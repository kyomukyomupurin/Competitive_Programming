// Cumulative Sum

#include <vector>

// snippet-begin
template <class _Tp>
class CumulativeSum {
 public:
  CumulativeSum(const std::vector<_Tp>& vec) : vec_(vec) { build(); }

  // return sum of [l, r]
  _Tp get(int l, int r) { return sum_[r + 1] - sum_[l]; }

  // return the first k where sum of [0, k] >= value
  // use only when all element in vec >= 0
  int lower_bound(_Tp value) {
    return std::distance(sum_.begin() + 1,
                         std::lower_bound(sum_.begin() + 1, sum_.end(), value));
  }

  // return the first k where sum of [0, k] > value
  // use only when all element in vec >= 0
  int upper_bound(_Tp value) {
    return std::distance(sum_.begin() + 1,
                         std::upper_bound(sum_.begin() + 1, sum_.end(), value));
  }

 private:
  std::vector<_Tp> vec_;
  std::vector<_Tp> sum_;

  void build() {
    sum_.assign(vec_.size() + 1, static_cast<_Tp>(0));
    for (size_t i = 0; i < vec_.size(); ++i) {
      sum_[i + 1] = sum_[i] + vec_[i];
    }
  }
};
// snippet-end
