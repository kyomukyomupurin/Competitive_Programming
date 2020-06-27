// scanner

#include <iostream>
#include <string>
#include <tuple>
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

  template <class T>
  inline Scanner& operator>>(T& val) {
    read(val);
    return *this;
  }

 private:
  inline void skip_space() {
    while (std::isspace(*rb)) ++rb;
  }

  template <class T, std::enable_if_t<std::is_same<T, int>::value, int> = 0>
  inline void read(T& num) {
    bool neg = false;
    num = 0;
    while (!std::isdigit(*rb) && *rb != '-') ++rb;
    if (*rb == '-') neg = true, ++rb;
    while (std::isdigit(*rb)) num = num * 10 + (*rb - '0'), ++rb;
    if (neg) num = -num;
  }

  template <class T, std::enable_if_t<std::is_same<T, int64>::value, int> = 0>
  inline void read(T& num) {
    bool neg = false;
    num = 0;
    while (!std::isdigit(*rb) && *rb != '-') ++rb;
    if (*rb == '-') neg = true, ++rb;
    while (std::isdigit(*rb)) num = num * 10 + (*rb - '0'), ++rb;
    if (neg) num = -num;
  }

  template <class T,
            std::enable_if_t<std::is_same<T, std::string>::value, int> = 0>
  inline void read(T& str) {
    skip_space();
    auto it = rb;
    while (!std::isspace(*rb)) ++rb;
    str = std::string(it, rb);
  }

  template <class T, std::enable_if_t<std::is_same<T, char>::value, int> = 0>
  inline void read(T& c) {
    skip_space();
    c = *rb, ++rb;
  }

  template <class T, std::enable_if_t<std::is_same<T, double>::value, int> = 0>
  inline void read(T& num) {
    skip_space();
    bool neg = false;
    num = 0;
    if (*rb == '-') neg = true, ++rb;
    while (std::isdigit(*rb)) num = num * 10 + (*rb - '0'), ++rb;
    if (*rb != '.') return;
    ++rb;
    T base = 0.1;
    while (std::isdigit(*rb)) {
      num += base * (*rb - '0');
      ++rb;
      base *= 0.1;
    }
    if (neg) num = -num;
  }

  template <class T, std::enable_if_t<std::is_same<T, long double>::value, int> = 0>
  inline void read(T& num) {
    skip_space();
    bool neg = false;
    num = 0;
    if (*rb == '-') neg = true, ++rb;
    while (std::isdigit(*rb)) num = num * 10 + (*rb - '0'), ++rb;
    if (*rb != '.') return;
    ++rb;
    T base = 0.1;
    while (std::isdigit(*rb)) {
      num += base * (*rb - '0');
      ++rb;
      base *= 0.1;
    }
    if (neg) num = -num;
  }

  template <class T>
  inline void read(std::vector<T>& vec) {
    for (T& e : vec) read(e);
  }

  template <class T, class U>
  inline void read(std::pair<T, U>& p) {
    read(p.first, p.second);
  }

  template <class Tuple, std::size_t... Is>
  inline void tuple_scan(Tuple& tp, std::index_sequence<Is...>) {
    (read(std::get<Is>(tp)), ...);
  }

  template <class... Args>
  inline void read(std::tuple<Args...>& tp) {
    tuple_scan(tp, std::index_sequence_for<Args...>{});
  }

  inline void read() {}

  template <class Head, class... Tail>
  inline void read(Head&& head, Tail&&... tail) {
    read(head);
    read(std::forward<Tail>(tail)...);
  }
};
// snippet-end
