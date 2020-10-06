// Disjoint Sparse table
// verified by
//     https://judge.yosupo.jp/problem/staticrmq
//     https://judge.yosupo.jp/problem/static_range_sum

#include <algorithm>
#include <vector>

// snippet-begin
template <class T, class F>
class DisjointSparseTable {
 public:
  DisjointSparseTable(const std::vector<T>& data, F f)
      : n_((int)data.size()), f_(f), data_(data) {
    build();
  }

  // reutrn f_[l, r)
  T get(int l, int r) {
    if (l >= --r) return tab_[0][l];
    int p = lookup_[l ^ r];
    return f_(tab_[p][l], tab_[p][r]);
  }

 private:
  int n_;
  F f_;
  std::vector<T> data_;
  std::vector<std::vector<T>> tab_;
  std::vector<int> lookup_;

  void build() {
    int sz = 0;
    while ((1 << sz) <= n_) ++sz;
    tab_.assign(sz, std::vector<T>(n_, T{}));
    for (int i = 0; i < n_; ++i) tab_[0][i] = data_[i];
    for (int i = 1; i < sz; ++i) {
      int shift = 1 << i;
      for (int j = 0; j < n_; j += shift << 1) {
        int t = std::min(j + shift, n_);
        tab_[i][t - 1] = data_[t - 1];
        for (int k = t - 2; k >= j; k--)
          tab_[i][k] = f_(data_[k], tab_[i][k + 1]);
        if (n_ <= t) break;
        tab_[i][t] = data_[t];
        int r = std::min(t + shift, n_);
        for (int k = t + 1; k < r; k++)
          tab_[i][k] = f_(tab_[i][k - 1], data_[k]);
      }
    }
    lookup_.resize(1 << sz);
    for (int i = 2; i < (int)lookup_.size(); ++i) {
      lookup_[i] = lookup_[i >> 1] + 1;
    }
  }
};
// snippet-end
