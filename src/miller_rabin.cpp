/**
 *  Miller-Rabin
**/

#include <iostream>
#include <random>
using namespace std;

struct Miller_Rabin{
  int power(int x, unsigned int y, int p) { 
    int res = 1;
    x %= p;
    while (y > 0) {
      if (y & 1) res = (res*x) % p; 
      y >>= 1;
      x = (x*x) % p;
    } 
    return res; 
  } 
 
  bool miller_rabin(int d, int n) { 
    mt19937 kyomukyomupurin(1728);
    int a = 2 + kyomukyomupurin() % (n - 4);
    int x = power(a, d, n);
    if (x == 1 || x == n - 1) return true;

    while (d != n - 1) {
      x = (x * x) % n;
      d <<= 1;
      if (x == 1) return false; 
      if (x == n - 1) return true; 
    }
    return false;
  }

  bool isPrime(int64_t n, int k) { 
    if (n <= 1 || n == 4) return false; 
    if (n <= 3) return true;
  
    int d = n - 1;
    while (d % 2 == 0) d >>= 1;
  
    for (int i = 0; i < k; i++)
      if (!miller_rabin(d, n)) return false;
    return true; 
  }
};