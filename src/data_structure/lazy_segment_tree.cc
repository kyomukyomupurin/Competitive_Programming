// Lazy segment tree
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I
//     https://judge.yosupo.jp/problem/range_affine_range_sum

#include <vector>

// snippet-begin
template <class M, class OM, class F1, class F2, class F3>
class LazySegmentTree {
 public:
  LazySegmentTree(const std::vector<M>& data, M ie, OM oie, F1 f1, F2 f2, F3 f3)
      : ie_(ie), oie_(oie), f1_(f1), f2_(f2), f3_(f3) {
    int sz = data.size();
    n_ = 1, h_ = 0;
    while (n_ < sz) n_ <<= 1, ++h_;
    node_.assign(2 * n_, ie_);
    lazy_.assign(2 * n_, oie_);
    for (int i = 0; i < sz; ++i) node_[i + n_] = data[i];
    for (int i = n_ - 1; i > 0; --i) node_[i] = f1_(node_[2 * i], node_[2 * i + 1]);
  }

  LazySegmentTree(int n, M ie, OM oie, F1 f1, F2 f2, F3 f3)
      : ie_(ie), oie_(oie), f1_(f1), f2_(f2), f3_(f3) {
    n_ = 1, h_ = 0;
    while (n_ < n) n_ <<= 1, ++h_;
    node_.assign(2 * n_, ie_);
    lazy_.assign(2 * n_, oie_);
    for (int i = n_ - 1; i > 0; --i) node_[i] = f1_(node_[2 * i], node_[2 * i + 1]);
  }

  // modify data_[l, r) -> f3_(data_[l], val), ... , f3_(data[r - 1], val)
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

  // return f1_[l, r)
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
  std::vector<M> node_;
  std::vector<OM> lazy_;
  M ie_;
  OM oie_;
  F1 f1_;
  F2 f2_;
  F3 f3_;

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
  auto f = [](int e1, int e2){ return min(e1, e2); };
  auto fg = [](int e, int x){ return x; };
  auto g = [](int x1, int x2){ return x2; };
  constexpr int inf = 2147483647;
  LazySegmentTree seg(n, inf, -1, f, fg, g);
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
  auto f = [](Node e1, Node e2) { return (Node){e1.val + e2.val, e1.len + e2.len}; };
  auto fg = [](Node e, int64 x){ return (Node){e.val + e.len * x, e.len}; };
  auto g = [](int64 x1, int64 x2){ return x1 + x2; };
  LazySegmentTree seg(n, (Node){0, 1}, 0, f, fg, g);
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
  auto f = [](int e1, int e2){ return min(e1, e2); };
  auto fg = [](int e, int x){ return e + x; };
  auto g = [](int x1, int x2){ return x1 + x2; };
  constexpr int inf = (int)1e9;
  vector<int> v(n, 0);
  LazySegmentTree seg(v, inf, 0, f, fg, g);
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
  auto f = [](Node e1, Node e2) { return (Node){e1.val + e2.val, e1.len + e2.len}; };
  auto fg = [](Node e, int64 x){ return (Node){e.len * x, e.len}; };
  auto g = [](int64 x1, int64 x2){ return x2; };
  LazySegmentTree seg(n, (Node){0, 1}, -int64(1e18), f, fg, g);
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
/*
void Range_Affine_Range_Sum() {
  int n, q;
  cin >> n >> q;
  vector<int64> a(n);
  for (int64& e : a) cin >> e;

  struct Node {
    int64 val, len;

    Node(int64 val_, int64 len_) : val(val_), len(len_) {}
  };

  struct Op {
    int64 op1, op2;

    Op(int64 op1_, int64 op2_) : op1(op1_), op2(op2_) {}

    bool operator==(const Op& rhs) const {
      return rhs.op1 == op1 && rhs.op2 == op2;
    };

    bool operator!=(const Op& rhs) const {
      return rhs.op1 != op1 || rhs.op2 != op2;
    };
  };

  constexpr int mod = 998244353;

  auto f = [](Node e1, Node e2) -> Node {
    return (Node){(e1.val + e2.val) % mod, e1.len + e2.len};
  };
  auto fg = [](Node e, Op x) -> Node {
    return (Node){(e.val * x.op1 + e.len * x.op2) % mod, e.len};
  };
  auto g = [](Op x1, Op x2) -> Op {
    return (Op){(x1.op1 * x2.op1) % mod, (x1.op2 * x2.op1 + x2.op2) % mod};
  };

  Node ie = {0, 1};
  Op oie = {1, 0};
  vector<Node> v;
  for (int i = 0; i < n; ++i) v.emplace_back(a[i], 1);
  LazySegmentTree seg(n, ie, oie, f, fg, g);

  while (q--) {
    int com;
    cin >> com;
    if (com == 0) {
      int l, r, b, c;
      cin >> l >> r >> b >> c;
      seg.modify(l, r, (Op){b, c});
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.get(l, r).val << '\n';
    }
  }
}
*/