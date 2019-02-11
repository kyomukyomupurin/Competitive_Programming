/**
 *  fast input
**/

void fastin(int &num) {
  bool neg = false;
  int c;
  num = 0;
  c = getchar_unlocked();
  if (c == '-') {
    neg = true;
    c = getchar_unlocked();
  }
  for (; (c > 47 && c < 58); c = getchar_unlocked()) num = (num << 3) + (num << 1) + c - 48;
  if (neg) num *= -1;
}