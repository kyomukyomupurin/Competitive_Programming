// Segment Tree
// non-recursive version
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B

#include <vector>
// snippet-begin
template <class Monoid, class Function>
class SegmentTree {
 public:
  SegmentTree(const std::vector<Monoid>& data, Monoid identity_element,
              Function function)
      : identity_element_(identity_element), data_(data), function_(function) {
    build();
  }

  void update(int pos, Monoid new_value) {
    assert(0 <= pos && pos < n_);
    pos += n_;
    node_[pos] = new_value;
    while (pos > 0) {
      pos >>= 1;
      node_[pos] = function_(node_[2 * pos], node_[2 * pos + 1]);
    }
  }

  // return function_[l, r)
  Monoid query(int l, int r) {
    assert(0 <= l && l < n_ && 0 <= r - 1 && r - 1 < n_);
    Monoid vl = identity_element_, vr = identity_element_;
    for (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = function_(vl, node_[l++]);
      if (r & 1) vr = function_(node_[--r], vr);
    }
    return function_(vl, vr);
  }

  Monoid operator[](int pos) const {
    assert(0 <= pos && pos < n_);
    return node_[n_ + pos];
  }

 private:
  int n_;
  Monoid identity_element_;
  std::vector<Monoid> data_;
  std::vector<Monoid> node_;
  Function function_;

  void build() {
    int SIZE = data_.size();
    n_ = 1;
    while (n_ < SIZE) {
      n_ <<= 1;
    }
    node_.assign(2 * n_, identity_element_);
    for (int i = 0; i < SIZE; ++i) {
      node_[i + n_] = data_[i];
    }
    for (int i = n_ - 1; i > 0; --i) {
      node_[i] = function_(node_[2 * i], node_[2 * i + 1]);
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