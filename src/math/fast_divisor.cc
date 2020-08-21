// Fast divisor enumeration

#include <algorithm>
#include <vector>

#include "./../algorithm/run_length_encoding.cc"
#include "./factor.cc"

// snippet-begin
template <class T>
std::vector<T> divisor(T n) {
  std::vector<T> v1 = factor(n);
  auto v2 = RunLengthEncoding(v1);
  std::vector<T> div;
  int sz = v2.size();
  auto dfs = [&](auto&& self, T val, int d) -> void {
    if (d == sz) {
      div.emplace_back(val);
      return;
    }
    int cur = 1;
    auto [pr, cnt] = v2[d];
    for (int i = 0; i < cnt + 1; ++i, cur *= pr) {
      self(self, val * cur, d + 1);
    }
  };
  dfs(dfs, 1, 0);
  std::sort(div.begin(), div.end());

  return div;
}
// snippet-end
