// Divisor Enumeration

#include <algorithm>
#include <vector>

// snippet-begin
template<class T>
std::vector<T> divisor(T n) {
  std::vector<T> res;
  for (T i = 1; i * i <= n; ++i) {
    if (n % i == 0){
      res.emplace_back(i);
      if (i * i != n){
        res.emplace_back(n / i);
      }
    }
  }
  std::sort(res.begin(), res.end());

  return res;
}
// snippet-end
