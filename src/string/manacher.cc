// Manacher
// verified by
//     https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d

#include <vector>
#include <string>

std::vector<int> Manacher(const std::string& s) {
  int n = s.size();
  std::vector<int> res(n);
  int i = 0, j = 0;
  while (i < n) {
    while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
    res[i] = j;
    int k = 1;
    while (i - k >= 0 && k + res[i - k] < j) res[i + k] = res[i - k], ++k;
    i += k;
    j -= k;
  }
  return res;
}

// verification code
/*
void ukuku09_D() {
  int n, q; cin >> n >> q;
  string s; cin >> s;

  vector<int> res = Manacher(s);

  auto f = [](int x, int y) {
    return max(x, y);
  };

  SegmentTree<int, decltype(f)> seg(res, 0, f);

  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    int low = 1, high = (r - l + 2) / 2 + 1;
    while (high - low > 1){
      int mid = (high + low) >> 1;
      if (seg.query(l + mid - 1, r - mid + 2) < mid) {
        high = mid;
      } else {
        low = mid;
      }
    }

    cout << 2 * low - 1 << '\n';
  }
}
*/