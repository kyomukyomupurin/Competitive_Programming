//
// 2-Dimensional Cumulative Sum
// verified by
//     https://atcoder.jp/contests/abc106/tasks/abc106_d

#include <vector>
#include <cassert>

template <class T>
class CumulativeSum2D {
 public:
  CumulativeSum2D(const std::vector<vector<T>>& vec)
      : vec_(vec), height_(vec.size()), width_(vec[0].size()) {
    Build();
  }

  // return sum of [sx, gx] * [sy, gy]
  T Get(int sx, int sy, int gx, int gy) {
    assert(sx <= gx && sy <= gy);
    assert(0 <= sx && sx < height_ && 0 <= gx && gx < height_ && 0 <= sy &&
          sy < width_ && 0 <= gy && gy < width_);
    return sum_[gx + 1][gy + 1] - sum_[gx + 1][sy] - sum_[sx][gy + 1] +
          sum_[sx][sy];
  }

 private:
  size_t height_;
  size_t width_;
  std::vector<vector<T>> vec_;
  std::vector<vector<T>> sum_;

  void Build() {
    sum_.assign(height_ + 1, vector<T>(width_ + 1, static_cast<T>(0)));
    for (size_t i = 0; i < height_; ++i) {
      for (size_t j = 0; j < width_; ++j) {
        sum_[i + 1][j + 1] = sum_[i + 1][j] + vec_[i][j];
      }
    }
    for (size_t i = 0; i < width_; ++i) {
      for (size_t j = 0; j < height_; ++j) {
        sum_[j + 1][i + 1] += sum_[j][i + 1];
      }
    }
  }
};

// verification code
/*
void ABC106_D() {
  int n, m, query; cin >> n >> m >> query;
  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    int l, r; cin >> l >> r; --l; --r;
    ++board[l][r];
  }

  CumulativeSum2D<int> cs2(board);

  for (int i = 0; i < query; ++i) {
    int p, q; cin >> p >> q;
    --p; --q;
    cout << cs2.Get(p, p, q, q) << '\n';
  }
}
*/