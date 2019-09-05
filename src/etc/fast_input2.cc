/**
 *  fast input
**/

#include <iostream>

constexpr int cm = 1<<17;
char buff[cm], *ci = buff + cm, ct;

inline char readchar() {
  if (ci - buff == cm) {
    fread(buff, 1, cm, stdin);
    ci = buff;
  }
  return *ci++;
}

inline int readint() {
  int num = 0;
  if (ci - buff + 16 > cm) {
    while ((ct = readchar()) >= '0') {
      num = (num << 3) + (num << 1) + ct - '0';
    }
  } else {
    while ((ct = *ci++) >= '0') {
      num = (num << 3) + (num << 1) + ct - '0';
    }
  }
  return num;
}