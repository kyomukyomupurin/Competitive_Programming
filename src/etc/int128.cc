// Helper function for __int128_t

#include <algorithm>
#include <iostream>
#include <string>

// snippet-begin
using int128 = __int128_t;

std::istream& operator>>(std::istream& is, int128& val) {
  std::string s;
  is >> s;
  val = 0;
  bool neg = false;
  int sz = s.size();
  for (int i = 0; i < sz; ++i) {
    if (!i && s[i] == '-') {
      neg = true;
    } else {
      val = val * 10 + (s[i] ^ 48);
    }
  }
  if (neg) val = -val;
  return is;
}

std::ostream& operator<<(std::ostream& os, const int128& val) {
  if (!val) return os << '0';
  int128 t = val;
  if (val < 0) {
    os << '-';
    t = -t;
  }
  std::string str = "";
  while (t) {
    str += (char)(t % 10 | 48);
    t /= 10;
  }
  std::reverse(str.begin(), str.end());
  return os << str;
}
// snippet-end
