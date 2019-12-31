/**
 *  Fenwick Tree(binary indexed tree) (for point add query and range sum query)
**/

#include <vector>

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
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
  // return sum of [left, rihgt]
  T GetRangeSum(int left, int right) {
    return GetSum(right) - GetSum(left - 1);
  }

 private:
  size_t n_;
  std::vector<T> data_;
  std::vector<T> node_;
  void Initialize() {
    node_.assign(n_ + 1, 0);
    for (size_t i = 0; i < n_ - 1; ++i) Add(i, data_[i]);
  }
};

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