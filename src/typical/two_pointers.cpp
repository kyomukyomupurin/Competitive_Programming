/**
 *  two pointers algorithm
**/

#include <iostream>
#include <vector>

int n;
std::vector<int> a(n);
int right = 0;
int64_t sum = 0;

// consition
bool ok(int64_t sum) {
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
     *  do something using 'len'(lenght of section which satisfies condition)
    **/

    // if rihgt can not go forward, increment it
    if (right == left) {
      ++right;
    } else {
      sum -= a[left];
    }
  }

  return;
}