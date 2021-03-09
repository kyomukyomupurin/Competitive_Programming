// 要素の追加・中央値の取得が高速にできるデータ構造
// verify してないけどたぶん大丈夫

#include <queue>

// snippet-begin
template <class T>
class MedianQueue {
 public:
  MedianQueue() {}

  // O(logN)
  void emplace(T val) noexcept {
    if (lower_.empty()) {
      lower_.emplace(val);
    } else {
      // lower_.size() == upper_.size() か
      // lower_.size() == upper_.size() + 1
      // を保つ
      if (val >= lower_.top()) {
        upper_.emplace(val);
      } else {
        lower_.emplace(val);
      }

      if (upper_.size() > lower_.size()) {
        T tmp = upper_.top();
        upper_.pop();
        lower_.emplace(tmp);
      }
      if (lower_.size() == upper_.size() + 2) {
        T tmp = lower_.top();
        lower_.pop();
        upper_.emplace(tmp);
      }
    }
  }

  // O(1)
  T get() const {
    assert(!lower_.empty());
    if (lower_.size() > upper_.size()) { // 要素が奇数個
      return lower_.top();
    } else {  // 要素が偶数個のときは問題文の median の定義をよく読むこと！
      return lower_.top();
    }
  }

 private:
  std::priority_queue<T> lower_;
  std::priority_queue<T, std::vector<T>, std::greater<T>> upper_;
};
// snippet-end