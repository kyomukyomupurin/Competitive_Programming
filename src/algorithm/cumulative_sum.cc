/**
 *  cumulative sum
**/

#include <vector>

template <typename T>
class CumulativeSum {
 public:
  CumulativeSum(const std::vector<T>& vec) : vec_(vec) { Build(); }
  T Get(int left, int right);

 private:
  std::vector<T> vec_;
  std::vector<T> sum_;
  void Build();
};

// return sum of [left, right]
template <typename T>
T CumulativeSum<T>::Get(int left, int right) {
  return sum_[right + 1] - sum_[left];
}

template <typename T>
void CumulativeSum<T>::Build() {
  sum_.assign(vec_.size() + 1, static_cast<T>(0));
  for (size_t i = 0; i < vec_.size(); ++i) {
    sum_[i + 1] = sum_[i] + vec_[i];
  }
}