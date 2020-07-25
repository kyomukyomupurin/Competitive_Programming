// Fenwick Tree(Binary Indexed Tree) (for point add query)
// verified by 
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B

#include <vector>

// snippet-begin
template <class T>
class FenwickTree {
 public:
  FenwickTree(const std::vector<T>& data) : n_(data.size() + 1), data_(data) {
    init();
  }

  void add(int pos, T val) {
    ++pos;
    while (pos < n_) {
      node_[pos] += val;
      pos += pos & -pos;
    }
  }

  // return sum of [0, i]
  T get(int pos) {
    ++pos;
    T sum = 0;
    while (pos > 0) {
      sum += node_[pos];
      pos -= pos & -pos;
    }
    return sum;
  }

  // return sum of [l, rihgt]
  T get(int l, int r) { return get(r) - get(l - 1); }

  // return the first k where sum of [0, k] >= val
  // use only when all element in data >= 0
  int lower_bound(T val) {
    if (val <= 0) return 0;
    int pos = 0;
    int k = 1;
    while (k < n_ - 1) k <<= 1;
    while (k > 0) {
      if (pos + k <= n_ - 1 && node_[pos + k] < val) {
        val -= node_[pos + k];
        pos += k;
      }
      k >>= 1;
    }
    return pos;
  }

 private:
  int n_;
  std::vector<T> data_;
  std::vector<T> node_;
  void init() {
    node_.assign(n_ + 1, 0);
    for (int i = 0; i < n_ - 1; ++i) add(i, data_[i]);
  }
};
// snippet-end

// verification code
/*
void DSL_2_B() {
  int n, q;
  cin >> n >> q;
  FenwickTree<int> ft(vector<int>(n, 0));
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      ft.add(x - 1, y);
    } else {
      cout << ft.get(x - 1, y - 1) << '\n';
    }
  }
}
*/