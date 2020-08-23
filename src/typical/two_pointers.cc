// two pointers algorithm

#include <iostream>
#include <vector>

using int64 = long long;

int n;
std::vector<int> a(n);
int right = 0;
int64 sum = 0;

bool ok(int64 sum) {
  return sum < 123456789;
}

void two_pointers() {
  for (int left = 0; left < n; ++left) {
    while (right < n && ok(sum + a[right])) {
      sum += a[right];
      ++right;
    }
    int len = right - left;

    ...

    if (right == left) {
      ++right;
    } else {
      sum -= a[left];
    }
  }

  return;
}