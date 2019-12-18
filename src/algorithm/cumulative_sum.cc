/**
 *  cumulative sum
**/

#include <vector>

template <class T>
class CumulativeSum {
 public:
  CumulativeSum(const std::vector<T>& vec) : vec_(vec) { Build(); }
  // return sum of [left, right]
  T Get(int left, int right) {
    return sum_[right + 1] - sum_[left];    
  }

 private:
  std::vector<T> vec_;
  std::vector<T> sum_;
  void Build() {
    sum_.assign(vec_.size() + 1, static_cast<T>(0));
    for (size_t i = 0; i < vec_.size(); ++i) {
      sum_[i + 1] = sum_[i] + vec_[i];
    }
  }
};