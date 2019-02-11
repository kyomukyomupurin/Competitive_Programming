/**
 *  split string
**/

vector<string> split(const string &str, char sep) {
  vector<string> v;
  auto beg = str.begin();
  while(beg != str.end()) {
    auto end = beg;
    while(end != str.end() && *end != sep) ++end;
    v.push_back(string(beg, end));
    if(end != str.end()) ++end;
    beg = end;
  }
  return v;
}