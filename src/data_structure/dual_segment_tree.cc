// Dual segment tree
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E

#include <vector>

// snippet-begin
template <class OM, class F>
class DualSegmentTree {
 public:
  DualSegmentTree(const std::vector<OM>& data, OM oie, F f)
      : data_(data), oie_(oie), f_(f) {
    build();
  }

  // modify data_[l, r) -> f_(data_[l], val), ... , f_(data[r - 1], val)
  void modify(int l, int r, OM val) {
    thrust(l + n_);
    thrust(r + n_ - 1);
    for (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lazy_[l] = f_(lazy_[l], val), ++l;
      if (r & 1) --r, lazy_[r] = f_(lazy_[r], val);
    }
  }

  OM operator[](int pos) {
    pos += n_;
    thrust(pos);
    return f_(data_[pos - n_], lazy_[pos]);
  }

 private:
  int n_, h_;
  std::vector<OM> data_;
  std::vector<OM> lazy_;
  F f_;
  OM oie_;

  void build() {
    int sz = data_.size();
    n_ = 1;
    h_ = 0;
    while (n_ < sz) n_ <<= 1, ++h_;
    lazy_.assign(2 * n_, oie_);
  }

  inline void propagate(int pos) {
    if (lazy_[pos] != oie_) {
      lazy_[2 * pos + 0] = f_(lazy_[2 * pos + 0], lazy_[pos]);
      lazy_[2 * pos + 1] = f_(lazy_[2 * pos + 1], lazy_[pos]);
      lazy_[pos] = oie_;
    }
  }

  inline void thrust(int pos) {
    for (int i = h_; i > 0; --i) propagate(pos >> i);
  }
};
// snippet-end

// verification code
/*
void DSL_2_D() {
  int n, q;
  cin >> n >> q;
  constexpr int inf = 2147483647;
  auto f = [](int e, int x) { return x; };
  DualSegmentTree<int, decltype(f)> seg(vector<int>(n, inf), inf, f);
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      seg.modify(s, t + 1, x);
    } else {
      int pos;
      cin >> pos;
      cout << seg[pos] << '\n';
    }
  }
}
*/

/*
void DSL_2_E() {
  int n, q;
  cin >> n >> q;
  auto f = [](int e, int x) { return e + x; };
  DualSegmentTree<int, decltype(f)> seg(vector<int>(n, 0), 0, f);
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      --s;
      --t;
      seg.modify(s, t + 1, x);
    } else {
      int pos;
      cin >> pos;
      --pos;
      cout << seg[pos] << '\n';
    }
  }
}
*/