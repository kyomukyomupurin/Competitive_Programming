// Segment Tree
// non-recursive version
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B

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

  // return function_[l, r)
  // if l >= r, return identity_element_
  M query(int l, int r) {
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

 private:
  int n_;
  M ie_;
  std::vector<M> data_;
  std::vector<M> node_;
  F f_;

  void build() {
    int SIZE = data_.size();
    n_ = 1;
    while (n_ < SIZE) {
      n_ <<= 1;
    }
    node_.assign(2 * n_, ie_);
    for (int i = 0; i < SIZE; ++i) {
      node_[i + n_] = data_[i];
    }
    for (int i = n_ - 1; i > 0; --i) {
      node_[i] = f_(node_[2 * i], node_[2 * i + 1]);
    }
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
      cout << seg.query(x, y + 1) << '\n';
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
      cout << seg.query(x, y + 1) << '\n';
    }
  }
}
*/