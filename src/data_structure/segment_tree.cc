//
// Segment Tree
// non-recursive version
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B

#include <vector>

template <class Monoid, class Function>
class SegmentTree {
 public:
  SegmentTree(const std::vector<Monoid>& data, Monoid identity_element,
              Function function)
      : identity_element_(identity_element), data_(data), function_(function) {
    Build();
  }

  void Update(size_t position, Monoid new_value) {
    position += n_;
    node_[position] = new_value;
    while (position > 0) {
      position >>= 1;
      node_[position] = function_(node_[2 * position], node_[2 * position + 1]);
    }
  }

  // return Query[left, right)
  Monoid Query(int left, int right) {
    Monoid vl = identity_element_, vr = identity_element_;
    for (left += n_, right += n_; left < right; left >>= 1, right >>= 1) {
      if (left & 1) vl = function_(vl, node_[left++]);
      if (right & 1) vr = function_(node_[--right], vr);
    }
    return function_(vl, vr);
  }

  Monoid operator[](size_t position) const { return node_[n_ + position]; }

 private:
  size_t n_;
  Monoid identity_element_;
  std::vector<Monoid> data_;
  std::vector<Monoid> node_;
  Function function_;

  void Build() {
    size_t SIZE = data_.size();
    n_ = 1;
    while (n_ < SIZE) {
      n_ <<= 1;
    }
    node_.assign(2 * n_, identity_element_);
    for (size_t i = 0; i < SIZE; ++i) {
      node_[i + n_] = data_[i];
    }
    for (size_t i = n_ - 1; i > 0; --i) {
      node_[i] = function_(node_[2 * i], node_[2 * i + 1]);
    }
  }
};

// verification code
/*
void DSL_2_A() {
  int n, q; cin >> n >> q;
  auto f = [](int x, int y){ return min(x, y); };
  SegmentTree<int, decltype(f)> seg(vector<int>(n, 2147483647), 2147483647, f);
  for (int i = 0; i < q; ++i) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) {
      seg.Update(x, y);
    } else {
      cout << seg.Query(x, y + 1) << '\n';
    }
  }
}
*/

/*
void DSL_2_B() {
  int n, q; cin >> n >> q;
  auto f = [](int x, int y){ return x + y; };
  SegmentTree<int, decltype(f)> seg(vector<int>(n, 0), 0, f);
  for (int i = 0; i < q; ++i) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) {
      seg.Update(x, seg[x] + y);
    } else {
      cout << seg.Query(x, y + 1) << '\n';
    }
  }
}
*/