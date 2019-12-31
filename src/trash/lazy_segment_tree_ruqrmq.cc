/**
 *  Lazy Propagation Segment Tree(for range update query, range min/max query)
**/

#include <vector>

// not fot raange sum query!!
template <class Monoid, class Function>
class LazySegmentTree {
  using OperatorMonoid = Monoid;

 public:
  LazySegmentTree(const std::vector<Monoid>& data, Monoid identity_element,
                  Function function)
      : identity_element_(identity_element),
        operator_identity_element_(static_cast<OperatorMonoid>(-1)),
        data_(data),
        function_(function) {
    Build();
  }
  void RangeUpdate(int left, int right, OperatorMonoid new_value) {
    Thrust(left += n_);
    Thrust(right += n_ - 1);
    for (int l = left, r = right + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lazy_[l] = new_value, ++l;
      if (r & 1) --r, lazy_[r] = new_value;
    }
    Recalc(left);
    Recalc(right);
  }
  Monoid Query(int left, int right) {
    Thrust(left += n_);
    Thrust(right += n_ - 1);
    Monoid L = identity_element_, R = identity_element_;
    for (int l = left, r = right + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = function_(L, Reflect(l++));
      if (r & 1) R = function_(Reflect(--r), R);
    }
    return function_(L, R);
  }
  Monoid operator[](int position) { return Query(position, position + 1); }

 private:
  size_t n_;
  size_t height_;
  Monoid identity_element_;
  OperatorMonoid operator_identity_element_;
  std::vector<Monoid> data_;
  std::vector<Monoid> node_;
  std::vector<OperatorMonoid> lazy_;
  Function function_;

  void Build() {
    size_t SIZE = data_.size();
    n_ = 1;
    height_ = 0;
    while (n_ < SIZE) {
      n_ <<= 1;
      ++height_;
    }
    node_.assign(2 * n_, identity_element_);
    lazy_.assign(2 * n_, operator_identity_element_);
    for (size_t i = 0; i < SIZE; ++i) {
      node_[i + n_] = data_[i];
    }
    for (size_t i = n_ - 1; i > 0; --i) {
      node_[i] = function_(node_[2 * i], node_[2 * i + 1]);
    }
  }
  inline void Propagate(int k) {
    if (lazy_[k] != operator_identity_element_) {
      lazy_[2 * k] = lazy_[k];
      lazy_[2 * k + 1] = lazy_[k];
      node_[k] = Reflect(k);
      lazy_[k] = operator_identity_element_;
    }
  }

  inline Monoid Reflect(int k) {
    return lazy_[k] == operator_identity_element_ ? node_[k] : lazy_[k];
  }

  inline void Recalc(int k) {
    while (k >>= 1) node_[k] = function_(Reflect(2 * k), Reflect(2 * k + 1));
  }

  inline void Thrust(int k) {
    for (size_t i = height_; i > 0; i--) Propagate(k >> i);
  }
};

/*
void DSL_2_F() {
  int n, query;
  cin >> n >> query;
  auto f = [](int x, int y) { return min(x, y); };
  LazySegmentTree<int, decltype(f)> seg(vector<int>(n, 2147483647), 2147483647, f);
  for (int i = 0; i < query; ++i) {
    int com;
    cin >> com;
    if (com == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      seg.RangeUpdate(s, t + 1, x);
    } else {
      int s, t;
      cin >> s >> t;
      cout << seg.Query(s, t + 1) << '\n';
    }
  }
}
*/