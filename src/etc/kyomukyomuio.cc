#include <charconv>
#include <cstring>
#include <iostream>

using int64 = long long;

// snippet-begin
namespace kyomukyomuIO {
class Scanner {
  static constexpr int sz = 1 << 18;
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
    int res = sz - (cur - buf);
    memcpy(buf, cur, res);
    fread(buf + res, 1, sz - res, stdin);
    cur = buf;
  }

  inline void skip() {
    while (*cur == ' ' || *cur == '\n') ++cur;
  }

  inline void read(int& num) {
    skip();
    if (cur + 20 >= buf + sz) reload();
    cur = const_cast<char*>(std::from_chars(cur, cur + 20, num).ptr);
  }

  inline void read(int64& num) {
    skip();
    if (cur + 20 >= buf + sz) reload();
    cur = const_cast<char*>(std::from_chars(cur, cur + 20, num).ptr);
  }
};

class Printer {
  static constexpr int sz = 1 << 18;
  char buf[sz];
  char* cur = buf;

 public:
  Printer() {}

  ~Printer() { flush(); }

  void flush() {
    fwrite(buf, 1, cur - buf, stdout);
    cur = buf;
  }

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
  inline void write(int num) {
    if (cur + 20 >= buf + sz) flush();
    cur = std::to_chars(cur, cur + 20, num).ptr;
  }

  inline void write(int64 num) {
    if (cur + 20 >= buf + sz) flush();
    cur = std::to_chars(cur, cur + 20, num).ptr;
  }

  inline void write(char c) {
    if (cur + 1 >= buf + sz) flush();
    *cur = c;
    ++cur;
  }

  inline void write(std::string str) {
    if (cur + str.size() >= buf + sz) flush();
    for (char c : str) *cur = c, ++cur;
  }

  inline void write(const char* str) {
    if (cur + strlen(str) >= buf + sz) flush();
    for (int i = 0; str[i]; ++i) *cur = str[i], ++cur;
  }
};
}  // namespace kyomukyomuIO

kyomukyomuIO::Scanner kin;
kyomukyomuIO::Printer kout;
// snippet-end