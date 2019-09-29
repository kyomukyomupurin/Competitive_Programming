/**
 *  Segment Tree
**/

#include <functional>
#include <vector>

// non-recursive version
// verified by
// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
template <typename T>
class SegmentTree {
 public:
  SegmentTree(const std::vector<T>& vec, const T& initial_value,
              std::function<T(T, T)> operation)
      : initial_value_(initial_value), vec_(vec), operation_(operation) {
    Initialize();
  }
  void Update(int position, T new_value) {
    position += n_;
    data_[position] = new_value;
    while (position > 0) {
      position >>= 1;
      data_[position] =
          operation_(data_[2 * position], data_[2 * position + 1]);
    }
  }
  // return Query[a, b)
  T Query(int a, int b) {
    T vl = initial_value_, vr = initial_value_;
    for (a += n_, b += n_; a < b; a >>= 1, b >>= 1) {
      if (a & 1) vl = operation_(vl, data_[a++]);
      if (b & 1) vr = operation_(data_[--b], vr);
    }
    return operation_(vl, vr);
  }

 private:
  int n_;
  const T initial_value_;
  const std::vector<T> vec_;
  std::vector<T> data_;
  std::function<T(T, T)> operation_;
  void Initialize() {
    int vsize = static_cast<int>(vec_.size());
    n_ = 1;
    while (n_ < vsize) {
      n_ <<= 1;
    }
    data_.assign(2 * n_, initial_value_);
    for (int i = 0; i < vsize; ++i) {
      data_[i + n_] = vec_[i];
    }
    for (int i = n_ - 1; i > 0; --i) {
      data_[i] = operation_(data_[2 * i], data_[2 * i + 1]);
    }
  }
};

/*
void DSL_2_A() {
  int n, q; cin >> n >> q;
  SegmentTree<int> seg(vector<int>(n, 2147483647), 2147483647, [](int x, int y){ return min(x, y); });
  rep(i, q) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) {
      seg.Update(x, y);
    } else {
      cout << seg.Query(x, y + 1) << '\n';
    }
  }  
}
*/