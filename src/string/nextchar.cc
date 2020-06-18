// verified by
//     https://atcoder.jp/contests/abc138/tasks/abc138_e

#include <cassert>
#include <string>
#include <vector>

// snippet-begin
class NextChar {
 public:
  NextChar(const std::string& str) : str_(str) { build(); }

  // returns the first position in str[pos:n_) that c appears
  // if c is not in str[pos:n_), returns n_
  int find(int pos, char c) const {
    assert(0 <= pos && pos < n_);
    return table_[c - 'a'][pos];
  }

  // returns whether str contains c or not
  bool contain(char c) const { return find(0, c) != n_; }

 private:
  int n_;
  std::string str_;
  std::vector<std::vector<int>> table_;

  void build() {
    n_ = str_.size();
    table_.resize(26, std::vector<int>(n_));
    for (char c = 'a'; c <= 'z'; ++c) {
      int nxt = n_;
      for (int i = n_ - 1; i >= 0; --i) {
        if (str_[i] == c) nxt = i;
        table_[c - 'a'][i] = nxt;
      }
    }
  }
};
// snippet-end

// verification code
/*
void ABC138_E() {
  string s, t;
  cin >> s >> t;

  NextChar nc(s);
  int n = s.size();

  int64 ans = 0;
  int cur = 0;

  for (char c : t) {
    if (!nc.contain(c)) {
      cout << -1 << endl;
      return;
    } else {
      if (nc.find(cur, c) == n) {
        ans += (n - cur);
        cur = 0;
        ans += (nc.find(cur, c) - cur + 1);
        cur = (nc.find(cur, c) + 1) % n;
      } else {
        ans += (nc.find(cur, c) - cur + 1);
        cur = (nc.find(cur, c) + 1) % n;
      }
    }
  }

  cout << ans << endl;
}
*/