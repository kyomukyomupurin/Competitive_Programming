// Euler's phi function
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D

// snippet-begin
template <class _Tp>
_Tp Totient(_Tp n) {
  _Tp res = n;
  for (_Tp i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;
    (res /= i) *= (i - 1);
    while (n % i == 0) n /= i;
  }
  if (n != 1) (res /= n) *= (n - 1);
  return res;
}
// snippet-end
