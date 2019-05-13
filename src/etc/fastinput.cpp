/**
 *  fast input
**/

#include <iostream>

void fastin(int &num) {
  bool neg = false;
  int c;
  num = 0;
  c = getchar();
  if (c == '-') {
    neg = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) num = (num << 3) + (num << 1) + c - 48;
  if (neg) num *= -1;
}