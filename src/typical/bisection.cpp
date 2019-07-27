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
  int low = 0; // 小さめにとっておく(そうしないと low <= x <= high の全ての x が条件を満たすときに壊れる)
  int high = INF; // 大きめにとっておく(条件を満たす数がないときに最初に high に設定した値が返ってくる)
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
  int low = -1; // 小さめにとっておく(条件を満たす数がないときに最初に low に設定した値が返ってくる)
  int high = 1e9; // 大きめにとっておく(そうしないと low <= x <= high の全ての x が条件を満たさないときに壊れる)
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