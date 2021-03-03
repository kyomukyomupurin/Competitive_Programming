// Helper function for __int128_t

#include <algorithm>
#include <iostream>
#include <string>

// snippet-begin
using int128 = __int128_t;

int128 to_int128(const std::string& str) {
  int128 val = 0;
  bool neg = (str[0] == '-');
  for (int i = neg ? 1 : 0; i < int(str.size()); ++i) {
    val = val * 10 + (str[i] & 15);
  }
  return neg ? -val : val;
}

int128 to_int128(const char* str) { return to_int128(std::string(str)); }

std::string to_string(const int128& val) {
  std::string str = "";
  int128 t = val;
  bool neg = (t < 0);
  if (neg) t = -t;
  while (t) {
    str += char(t % 10 | 48);
    t /= 10;
  }
  if (neg) str += '-';
  std::reverse(str.begin(), str.end());
  return str;
}

std::istream& operator>>(std::istream& is, int128& val) {
  std::string str;
  is >> str;
  val = to_int128(str);
  return is;
}

std::ostream& operator<<(std::ostream& os, const int128& val) {
  return os << to_string(val);
}
// snippet-end