// Cumulative Sum

#include <vector>

// snippet-begin
template <class T>
class CumulativeSum {
 public:
  CumulativeSum(const std::vector<T>& vec) : vec_(vec) { build(); }

  // return sum of [l, r]
  T get(int l, int r) { return sum_[r + 1] - sum_[l]; }

  // return the first k where sum of [0, k] >= value
  // use only when all element in vec >= 0
  int lower_bound(T val) {
    return std::distance(sum_.begin() + 1,
                         std::lower_bound(sum_.begin() + 1, sum_.end(), val));
  }

  // return the first k where sum of [0, k] > value
  // use only when all element in vec >= 0
  int upper_bound(T val) {
    return std::distance(sum_.begin() + 1,
                         std::upper_bound(sum_.begin() + 1, sum_.end(), val));
  }

 private:
  std::vector<T> vec_;
  std::vector<T> sum_;

  void build() {
    sum_.resize(vec_.size() + 1);
    sum_[0] = 0;
    std::partial_sum(vec_.begin(), vec_.end(), sum_.begin() + 1);
  }
};
// snippet-end
