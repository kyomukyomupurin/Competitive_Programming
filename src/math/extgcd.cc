// Extended euclidean algorithm
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E

// snippet-begin
// find x, y such that a * x + b * y = gcd(a, b)
template <class T>
T extgcd(T a, T b, T& x, T& y) {
  T d = a;
  if (b) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}
// snippet-end

// verification code
/*
void NTL_1_E() {
  int a, b; cin >> a >> b;
  int x, y;
  extgcd(a, b, x, y);
  cout << x << " " << y << '\n';
}
*/