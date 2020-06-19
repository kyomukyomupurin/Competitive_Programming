// Z algorithm
// verified by
//     https://atcoder.jp/contests/abc141/tasks/abc141_e

#include <vector>
#include <string>

// snippet-begin
std::vector<int> Zalgorithm(const std::string str) {
  int n = str.size();
  std::vector<int> res(n);
  res[0] = n;
  int i = 1, j = 0;
  while (i < n) {
    while (i + j < n && str[j] == str[i + j]) ++j;
    res[i] = j;
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < n && k + res[k] < j) res[i + k] = res[k], ++k;
    i += k;
    j -= k;
  }
  return res;
};
// snippet-end

// verification code
/*
void ABC141_D() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    string t = s.substr(i, n - i);
    vector<int> v = Zalgorithm(t);

    for (int j = 0; j < n - i; ++j) {
      ans = max(ans, min(j, v[j]));
    }
  }
  cout << ans << endl;
}
*/