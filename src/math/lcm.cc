// GCD(Greatest Common Divisor), LCM(Least Common Multiple)

template<class T> T gcd(T x, T y) {
  while (y > 0){
    T tmp = x % y;
    x = y;
    y = tmp;
  }
  return x;
}

template<class T> T lcm(T x, T y) {
  if (x == 0 || y == 0) return 0;
  else return x * y / gcd(x, y);
}