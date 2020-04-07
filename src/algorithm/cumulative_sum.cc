// Cumulative Sum

#include <vector>

template <class _Tp>
class CumulativeSum {
 public:
  CumulativeSum(const std::vector<_Tp>& vec) : vec_(vec) { build(); }

  // return sum of [l, r]
  _Tp get(int l, int r) { return sum_[r + 1] - sum_[l]; }

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