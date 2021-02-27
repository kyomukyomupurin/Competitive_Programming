// Fenwick Tree(Binary Indexed Tree) (for point add query)

#include <vector>

// snippet-begin
template <class T>
class FenwickTree {
 public:
  FenwickTree(const std::vector<T>& data) : n_(int(data.size()) + 1) {
    node_.assign(n_, 0);
    for (int i = 0; i < n_ - 1; ++i) add(i, data[i]);
  }

  FenwickTree(int n) : n_(n + 1) { node_.assign(n_, 0); }

  void add(int pos, T val) {
    ++pos;
    while (pos < n_) {
      node_[pos] += val;
      pos += pos & -pos;
    }
  }

  // return sum of [l, r)
  T get(int l, int r) const {
    T sum = 0;
    while (l < r) {
      sum += node_[r];
      r -= r & -r;
    }
    while (r < l) {
      sum -= node_[l];
      l -= l & -l;
    }
    return sum;
  }

  // return the first k where sum of [0, k] >= val
  // use only when all element in data >= 0
  int lower_bound(T val) const {
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
  std::vector<T> node_;
};
// snippet-end