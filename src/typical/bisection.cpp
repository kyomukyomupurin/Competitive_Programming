/**
 *  bisection method
**/

const int INF = (1<<30) - 1;

// find the minimum n to satisfy something

bool ok1(int n) {
  // for example
  return n >= 10000;
}

int solve1() {
  int low = 0;
  int high = INF; // high : impossible
  while (high - low > 1) {
    int mid = (low + high) >> 1;
    if (ok1(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return high;
}

// find the maximum n to satisfy something

bool ok2(int n) {
  // for example
  return n <= 500;
}

int solve2() {
  int low = -1; // low : impossible
  int high = 1e9;
  while (high - low > 1) {
    int mid = (high + low) >> 1;
    if (ok2(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return low;
}