/**
 *  fast input
**/

#include <iostream>

template<typename T> void fastin(T &num) {
  bool negative = false;
  T c;
  num = 0;
  c = getchar_unlocked();
  if (c == '-') {
    negative = true;
    c = getchar_unlocked();
  }
  for (; (c > 47 && c < 58); c = getchar_unlocked()) num = (num << 3) + (num << 1) + c - 48;
  if (negative) num *= -1;
}