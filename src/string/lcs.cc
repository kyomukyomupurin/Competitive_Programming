// longest common subsequence
// verified by
//     https://atcoder.jp/contests/dp/tasks/dp_f

#include <algorithm>
#include <string>
#include <vector>

// snippet-begin
std::string LCS(const std::string& str1, const std::string& str2) {
  int n1 = str1.size(), n2 = str2.size();
  std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      if (str1[i] == str2[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  int c1 = n1, c2 = n2;
  std::string ret = "";
  while (c1 > 0 && c2 > 0) {
    if (str1[c1 - 1] == str2[c2 - 1]) {
      ret += str1[c1 - 1];
      --c1;
      --c2;
    } else {
      if (dp[c1][c2] == dp[c1][c2 - 1]) {
        --c2;
      } else {
        --c1;
      }
    }
  }
  std::reverse(ret.begin(), ret.end());
  return ret;
}
// snippet-end
