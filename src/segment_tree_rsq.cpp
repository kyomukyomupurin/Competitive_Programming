/**
 *  SegmentTree(Range Sum Query)
**/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct SegmentTree{
  private:
    int n;
    vector<int> dat;
  public:
    SegmentTree(vector<int> v) {
      int SIZE = v.size();
      n = 1;
      while (n < SIZE) n <<= 1;
      dat.resize(2 * n - 1, 0);
    }

    void add(int pos, int val){
      pos += n - 1;
      dat[pos] += val;
      while (pos > 0){
        pos = (pos - 1) / 2;
        dat[pos] = dat[2 * pos + 1] + dat[2 * pos + 2];
      }
    }

    int query(int a, int b, int k = 0, int l = 0, int r = -1){
      if (r < 0) r = n;
      if (r <= a || b <= l) return 0;
      if (a <= l && r <= b) return dat[k];
      int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
      int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
      return vl + vr;
    }
};