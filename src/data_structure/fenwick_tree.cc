// Fenwick Tree(Binary Indexed Tree) (for point/range add query and range sum query)
// verified by 
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G

#include <vector>

template <class _Tp>
class FenwickTree {
 public:
  FenwickTree(const std::vector<_Tp>& data) : n_(data.size() + 1), data_(data) {
    initialize();
  }

  void add(int pos, _Tp value) {
    ++pos;
    while (pos < n_) {
      node_[pos] += value;
      pos += pos & -pos;
    }
  }

  // return sum of [0, i]
  _Tp get(int pos) {
    ++pos;
    _Tp sum = 0;
    while (pos > 0) {
      sum += node_[pos];
      pos -= pos & -pos;
    }
    return sum;
  }

  // return sum of [l, rihgt]
  _Tp get(int l, int r) { return get(r) - get(l - 1); }

  // for range add query
  class RAQ {
   public:
    RAQ(const std::vector<_Tp>& data)
        : n_(data.size()),
          ft1_(FenwickTree<_Tp>(data)),
          ft2_(FenwickTree<_Tp>(data)) {}

    // add value range [l, r)
    void add(int l, int r, _Tp value) {
      add(ft1_, l, r, value);
      add(ft2_, l, r, -value * static_cast<_Tp>(l - 1));
      add(ft2_, r, n_, value * static_cast<_Tp>(r - l));
    }

    // get sum of [0, i]
    _Tp get(int pos) {
      return ft1_.get(pos) * static_cast<_Tp>(pos) + ft2_.get(pos);
    }

    // get sum of [l, r]
    _Tp get(int l, int r) { return get(r) - get(l - 1); }

   private:
    int n_;
    FenwickTree<_Tp> ft1_;
    FenwickTree<_Tp> ft2_;
    void add(FenwickTree<_Tp>& ft, int l, int r, _Tp value) {
      ft.add(l, value);
      ft.add(r, -value);
    }
  };

 private:
  int n_;
  std::vector<_Tp> data_;
  std::vector<_Tp> node_;
  void initialize() {
    node_.assign(n_ + 1, 0);
    for (int i = 0; i < n_ - 1; ++i) add(i, data_[i]);
  }
};

// verification code
/*
void DSL_2_B() {
  int n, q;
  cin >> n >> q;
  FenwickTree<int> ft(vector<int>(n, 0));
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      ft.add(x - 1, y);
    } else {
      cout << ft.get(x - 1, y - 1) << '\n';
    }
  }
}
*/

/*
void DSL_2_G() {
  int n, q;
  cin >> n >> q;
  FenwickTree<int64>::RAQ ft(vector<int64>(n, 0));
  for (int i = 0; i < q; ++i) {
    int com;
    cin >> com;
    if (com == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      ft.add(s - 1, t, x);
    } else {
      int s, t;
      cin >> s >> t;
      cout << ft.get(s - 1, t - 1) << '\n';
    }
  }
}
*/