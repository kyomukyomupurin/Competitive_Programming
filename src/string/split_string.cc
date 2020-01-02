// split string

#include <vector>
#include <string>

std::vector<std::string> split(const std::string &str, char sep) {
  std::vector<std::string> v;
  auto beg = str.begin();
  while(beg != str.end()) {
    auto end = beg;
    while(end != str.end() && *end != sep) ++end;
    v.push_back(std::string(beg, end));
    if(end != str.end()) ++end;
    beg = end;
  }
  return v;
}