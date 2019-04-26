/**
 *  gcd(greatest common divisor), lcm(least common multiple)
**/

#include <iostream>

template<typename T> T gcd(T x, T y){
  if (x % y == 0) return y;
  else return gcd(y, x % y);
}

template<typename T> T lcm(T x, T y){
  if (x % y == 0) return x;
  else if (y % x == 0) return y;
  else return x * y / gcd(x, y);
}