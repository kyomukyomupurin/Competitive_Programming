// GCD(Greatest Common Divisor), LCM(Least Common Multiple)

template<class T> T gcd(T x, T y) { return __gcd(x, y); }
template<class T> T lcm(T x, T y) { return x / gcd(x, y) * y; }