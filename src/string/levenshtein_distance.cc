// Levenstein distance
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_E

#include <algorithm>
#include <string>
#include <vector>
// snippet-begin
int Levenshtein_distance(const std::string& s1, const std::string& s2) {
  int n1 = s1.size(), n2 = s2.size();
  std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
  for (int i = 0; i <= n1; ++i) dp[i][0] = i;
  for (int i = 0; i <= n2; ++i) dp[0][i] = i;
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      const int cost = (s1[i] != s2[j]);
      dp[i + 1][j + 1] =
          std::min({dp[i + 1][j] + 1, dp[i][j + 1] + 1, dp[i][j] + cost});
    }
  }
  return dp[n1][n2];
}
// snippet-end