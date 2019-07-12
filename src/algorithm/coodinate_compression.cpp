/**
 *  coodinate compression
**/

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T> void compression(std::vector<T> &v) {
  std::vector<T> t = v;
  std::sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  for (int i = 0; i < (int) v.size(); ++i) {
    v[i] = distance(t.begin(), std::lower_bound(t.begin(), t.end(), v[i]));
  }
}