// Coodinate compression

#include <algorithm>
#include <vector>

// snippet-begin
template <class T>
inline std::vector<int> compressed(const std::vector<T>& vec) {
  std::vector<T> t = vec;
  std::sort(t.begin(), t.end());
  int n = vec.size();
  t.erase(std::unique(t.begin(), t.end()), t.end());
  std::vector<int> compressed(n);
  for (int i = 0; i < n; ++i)
    compressed[i] =
        std::distance(t.begin(), std::lower_bound(t.begin(), t.end(), vec[i]));
  return compressed;
}
// snippet-end