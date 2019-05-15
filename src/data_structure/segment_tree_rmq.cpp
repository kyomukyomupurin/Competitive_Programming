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