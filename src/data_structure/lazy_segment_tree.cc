// Lazy segment tree

#include <vector>

// snippet-begin
template <class M, class OM, class F1, class F2, class F3>
class LazySegmentTree {
 public:
  LazySegmentTree(const std::vector<M>& data, M ie, OM oie, F1 f1, F2 f2, F3 f3)
      : ie_(ie), oie_(oie), data_(data), f1_(f1), f2_(f2), f3_(f3) {
    build();
  }

  void modify(int l, int r, OM val) {
    if (l >= r) return;
    thrust(l += n_);
    thrust(r += n_ - 1);
    for (int cl = l, cr = r + 1; cl < cr; cl >>= 1, cr >>= 1) {
      if (cl & 1) lazy_[cl] = f3_(lazy_[cl], val), ++cl;
      if (cr & 1) --cr, lazy_[cr] = f3_(lazy_[cr], val);
    }
    recalc(l);
    recalc(r);
  }

  M get(int l, int r) {
    if (l >= r) return ie_;
    thrust(l + n_);
    thrust(r + n_ - 1);
    M vl = ie_, vr = ie_;
    for (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f1_(vl, apply(l++));
      if (r & 1) vr = f1_(apply(--r), vr);
    }
    return f1_(vl, vr);
  }

 private:
  int n_, h_;
  std::vector<M> data_;
  std::vector<M> node_;
  std::vector<OM> lazy_;
  M ie_;
  OM oie_;
  F1 f1_;
  F2 f2_;
  F3 f3_;

  void build() {
    int sz = data_.size();
    n_ = 1, h_ = 0;
    while (n_ < sz) n_ <<= 1, ++h_;
    node_.assign(2 * n_, ie_);
    lazy_.assign(2 * n_, oie_);
    for (int i = 0; i < sz; ++i) node_[i + n_] = data_[i];
    for (int i = n_ - 1; i > 0; --i) node_[i] = f1_(node_[2 * i], node_[2 * i + 1]);
  }

  inline void propagate(int pos) {
    if (lazy_[pos] != oie_) {
      lazy_[2 * pos] = f3_(lazy_[2 * pos], lazy_[pos]);
      lazy_[2 * pos + 1] = f3_(lazy_[2 * pos + 1], lazy_[pos]);
      node_[pos] = apply(pos);
      lazy_[pos] = oie_;
    }
  }

  inline M apply(int pos) {
    if (lazy_[pos] == oie_) {
      return node_[pos];
    } else {
      return f2_(node_[pos], lazy_[pos]);
    }
  }

  inline void recalc(int pos) {
    while (pos >>= 1) node_[pos] = f1_(apply(2 * pos), apply(2 * pos + 1));
  }

  inline void thrust(int pos) {
    for (int i = h_; i > 0; --i) propagate(pos >> i);
  }
};
// snippet-end

// verification code
/*
// RMQ and RUQ
void DSL_2_F() {
  int n, q; cin >> n >> q;
  auto f1 = [](int e1, int e2){ return min(e1, e2); };
  auto f2 = [](int e, int x){ return x; };
  auto f3 = [](int x1, int x2){ return x2; };
  constexpr int inf = 2147483647;
  vector<int> v(n, inf);
  LazySegmentTree<int, int, decltype(f1), decltype(f2), decltype(f3)> seg(v, inf, -1, f1, f2, f3);
  while (q--) {
    int op; cin >> op;
    if (op == 0) {
      int s, t, x; cin >> s >> t >> x;
      seg.modify(s, t + 1, x);
    } else {
      int s, t; cin >> s >> t;
      cout << seg.get(s, t + 1) << '\n';
    }
  }
}
*/
/*
// RSQ and RAQ
void DSL_2_G() {
  int n, q; cin >> n >> q;
  struct Node {
    int64 val, len;
  };
  auto f1 = [](Node e1, Node e2) { return (Node){e1.val + e2.val, e1.len + e2.len}; };
  auto f2 = [](Node e, int64 x){ return (Node){e.val + e.len * x, e.len}; };
  auto f3 = [](int64 x1, int64 x2){ return x1 + x2; };
  vector<Node> v(n, (Node){0, 1});
  LazySegmentTree<Node, int64, decltype(f1), decltype(f2), decltype(f3)> seg(v, (Node){0, 1}, 0, f1, f2, f3);
  while (q--) {
    int op; cin >> op;
    if (op == 0) {
      int s, t; int64 x; cin >> s >> t >> x;
      seg.modify(s - 1, t, x);
    } else {
      int s, t; cin >> s >> t;
      cout << seg.get(s - 1, t).val << '\n';
    }
  }
}
*/
/*
// RMQ and RAQ
void DSL_2_H() {
  int n, q; cin >> n >> q;
  auto f1 = [](int e1, int e2){ return min(e1, e2); };
  auto f2 = [](int e, int x){ return e + x; };
  auto f3 = [](int x1, int x2){ return x1 + x2; };
  constexpr int inf = (int)1e9;
  vector<int> v(n, 0);
  LazySegmentTree<int, int, decltype(f1), decltype(f2), decltype(f3)> seg(v, inf, 0, f1, f2, f3);
  while (q--) {
    int op; cin >> op;
    if (op == 0) {
      int s, t, x; cin >> s >> t >> x;
      seg.modify(s, t + 1, x);
    } else {
      int s, t; cin >> s >> t;
      cout << seg.get(s, t + 1) << '\n';
    }
  }
}
*/
/*
// RSQ and RUQ
void DSL_2_I() {
  int n, q; cin >> n >> q;
  struct Node {
    int64 val, len;
  };
  auto f1 = [](Node e1, Node e2) { return (Node){e1.val + e2.val, e1.len + e2.len}; };
  auto f2 = [](Node e, int64 x){ return (Node){e.len * x, e.len}; };
  auto f3 = [](int64 x1, int64 x2){ return x2; };
  vector<Node> v(n, (Node){0, 1});
  LazySegmentTree<Node, int64, decltype(f1), decltype(f2), decltype(f3)> seg(v, (Node){0, 1}, -(int64)1e18, f1, f2, f3);
  while (q--) {
    int op; cin >> op;
    if (op == 0) {
      int s, t; int64 x; cin >> s >> t >> x;
      seg.modify(s, t + 1, x);
    } else {
      int s, t; cin >> s >> t;
      cout << seg.get(s, t + 1).val << '\n';
    }
  }
}
*/