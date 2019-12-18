/**
 *  coodinate compression
**/

#include <algorithm>
#include <vector>

// verified by https://atcoder.jp/contests/abc036/tasks/abc036_c
template <typename T>
class CoodinateCompression {
 public:
  CoodinateCompression(const std::vector<T>& vec) : vec_(vec) {
    result_.resize(vec_.size());
    Compress();
  }
  struct state {
    T before;
    int after;
  };
  state operator[](int pos) const { return result_[pos]; }

 private:
  std::vector<T> vec_;
  std::vector<state> result_;
  void Compress() {
    std::vector<T> t = vec_;
    std::sort(t.begin(), t.end());
    t.erase(std::unique(t.begin(), t.end()), t.end());
    for (size_t i = 0; i < vec_.size(); ++i) {
      result_[i] = {vec_[i], static_cast<int>(std::distance(
                                t.begin(),
                                std::lower_bound(t.begin(), t.end(), vec_[i])))};
    }
  }
};

/*
void ABC36_C() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  CoodinateCompression<int> cc(a);
  for (int i = 0; i < n; ++i) {
    cout << cc[i].after << '\n';
  }
}
*/