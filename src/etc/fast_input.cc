/**
 *  fast input (available in gcc)
**/

#include <iostream>

// snippet-begin
class Scanner {
  static constexpr int buf = (1 << 27);
  char in[buf], *rb;

 public:
  Scanner() {
    std::fread(in, 1, buf, stdin);
    rb = in;
  }

  template <class Integer>
  inline void read_int(Integer& num) {
    bool neg = false;
    num = 0;
    while (!std::isdigit(*rb) && *rb != '-') ++rb;
    if (*rb == '-') neg = true, ++rb;
    while (std::isdigit(*rb)) num = (num << 3) + (num << 1) + (*rb - '0'), ++rb;
    if (neg) num = -num;
  }

  inline void read_string(std::string& str) {
    while (std::isspace(*rb)) ++rb;
    auto it = rb;
    while (!std::isspace(*rb)) ++rb;
    str = std::string(it, rb);
  }

  inline void read_char(char& c) {
    while (std::isspace(*rb)) ++rb;
    c = *rb, ++rb;
  }
};
// snippet-end
