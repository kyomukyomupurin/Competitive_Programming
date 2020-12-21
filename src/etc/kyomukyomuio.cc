// Fast input for integer, fast output for integer and string

#include <cstring>
#include <iostream>

using int64 = long long;

// snippet-begin
#include <charconv>

namespace kyomukyomuIO {
class Scanner {
  static constexpr int sz = 1 << 19;
  char buf[sz];
  char* cur = buf;

 public:
  Scanner() { fread(buf, 1, sz, stdin); }

  template <class T>
  inline Scanner& operator>>(T& val) {
    read(val);
    return *this;
  }

 private:
  inline void reload() {
    size_t res = std::distance(cur, std::end(buf));
    memcpy(buf, cur, res);
    fread(std::next(buf, res), 1, sz - res, stdin);
    cur = buf;
  }

  inline void skip() {
    while (*cur == ' ' || *cur == '\n') ++cur;
  }

  inline void read(int& num) {
    skip();
    if (std::next(cur, 20) >= std::end(buf)) reload();
    cur = const_cast<char*>(std::from_chars(cur, std::next(cur, 20), num).ptr);
  }

  inline void read(int64& num) {
    skip();
    if (std::next(cur, 20) >= std::end(buf)) reload();
    cur = const_cast<char*>(std::from_chars(cur, std::next(cur, 20), num).ptr);
  }
};

class Printer {
  static constexpr int sz = 1 << 18;
  char buf[sz];
  char* cur = buf;

 public:
  Printer() {}

  ~Printer() { flush(); }

  template <class T>
  inline Printer& operator<<(T val) {
    write(val);
    return *this;
  }

  template <class T>
  inline void println(T val) {
    write(val);
    write('\n');
  }

 private:
  void flush() {
    fwrite(buf, 1, cur - buf, stdout);
    cur = buf;
  }

  inline void write(int num) {
    if (std::next(cur, 20) >= std::end(buf)) flush();
    cur = std::to_chars(cur, std::next(cur, 20), num).ptr;
  }

  inline void write(int64 num) {
    if (std::next(cur, 20) >= std::end(buf)) flush();
    cur = std::to_chars(cur, std::next(cur, 20), num).ptr;
  }

  inline void write(char c) {
    if (std::next(cur) >= std::end(buf)) flush();
    *cur = c;
    std::advance(cur, 1);
  }

  inline void write(const std::string& str) {
    if (std::next(cur, str.size()) >= std::end(buf)) flush();
    for (char c : str) {
      *cur = c;
      std::advance(cur, 1);
    }
  }

  inline void write(const char* str) {
    if (std::next(cur, std::strlen(str)) >= std::end(buf)) flush();
    memcpy(cur, str, std::strlen(str));
    std::advance(cur, std::strlen(str));
  }
};
}  // namespace kyomukyomuIO

kyomukyomuIO::Scanner in;
kyomukyomuIO::Printer out;
// snippet-end