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
