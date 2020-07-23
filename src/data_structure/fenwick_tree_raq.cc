// Fenwick Tree(Binary Indexed Tree) (for point add query)
// verified by 
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G

#include <vector>

#include "./fenwick_tree.cc"

// snippet-begin
template <class _Tp>
class FenwickTreeRAQ {
 public:
  FenwickTreeRAQ(const std::vector<_Tp>& data)
      : n_(data.size()),
        ft1_(FenwickTree<_Tp>(data)),
        ft2_(FenwickTree<_Tp>(data)) {}

  // add val range [l, r)
  void add(int l, int r, _Tp val) {
    add(ft1_, l, r, val);
    add(ft2_, l, r, -val * (l - 1));
    add(ft2_, r, n_, val * (r - l));
  }

  // get sum of [0, i]
  _Tp get(int pos) { return ft1_.get(pos) * pos + ft2_.get(pos); }

  // get sum of [l, r]
  _Tp get(int l, int r) { return get(r) - get(l - 1); }

 private:
  int n_;
  FenwickTree<_Tp> ft1_;
  FenwickTree<_Tp> ft2_;
  void add(FenwickTree<_Tp>& ft, int l, int r, _Tp val) {
    ft.add(l, val);
    ft.add(r, -val);
  }
};
// snippet-end

/*
void DSL_2_G() {
  int n, q;
  cin >> n >> q;
  FenwickTreeRAQ<int64> ft(vector<int64>(n, 0));
  while (q--) {
    int com;
    cin >> com;
    if (com == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      ft.add(s - 1, t, x);
    } else {
      int s, t;
      cin >> s >> t;
      cout << ft.get(s - 1, t - 1) << '\n';
    }
  }
}
*/