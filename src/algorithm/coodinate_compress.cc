// Coodinate compression

#include <algorithm>
#include <vector>

// snippet-begin
template <class T>
class CoodinateCompression {
 public:
  CoodinateCompression(const std::vector<T>& data) : data_(data) {
    assert(!data.empty());
    std::sort(data_.begin(), data_.end());
    data_.erase(std::unique(data_.begin(), data_.end()), data_.end());
    n_ = data_.size();
  }

  T find_by_order(int ord) const noexcept {
    assert(0 <= ord && ord < n_);
    return data_[ord];
  }

  int find_by_value(T val) const noexcept {
    auto it = std::lower_bound(data_.begin(), data_.end(), val);
    assert(it != data_.end());
    return std::distance(data_.begin(), it);
  }

  int size() const noexcept { return n_; }

 private:
  int n_;
  std::vector<T> data_;
};
// snippet-end