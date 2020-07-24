// Sparse table
// verified by
//     https://judge.yosupo.jp/problem/staticrmq

#include <algorithm>
#include <vector>

// snippet-begin
template <class T, class F>
class SaprseTable {
  // F must be idempotent function!
 public:
  SaprseTable(const std::vector<T>& data, F f)
      : n_((int)data.size()), lg_(32 - __builtin_clz(n_)), f_(f), data_(data) {
    build();
  }

  // return f_[l, r]
  T query(int l, int r) {
    assert(0 <= l && l <= r && r < n_);
    int lg = 32 - __builtin_clz(r - l + 1) - 1;
    return f_(tab_[lg][l], tab_[lg][r - (1 << lg) + 1]);
  }

 private:
  int n_;
  int lg_;
  F f_;
  std::vector<T> data_;
  std::vector<std::vector<T>> tab_;

  void build() {
    tab_.resize(lg_);
    tab_[0] = data_;
    for (int j = 1; j < lg_; ++j) {
      tab_[j].resize(n_ - (1 << j) + 1);
      for (int i = 0; i <= n_ - (1 << j); ++i) {
        tab_[j][i] = f_(tab_[j - 1][i], tab_[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
};
// snippet-end

// verification code
/*
void Static_RMQ() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& e : a) cin >> e;
  auto f = [](int x, int y) { return min(x, y); };
  SaprseTable st(a, f);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l, r - 1) << '\n';
  }
}
*/