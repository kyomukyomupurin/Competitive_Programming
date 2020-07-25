// 2-Dimensional Cumulative Sum
// verified by
//     https://atcoder.jp/contests/abc106/tasks/abc106_d

#include <vector>
#include <cassert>

// snippet-begin
template <class T>
class CumulativeSum2D {
 public:
  CumulativeSum2D(const std::vector<vector<T>>& vec)
      : x_((int)vec.size()), y_((int)vec[0].size()), vec_(vec) {
    build();
  }

  // return sum of [sx, gx] * [sy, gy]
  T get(int sx, int sy, int gx, int gy) {
    assert(sx <= gx && sy <= gy);
    assert(0 <= sx && sx < x_ && 0 <= gx && gx < x_ && 0 <= sy && sy < y_ &&
           0 <= gy && gy < y_);
    return sum_[gx + 1][gy + 1] - sum_[gx + 1][sy] - sum_[sx][gy + 1] +
           sum_[sx][sy];
  }

 private:
  int x_;
  int y_;
  std::vector<vector<T>> vec_;
  std::vector<vector<T>> sum_;

  void build() {
    sum_.assign(x_ + 1, std::vector<T>(y_ + 1, 0));
    for (int i = 0; i < x_; ++i) {
      std::partial_sum(vec_[i].begin(), vec_[i].end(), sum_[i + 1].begin() + 1);
    }
    for (int i = 0; i < y_; ++i) {
      for (int j = 0; j < x_; ++j) {
        sum_[j + 1][i + 1] += sum_[j][i + 1];
      }
    }
  }
};
// snippet-end

// verification code
/*
void ABC106_D() {
  int n, m, query;
  cin >> n >> m >> query;
  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    ++board[l][r];
  }

  CumulativeSum2D<int> cs2(board);

  for (int i = 0; i < query; ++i) {
    int p, q;
    cin >> p >> q;
    --p;
    --q;
    cout << cs2.get(p, p, q, q) << '\n';
  }
}

*/