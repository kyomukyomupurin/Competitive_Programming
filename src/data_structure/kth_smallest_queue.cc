// 要素の追加・k 番目に小さい値の取得が高速にできるデータ構造(k は固定値)
// verify してないけどたぶん大丈夫

#include <queue>

// snippet-begin
template <class T, int K>
class KthSmallestQueue {
 public:
  KthSmallestQueue() {}

  // O(logN)
  void emplace(T val) noexcept {
    if (int(lower_.size()) < K) {
      lower_.emplace(val);
    } else {  // lower_.size() == k を保つ
      if (val >= lower_.top()) {
        upper_.emplace(val);
      } else {
        lower_.emplace(val);
        T tmp = lower_.top();
        lower_.pop();
        upper_.emplace(tmp);
      }
    }
  }

  // O(1)
  T get() const {
    assert(int(lower_.size()) == K);
    return lower_.top();
  }

 private:
  std::priority_queue<T> lower_;
  std::priority_queue<T, std::vector<T>, std::greater<T>> upper_;
};
// snippet-end