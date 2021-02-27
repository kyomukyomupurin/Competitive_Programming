// 2D Fenwick Tree

#include <vector>

// snippet-begin
template <class T>
class FenwickTree2D {
 public:
  FenwickTree2D(const std::vector<std::vector<T>>& vec)
      : x_(int(vec.size())), y_(int(vec[0].size())) {
    node_.assign(x_ + 1, std::vector<T>(y_ + 1, 0));
    for (int i = 0; i < x_; ++i) {
      for (int j = 0; j < y_; ++j) {
        add(i, j, vec[i][j]);
      }
    }
  }

  FenwickTree2D(int x, int y) : x_(x), y_(y) {
    node_.assign(x_ + 1, std::vector<T>(y_ + 1, 0));
  }

  // add val to (x, y)
  void add(int x, int y, T val) {
    for (int i = x + 1; i < x_ + 1; i += i & -i) {
      for (int j = y + 1; j < y_ + 1; j += j & -j) {
        node_[i][j] += val;
      }
    }
  }

  // return sum of [0, x] * [0, y]
  T get(int x, int y) const {
    T sum = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
      for (int j = y + 1; j > 0; j -= j & -j) {
        sum += node_[i][j];
      }
    }
    return sum;
  }

  // return sum of [sx, gx] * [sy, gy] 
  T get(int sx, int sy, int gx, int gy) const {
    return get(gx, gy) - get(sx - 1, gy) - get(gx, sy - 1) +
           get(sx - 1, sy - 1);
  }

 private:
  int x_;
  int y_;
  std::vector<std::vector<T>> node_;
};
// snippet-end
