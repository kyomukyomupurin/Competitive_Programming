// 2-Dimensional Cumulative Sum
// verified by
//     https://atcoder.jp/contests/abc106/tasks/abc106_d

#include <vector>
#include <cassert>

template <class _Tp>
class CumulativeSum2D {
 public:
  CumulativeSum2D(const std::vector<vector<_Tp>>& vec)
      : x_(vec.size()), y_(vec[0].size()), vec_(vec) {
    build();
  }

  // return sum of [sx, gx] * [sy, gy]
  _Tp get(int sx, int sy, int gx, int gy) {
    assert(sx <= gx && sy <= gy);
    assert(0 <= sx && sx < x_ && 0 <= gx && gx < x_ && 0 <= sy && sy < y_ &&
           0 <= gy && gy < y_);
    return sum_[gx + 1][gy + 1] - sum_[gx + 1][sy] - sum_[sx][gy + 1] +
           sum_[sx][sy];
  }

 private:
  int x_;
  int y_;
  std::vector<vector<_Tp>> vec_;
  std::vector<vector<_Tp>> sum_;

  void build() {
    sum_.assign(x_ + 1, vector<_Tp>(y_ + 1, static_cast<_Tp>(0)));
    for (int i = 0; i < x_; ++i) {
      for (int j = 0; j < y_; ++j) {
        sum_[i + 1][j + 1] = sum_[i + 1][j] + vec_[i][j];
      }
    }
    for (int i = 0; i < y_; ++i) {
      for (int j = 0; j < x_; ++j) {
        sum_[j + 1][i + 1] += sum_[j][i + 1];
      }
    }
  }
};

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