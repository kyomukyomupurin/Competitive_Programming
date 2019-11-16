/**
 *  two dimensional cumulative sum
**/

#include <vector>
#include <cassert>

template <typename T>
class CumulaticeSum2D {
 public:
  CumulaticeSum2D(const std::vector<vector<T>>& vec)
      : vec_(vec), height_(vec.size()), width_(vec[0].size()) {
    Build();
  }
  T Get(int sx, int sy, int gx, int gy);

 private:
  size_t height_;
  size_t width_;
  std::vector<vector<T>> vec_;
  std::vector<vector<T>> sum_;
  void Build();
};

// return sum of [sx, gx] * [sy, gy]
template <typename T>
T CumulaticeSum2D<T>::Get(int sx, int sy, int gx, int gy) {
  assert(sx <= gx && sy <= gy);
  assert(0 <= sx && sx < height_ && 0 <= gx && gx < height_ && 0 <= sy &&
         sy < width_ && 0 <= gy && gy < width_);
  return sum_[gx + 1][gy + 1] - sum_[gx + 1][sy] - sum_[sx][gy + 1] +
         sum_[sx][sy];
}

template <typename T>
void CumulaticeSum2D<T>::Build() {
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