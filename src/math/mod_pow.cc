// Calculate x^n (modulo mod)

template<class T, class U> T mod_pow(T x, U n, T mod) {
  T res = 1;
  while (n > 0) {
    if (n & 1) (res *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return res;
}