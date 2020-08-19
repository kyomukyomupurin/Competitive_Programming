// Run length encoding

#include <string>
#include <vector>

// snippet-begin
std::vector<std::pair<char, int>> RunLengthEncoding(const std::string& str) {
  std::vector<std::pair<char, int>> ret;
  int sz = str.size();
  int beg = 0;
  while (beg < sz) {
    int ed = beg;
    while (ed + 1 < sz && str[beg] == str[ed + 1]) ++ed;
    int len = ed - beg + 1;
    ret.emplace_back(str[beg], len);
    beg = ed + 1;
  }
  return ret;
};

template <class T>
std::vector<std::pair<T, int>> RunLengthEncoding(const std::vector<T>& vec) {
  std::vector<std::pair<T, int>> ret;
  int sz = vec.size();
  int beg = 0;
  while (beg < sz) {
    int ed = beg;
    while (ed + 1 < sz && vec[beg] == vec[ed + 1]) ++ed;
    int len = ed - beg + 1;
    ret.emplace_back(vec[beg], len);
    beg = ed + 1;
  }
  return ret;
};
// snippet-end
