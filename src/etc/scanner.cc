// scanner

#include <iostream>
#include <vector>

using int64 = long long;

// snippet-begin
class Scanner {
  static constexpr int buf = (1 << 27);
  char in[buf], *rb;

 public:
  Scanner() {
    std::fread(in, 1, buf, stdin);
    rb = in;
  }

  template <class Int, std::enable_if_t<std::is_same<Int, int>::value, int> = 0>
  inline void read(Int& num) {
    bool neg = false;
    num = 0;
    while (!std::isdigit(*rb) && *rb != '-') ++rb;
    if (*rb == '-') neg = true, ++rb;
    while (std::isdigit(*rb)) num = (num << 3) + (num << 1) + (*rb - '0'), ++rb;
    if (neg) num = -num;
  }

  template <class Int64,
            std::enable_if_t<std::is_same<Int64, int64>::value, int> = 0>
  inline void read(Int64& num) {
    bool neg = false;
    num = 0;
    while (!std::isdigit(*rb) && *rb != '-') ++rb;
    if (*rb == '-') neg = true, ++rb;
    while (std::isdigit(*rb)) num = (num << 3) + (num << 1) + (*rb - '0'), ++rb;
    if (neg) num = -num;
  }

  template <class String,
            std::enable_if_t<std::is_same<String, std::string>::value, int> = 0>
  inline void read(String& str) {
    while (std::isspace(*rb)) ++rb;
    auto it = rb;
    while (!std::isspace(*rb)) ++rb;
    str = std::string(it, rb);
  }

  template <class Char,
            std::enable_if_t<std::is_same<Char, char>::value, int> = 0>
  inline void read(Char& c) {
    while (std::isspace(*rb)) ++rb;
    c = *rb, ++rb;
  }

  template <class Double,
            std::enable_if_t<std::is_same<Double, double>::value, int> = 0>
  inline void read(Double& num) {
    while (std::isspace(*rb)) ++rb;
    auto it = rb;
    while (!std::isspace(*rb)) ++rb;
    const std::string str = std::string(it, rb);
    num = std::stod(str);
  }

  template <
      class LongDouble,
      std::enable_if_t<std::is_same<LongDouble, long double>::value, int> = 0>
  inline void read(LongDouble& num) {
    while (std::isspace(*rb)) ++rb;
    auto it = rb;
    while (!std::isspace(*rb)) ++rb;
    const std::string str = std::string(it, rb);
    num = std::stold(str);
  }

  template <class Type>
  inline void read(std::vector<Type>& vec) {
    for (Type& e : vec) read(e);
  }

  /*
    void read() {}

    template <class Head, class... Tail>
    inline void read(Head&& head, Tail&&... tail) {
      read(head);
      read(std::forward<Tail>(tail)...);
    }
  */

  template <class Type>
  inline Scanner& operator>>(Type& value) {
    read(value);
    return *this;
  }
};
// snippet-end
