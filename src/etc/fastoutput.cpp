/**
 *  fast output
**/

#include <iostream>

void fastout(int &n) {
  int N = n, rev, count = 0;
  rev = N;
  if (N == 0) { 
    putchar('0');
    putchar('\n');
    return;
  }
  while ((rev % 10) == 0) { 
    ++count; rev /= 10;
  }
  rev = 0;
  while (N != 0) { 
    rev = (rev << 3) + (rev << 1) + N % 10;
    N /= 10;
  }
  while (rev != 0) { 
    putchar(rev % 10 + '0');
    rev /= 10;
  }
  while (count--) putchar('0');
  putchar('\n');
}