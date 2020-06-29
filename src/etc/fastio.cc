// fastio

#include <cstring>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using int64 = long long;

// snippet-begin
namespace FastIO {
class Scanner {
  static constexpr int buf_size = (1 << 18);
  static constexpr int integer_size = 20;
  char buf[buf_size] = {};
  char *cur = buf, *ed = buf;

 public:
  Scanner() {}

  template <class T>
  inline Scanner& operator>>(T& val) {
    read(val);
    return *this;
  }

 private:
  inline void flush() {
    size_t len = ed - cur;
    memmove(buf, cur, len);
    char* tmp = buf + len;
    ed = tmp + fread(tmp, 1, buf_size - len, stdin);
    *ed = 0;
    cur = buf;
  }

  inline void skip_space() {
    while (true) {
      if (cur == ed) flush();
      while (std::isspace(*cur)) ++cur;
      if (__builtin_expect(cur != ed, 1)) return;
    }
  }

  template <class T, std::enable_if_t<std::is_same<T, int>::value, int> = 0>
  inline void read(T& num) {
    skip_space();
    if (cur + integer_size >= ed) flush();
    bool neg = false;
    num = 0;
    while (!std::isdigit(*cur) && *cur != '-') ++cur;
    if (*cur == '-') neg = true, ++cur;
    while (std::isdigit(*cur)) num = num * 10 + (*cur - '0'), ++cur;
    if (neg) num = -num;
  }

  template <class T, std::enable_if_t<std::is_same<T, int64>::value, int> = 0>
  inline void read(T& num) {
    skip_space();
    if (cur + integer_size >= ed) flush();
    bool neg = false;
    num = 0;
    while (!std::isdigit(*cur) && *cur != '-') ++cur;
    if (*cur == '-') neg = true, ++cur;
    while (std::isdigit(*cur)) num = num * 10 + (*cur - '0'), ++cur;
    if (neg) num = -num;
  }

  template <class T,
            std::enable_if_t<std::is_same<T, std::string>::value, int> = 0>
  inline void read(T& str) {
    skip_space();
    if (cur + str.size() >= ed) flush();
    auto it = cur;
    while (!std::isspace(*cur)) ++cur;
    str = std::string(it, cur);
  }

  template <class T, std::enable_if_t<std::is_same<T, char>::value, int> = 0>
  inline void read(T& c) {
    skip_space();
    if (cur + 1 >= ed) flush();
    c = *cur, ++cur;
  }

  template <class T, std::enable_if_t<std::is_same<T, double>::value, int> = 0>
  inline void read(T& num) {
    skip_space();
    if (cur + integer_size >= ed) flush();
    bool neg = false;
    num = 0;
    if (*cur == '-') neg = true, ++cur;
    while (std::isdigit(*cur)) num = num * 10 + (*cur - '0'), ++cur;
    if (*cur != '.') return;
    ++cur;
    T base = 0.1;
    while (std::isdigit(*cur)) {
      num += base * (*cur - '0');
      ++cur;
      base *= 0.1;
    }
    if (neg) num = -num;
  }

  template <class T,
            std::enable_if_t<std::is_same<T, long double>::value, int> = 0>
  inline void read(T& num) {
    skip_space();
    if (cur + integer_size >= ed) flush();
    bool neg = false;
    num = 0;
    if (*cur == '-') neg = true, ++cur;
    while (std::isdigit(*cur)) num = num * 10 + (*cur - '0'), ++cur;
    if (*cur != '.') return;
    ++cur;
    T base = 0.1;
    while (std::isdigit(*cur)) {
      num += base * (*cur - '0');
      ++cur;
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

class Printer {
  static constexpr int buf_size = (1 << 18);
  static constexpr int integer_size = 20;
  static constexpr int margin = 1;
  char buf[buf_size + margin] = {};
  char integer[integer_size + margin] = {};
  char* cur = buf;

 public:
  Printer() {}

  ~Printer() { flush(); }

  template <class T>
  inline Printer& operator<<(T val) {
    write(val);
    return *this;
  }

 private:
  inline void flush() {
    fwrite(buf, 1, cur - buf, stdout);
    cur = buf;
  }

  template <class T, std::enable_if_t<std::is_same<T, char>::value, int> = 0>
  inline void write(T c) {
    if (__builtin_expect(cur + 1 >= buf + buf_size, 0)) flush();
    *cur = c;
    ++cur;
  }

  template <class T,
            std::enable_if_t<std::is_same<T, std::string>::value, int> = 0>
  inline void write(T str) {
    if (__builtin_expect(cur + str.size() >= buf + buf_size, 0)) flush();
    for (char c : str) write(c);
  }

  template <class T, std::enable_if_t<std::is_same<T, int>::value, int> = 0>
  inline void write(T num) {
    if (__builtin_expect(cur + integer_size >= buf + buf_size, 0)) flush();
    if (num == 0) {
      write('0');
      return;
    }
    if (num < 0) {
      write('-');
      num = -num;
    }
    char* tmp = integer + sizeof(integer);
    T y = num;
    size_t len = 0;
    while (y > 0) {
      *--tmp = y % 10 + '0';
      y /= 10;
      ++len;
    }
    memcpy(cur, tmp, len);
    cur += len;
  }

  template <class T, std::enable_if_t<std::is_same<T, int64>::value, int> = 0>
  inline void write(T num) {
    if (__builtin_expect(cur + integer_size >= buf + buf_size, 0)) flush();
    if (num == 0) {
      write('0');
      return;
    }
    if (num < 0) {
      write('-');
      num = -num;
    }
    char* tmp = integer + sizeof(integer);
    T y = num;
    size_t len = 0;
    while (y > 0) {
      *--tmp = y % 10 + '0';
      y /= 10;
      ++len;
    }
    memcpy(cur, tmp, len);
    cur += len;
  }
};
}  // namespace FastIO

FastIO::Scanner sc;
FastIO::Printer pr;
// snippet-end
