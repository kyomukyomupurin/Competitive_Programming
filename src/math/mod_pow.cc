// Calculate x^n (modulo mod)

template<class T> T mod_pow(T x, T n, T mod) {
  T res = 1;
  while (n > 0) {
    if (n & 1) (res *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return res;
}