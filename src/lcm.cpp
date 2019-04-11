/**
 *  gcd(greatest common divisor), lcm(least common multiple)
**/

#include <iostream>

int64_t gcd(int64_t x, int64_t y){
  if (x % y == 0) return y;
  else return gcd(y, x % y);
}

int64_t lcm(int64_t x, int64_t y){
  if (x % y == 0) return x;
  else if (y % x == 0) return y;
  else return x * y / gcd(x, y);
}