/**
 *  SegmentTree(Range Minimum Query)
**/

#include <vector>

const int INF = (1LL<<31) - 1;

struct SegmentTree{
  private:
    int n;
    std::vector<int> dat;
  public:
    SegmentTree(std::vector<int> v) {
      int SIZE = v.size();
      n = 1;
      while (n < SIZE) n <<= 1;
      dat.resize(2 * n - 1, INF);
      for (int i = 0; i < SIZE; ++i) dat[i + n - 1] = v[i];
      for (int i = n - 2; i >= 0; --i) dat[i] = std::min(dat[2 * i + 1], dat[2 * i + 2]);
    }

    void update(int pos, int val){
      pos += n - 1;
      dat[pos] = val;
      while (pos > 0){
        pos = (pos - 1) / 2;
        dat[pos] = std::min(dat[2 * pos + 1], dat[2 * pos + 2]);
      }
    }

    int query(int a, int b, int k = 0, int l = 0, int r = -1){
      if (r < 0) r = n;
      if (r <= a || b <= l) return INF;
      if (a <= l && r <= b) return dat[k];
      int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
      int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
      return std::min(vl, vr);
    }
};

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
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
  data_.assign(2 * n_ - 1, INF);
  for (int i = 0; i < vsize; ++i) {
    data_[i + n_ - 1] = vec_[i];
  }
  for (int i = n_ - 2; i >= 0; --i) {
    data_[i] = std::min(data_[2 * i + 1], data_[2 * i + 2]);
  }
}

void SegmentTree::Update(int position, int value) {
  position += n_ - 1;
  data_[position] = value;
  while (position > 0){
    position = (position - 1) / 2;
    data_[position] = std::min(data_[2 * position + 1], data_[2 * position + 2]);
  }
}

int SegmentTree::Query(int a, int b, int k = 0, int l = 0, int r = -1) {
  if (r < 0) r = n_;
  if (r <= a || b <= l) return INF;
  if (a <= l && r <= b) return data_[k];
  int vl = Query(a, b, 2 * k + 1, l, (l + r) / 2);
  int vr = Query(a, b, 2 * k + 2, (l + r) / 2, r);
  return std::min(vl, vr);
}