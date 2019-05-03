/**
 *  gcd(greatest common divisor), lcm(least common multiple)
**/

#include <iostream>

template<typename T> T gcd(T x, T y){
  while (y > 0){
    T tmp = x % y;
    y = x;
    x = tmp;
  }
  return x;
}

template<typename T> T lcm(T x, T y){
  if (x == 0 || y == 0) return 0;
  else return x * y / gcd(x, y);
}