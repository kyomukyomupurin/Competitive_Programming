// Fenwick Tree(Binary Indexed Tree) (for range add query)

#include <vector>

#include "./fenwick_tree.cc"

// snippet-begin
template <class T>
class FenwickTreeRAQ {
 public:
  FenwickTreeRAQ(const std::vector<T>& data)
      : n_(int(data.size())),
        ft1_(FenwickTree<T>(data)),
        ft2_(FenwickTree<T>(data)) {}

  FenwickTreeRAQ(int n)
      : n_(n), ft1_(FenwickTree<T>(n)), ft2_(FenwickTree<T>(n)) {}

  // add val range [l, r)
  void add(int l, int r, T val) {
    add(ft1_, l, r, val);
    add(ft2_, l, r, -val * (l - 1));
    add(ft2_, r, n_, val * (r - l));
  }

  // get sum of [0, pos]
  T get(int pos) const {
    return ft1_.get(0, pos + 1) * pos + ft2_.get(0, pos + 1);
  }

  // get sum of [l, r]
  T get(int l, int r) const { return get(r) - get(l - 1); }

 private:
  int n_;
  FenwickTree<T> ft1_;
  FenwickTree<T> ft2_;

  void add(FenwickTree<T>& ft, int l, int r, T val) {
    ft.add(l, val);
    ft.add(r, -val);
  }
};
// snippet-end