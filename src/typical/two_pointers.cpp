/**
 *  two pointers algorithm
**/

#include <iostream>
#include <vector>
using int64 = long long;

int n;
std::vector<int> a(n);
int right = 0;
int64 sum = 0;

// condition
bool ok(int64 sum) {
  // for example
  return sum < 123456789;
}

void two_pointers() {
  // fix left
  for (int left = 0; left < n; ++left) {
    // increment right while ok
    while (right < n && ok(sum + a[right])) {
      sum += a[right];
      ++right;
    }
    int len = right - left;

    /**
     *  do something using 'len'(length of section which satisfies condition)
    **/

    // if right do not move at all, increment it
    if (right == left) {
      ++right;
    } else {
      sum -= a[left];
    }
  }

  return;
}