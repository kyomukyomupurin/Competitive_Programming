/**
 *  Segment Tree
**/

#include <functional>
#include <vector>

// non-recursive version
// verified by
// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
template <typename T>
class SegmentTree {
 public:
  SegmentTree(const std::vector<T>& vec, T initial_value,
              std::function<T(T, T)> operation)
      : initial_value_(initial_value), vec_(vec), operation_(operation) {
    Initialize();
  }
  void Update(int position, T new_value);
  T Query(int a, int b);
  T operator[](int position) const;

 private:
  int n_;
  T initial_value_;
  const std::vector<T> vec_;
  std::vector<T> data_;
  std::function<T(T, T)> operation_;
  void Initialize();
};

template <typename T>
void SegmentTree<T>::Initialize() {
  int vsize = vec_.size();
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

template <typename T>
void SegmentTree<T>::Update(int position, T new_value) {
  position += n_;
  data_[position] = new_value;
  while (position > 0) {
    position >>= 1;
    data_[position] = operation_(data_[2 * position], data_[2 * position + 1]);
  }
}

// return Query[a, b)
template <typename T>
T SegmentTree<T>::Query(int a, int b) {
  T vl = initial_value_, vr = initial_value_;
  for (a += n_, b += n_; a < b; a >>= 1, b >>= 1) {
    if (a & 1) vl = operation_(vl, data_[a++]);
    if (b & 1) vr = operation_(data_[--b], vr);
  }
  return operation_(vl, vr);
}

template <typename T>
T SegmentTree<T>::operator[](int position) const {
  return data_[n_ + position];
}

/*
void DSL_2_A() {
  int n, q; cin >> n >> q;
  SegmentTree<int> seg(vector<int>(n, 2147483647), 2147483647, [](int x, int y){ return min(x, y); });
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
  SegmentTree<int> seg(vector<int>(n, 0), 0, [](int x, int y){ return x + y; });
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