// Fenwick Tree(Binary Indexed Tree) (for point/range add query and range sum query)
// verified by 
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G

#include <vector>

template <class T>
class FenwickTree {
 public:
  FenwickTree(const std::vector<T>& data) : n_(data.size() + 1), data_(data) {
    Initialize();
  }

  void Add(size_t pos, T value) {
    ++pos;
    while (pos < n_) {
      node_[pos] += value;
      pos += pos & -pos;
    }
  }

  // return sum of [0, i]
  T GetSum(size_t pos) {
    ++pos;
    T sum = 0;
    while (pos > 0) {
      sum += node_[pos];
      pos -= pos & -pos;
    }
    return sum;
  }

  // return sum of [left, right]
  T GetRangeSum(int left, int right) {
    return GetSum(right) - GetSum(left - 1);
  }

  // for range add query
  class RAQ {
   public:
    RAQ(const std::vector<T>& data)
        : n_(data.size()),
          ft1_(FenwickTree<T>(data)),
          ft2_(FenwickTree<T>(data)) {}

    // add value range [left, right)
    void RangeAdd(int left, int right, T value) {
      Add(ft1_, left, right, value);
      Add(ft2_, left, right, -value * static_cast<T>(left - 1));
      Add(ft2_, right, n_, value * static_cast<T>(right - left));
    }

    // get sum of [0, i]
    T GetSum(size_t pos) {
      return ft1_.GetSum(pos) * static_cast<T>(pos) + ft2_.GetSum(pos);
    }

    // get sum of [left, right]
    T GetRangeSum(int left, int right) {
      return GetSum(right) - GetSum(left - 1);
    }

   private:
    size_t n_;
    FenwickTree<T> ft1_;
    FenwickTree<T> ft2_;
    void Add(FenwickTree<T>& ft, int left, int right, T value) {
      ft.Add(left, value);
      ft.Add(right, -value);
    }
  };

 private:
  size_t n_;
  std::vector<T> data_;
  std::vector<T> node_;
  void Initialize() {
    node_.assign(n_ + 1, 0);
    for (size_t i = 0; i < n_ - 1; ++i) Add(i, data_[i]);
  }
};

// verification code
/*
void DSL_2_B() {
  int n, q; cin >> n >> q;
  FenwickTree<int> ft(vector<int>(n, 0));
  for (int i = 0; i < q; ++i) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) {
      ft.Add(x - 1, y);
    } else {
      cout << ft.GetRangeSum(x - 1, y - 1) << '\n';
    }
  }
}
*/

/*
void DSL_2_G() {
  int n, q; cin >> n >> q;
  FenwickTree<int64>::RAQ ft(vector<int64>(n, 0));
  for (int i = 0; i < q; ++i) {
    int com; cin >> com;
    if (com == 0) {
      int s, t, x; cin >> s >> t >> x;
      ft.RangeAdd(s - 1, t, x);
    } else {
      int s, t; cin >> s >> t;
      cout << ft.GetRangeSum(s - 1, t - 1) << '\n';
    }
  }
}
*/