// Fast input for integer
// Fast output for integer, char, std::string, char*
// Slower than FastIO, but implementation is very simple

#include <charconv>
#include <cstring>
#include <iostream>

using int64 = long long;

// snippet-begin
namespace FastIO {
class Scanner {
 public:
  Scanner() { fread(buf, 1, std::size(buf), stdin); }

  template <class T>
  inline Scanner& operator>>(T& val) {
    skip();
    scan(val);
    return *this;
  }

 private:
  char buf[1 << 19];
  char* cur = buf;

  inline void reload() {
    int res = std::distance(cur, std::end(buf));
    std::memcpy(buf, cur, res);
    fread(std::next(buf, res), 1, std::size(buf) - res, stdin);
    cur = buf;
  }

  inline void skip() {
    while (*cur == ' ' || *cur == '\n') ++cur;
  }

  inline void scan(int& num) {
    if (std::next(cur, 20) >= std::end(buf)) reload();
    cur = const_cast<char*>(std::from_chars(cur, std::next(cur, 20), num).ptr);
  }

  inline void scan(int64& num) {
    if (std::next(cur, 20) >= std::end(buf)) reload();
    cur = const_cast<char*>(std::from_chars(cur, std::next(cur, 20), num).ptr);
  }
};

class Printer {
 public:
  Printer() {}

  ~Printer() { flush(); }

  template <class T>
  inline Printer& operator<<(T val) {
    print(val);
    return *this;
  }

  template <class T>
  inline void println(T val) {
    print(val);
    print('\n');
  }

 private:
  char buf[1 << 19];
  char* cur = buf;

  void flush() {
    fwrite(buf, 1, std::distance(buf, cur), stdout);
    cur = buf;
  }

  inline void print(int num) {
    if (std::next(cur, 20) >= std::end(buf)) flush();
    cur = std::to_chars(cur, std::next(cur, 20), num).ptr;
  }

  inline void print(int64 num) {
    if (std::next(cur, 20) >= std::end(buf)) flush();
    cur = std::to_chars(cur, std::next(cur, 20), num).ptr;
  }

  inline void print(std::size_t num) {
    print(static_cast<int>(num));
  }

  inline void print(std::ptrdiff_t num) {
    print(static_cast<int>(num));
  }

  inline void print(char c) {
    if (std::next(cur) >= std::end(buf)) flush();
    *cur = c;
    ++cur;
  }

  inline void print(const std::string& str) {
    if (std::next(cur, str.size()) >= std::end(buf)) flush();
    std::strcpy(cur, str.data());
    std::advance(cur, str.size());
  }

  inline void print(const char* str) {
    if (std::next(cur, std::strlen(str)) >= std::end(buf)) flush();
    std::strcpy(cur, str);
    std::advance(cur, std::strlen(str));
  }
};
}  // namespace FastIO

FastIO::Scanner in;
FastIO::Printer out;
// snippet-end