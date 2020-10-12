// Segment Tree
// non-recursive version
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
//     https://atcoder.jp/contests/practice2/tasks/practice2_j

#include <vector>

// snippet-begin
template <class M, class F>
class SegmentTree {
 public:
  SegmentTree(const std::vector<M>& data, M ie, F f)
      : ie_(ie), data_(data), f_(f) {
    build();
  }

  void update(int pos, M val) {
    assert(0 <= pos && pos < n_);
    pos += n_;
    node_[pos] = val;
    while (pos > 0) {
      pos >>= 1;
      node_[pos] = f_(node_[2 * pos], node_[2 * pos + 1]);
    }
  }

  // return f_[l, r)
  // if l >= r, return ie_
  M get(int l, int r) {
    assert(0 <= l && l < n_ && 0 <= r && r < n_ + 1);
    M vl = ie_, vr = ie_;
    for (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f_(vl, node_[l++]);
      if (r & 1) vr = f_(node_[--r], vr);
    }
    return f_(vl, vr);
  }

  M operator[](int pos) const {
    assert(0 <= pos && pos < n_);
    return node_[n_ + pos];
  }

  // return f_[0, sz_)
  M get_all() { return node_[1]; }

  // return the maximum i that satisfies cond(i) == true, where i >= l
  // if there is no such i, return sz_
  template <class Condition>
  int max_right(int l, Condition cond) {
    assert(0 <= l && l <= sz_);
    assert(cond(ie_));
    if (l == sz_) return sz_;
    l += n_;
    M sm = ie_;

    do {
      while (~l & 1) l >>= 1;
      if (!cond(f_(sm, node_[l]))) {
        while (l < n_) {
          l <<= 1;
          if (cond(f_(sm, node_[l]))) {
            sm = f_(sm, node_[l]);
            ++l;
          }
        }
        return l - n_;
      }
      sm = f_(sm, node_[l]);
      ++l;
    } while ((l & -l) != l);

    return sz_;
  }

  // return the minimum i that satisfies cond(i) == true, where i <= r
  // if there is no such i, return 0
  // NOT VERIFIED!!
  template <class Condition>
  int min_left(int r, Condition cond) {
    assert(0 <= r && r <= sz_);
    assert(cond(ie_));
    if (r == 0) return 0;
    r += n_;
    M sm = ie_;

    do {
      --r;
      while (r > 1 && (r & 1)) r >>= 1;
      if (!cond(f_(node_[r], sm))) {
        while (r < n_) {
          r = (2 * r + 1);
          if (cond(f_(node_[r], sm))) {
            sm = f_(node_[r], sm);
            --r;
          }
        }
        return r + 1 - n_;
      }
      sm = f_(node_[r], sm);
    } while ((r & -r) != r);

    return 0;
  }

 private:
  int n_;
  int sz_;
  M ie_;
  std::vector<M> data_;
  std::vector<M> node_;
  F f_;

  void build() {
    sz_ = data_.size();
    n_ = 1;
    while (n_ < sz_) n_ <<= 1;
    node_.assign(2 * n_, ie_);
    for (int i = 0; i < sz_; ++i) node_[i + n_] = data_[i];
    for (int i = n_ - 1; i > 0; --i) node_[i] = f_(node_[2 * i], node_[2 * i + 1]);
  }
};
// snippet-end

// verification code
/*
void DSL_2_A() {
  int n, q;
  cin >> n >> q;
  auto f = [](int x, int y) { return min(x, y); };
  constexpr int INF = 2147483647;
  SegmentTree<int, decltype(f)> seg(vector<int>(n, INF), INF, f);
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      seg.update(x, y);
    } else {
      cout << seg.get(x, y + 1) << '\n';
    }
  }
}
*/

/*
void DSL_2_B() {
  int n, q;
  cin >> n >> q;
  auto f = [](int x, int y) { return x + y; };
  SegmentTree<int, decltype(f)> seg(vector<int>(n, 0), 0, f);
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      --x;
      seg.update(x, seg[x] + y);
    } else {
      --x;
      --y;
      cout << seg.get(x, y + 1) << '\n';
    }
  }
}
*/

/*
void practice2_J() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& e : a) cin >> e;

  int ie = -1;
  auto f = [](int x, int y) { return max(x, y); };
  SegmentTree seg(a, ie, f);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, v;
      cin >> x >> v;
      --x;
      seg.update(x, v);
    } else if (t == 2) {
      int l, r;
      cin >> l >> r;
      cout << seg.get(l - 1, r) << '\n';
    } else {
      int x, v;
      cin >> x >> v;
      auto cond = [&](int val) -> bool { return val < v; };
      cout << seg.max_right(x - 1, cond) + 1 << '\n';
    }
  }
} 
*/