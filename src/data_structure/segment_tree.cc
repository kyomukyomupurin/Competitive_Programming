// Segment Tree

#include <vector>

// snippet-begin
template <class M, class F>
class SegmentTree {
 public:
  SegmentTree(const std::vector<M>& data, M ie, F f)
      : sz_(int(data.size())), ie_(ie), f_(f) {
    n_ = 1;
    while (n_ < sz_) n_ <<= 1;
    node_.assign(2 * n_, ie_);
    for (int i = 0; i < sz_; ++i) node_[i + n_] = data[i];
    for (int i = n_ - 1; i > 0; --i)
      node_[i] = f_(node_[2 * i], node_[2 * i + 1]);
  }

  SegmentTree(int n, M ie, F f) : sz_(n), ie_(ie), f_(f) {
    n_ = 1;
    while (n_ < sz_) n_ <<= 1;
    node_.assign(2 * n_, ie_);
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
  M get(int l, int r) const {
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
  M get_all() const { return node_[1]; }

  // return the maximum i that satisfies cond(i) == true, where i >= l
  // if there is no such i, return sz_
  template <class Condition>
  int max_right(int l, Condition cond) const {
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
  int min_left(int r, Condition cond) const {
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
  std::vector<M> node_;
  F f_;
};
// snippet-end