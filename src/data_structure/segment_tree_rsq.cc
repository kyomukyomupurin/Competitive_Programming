/**
 *  Segment Tree(Range Sum Query)
**/

#include <vector>

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
class SegmentTree {
 public:
  SegmentTree(const std::vector<int>& vec) : vec_(vec) {}
  void Initialize();
  void Update(int position, int value);
  int Query(int a, int b, int k, int l, int r);

 private:
  int n_;
  const std::vector<int> vec_;
  std::vector<int> data_;
};

void SegmentTree::Initialize() {
  int vsize = static_cast<int>(vec_.size());
  n_ = 1;
  while (n_ < vsize) {
    n_ <<= 1;
  }
  data_.assign(2 * n_ - 1, 0);
  for (int i = 0; i < vsize; ++i) {
    data_[i + n_ - 1] = vec_[i];
  }
  for (int i = n_ - 2; i >= 0; --i) {
    data_[i] = data_[2 * i + 1] + data_[2 * i + 2];
  }
}

void SegmentTree::Update(int position, int value) {
  position += n_ - 1;
  data_[position] += value;
  while (position > 0){
    position = (position - 1) / 2;
    data_[position] = data_[2 * position + 1] + data_[2 * position + 2];
  }
}

int SegmentTree::Query(int a, int b, int k = 0, int l = 0, int r = -1) {
  if (r < 0) r = n_;
  if (r <= a || b <= l) return 0;
  if (a <= l && r <= b) return data_[k];
  int vl = Query(a, b, 2 * k + 1, l, (l + r) / 2);
  int vr = Query(a, b, 2 * k + 2, (l + r) / 2, r);
  return vl + vr;
}