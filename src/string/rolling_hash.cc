/**
 *  Rolling Hash
**/

#include <chrono>
#include <string>
#include <vector>

// verified by
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
class RollingHash {
 public:
  RollingHash(const std::string& s) : s_(s) { Initialize(); }
  unsigned int GetHash(int left, int right);

 private:
  const std::string s_;
  static std::vector<unsigned int> bases_;
  static unsigned int base_;
  const unsigned int mod_ = 1000000007;
  std::vector<unsigned int> hash_;
  std::vector<unsigned int> power_;
  void Initialize();
  unsigned int mul(unsigned int a, unsigned int b);
};

std::vector<unsigned int> RollingHash::bases_ = {
    10007, 10009, 10037, 10039, 10061, 10067, 10069, 10079, 10091, 10093, 10099,
    10103, 10111, 10133, 10139, 10141, 10151, 10159, 10163, 10169, 10177, 10181,
    10193, 10211, 10223, 10243, 10247, 10253, 10259, 10267, 10271, 10273, 10289,
    10301, 10303, 10313, 10321, 10331, 10333, 10337, 10343, 10357, 10369, 10391,
    10399, 10427, 10429, 10433, 10453, 10457, 10459, 10463, 10477, 10487, 10499,
    10501, 10513, 10529, 10531, 10559, 10567, 10589, 10597, 10601, 10607, 10613,
    10627, 10631, 10639, 10651, 10657, 10663, 10667, 10687, 10691, 10709, 10711,
    10723, 10729, 10733, 10739, 10753, 10771, 10781, 10789, 10799, 10831, 10837,
    10847, 10853, 10859, 10861, 10867, 10883, 10889, 10891, 10903, 10909, 10937,
    10939, 10949, 10957, 10973, 10979, 10987, 10993, 11003, 11027, 11047, 11057,
    11059, 11069, 11071, 11083, 11087, 11093, 11113, 11117, 11119, 11131, 11149,
    11159, 11161, 11171, 11173, 11177, 11197};
unsigned int RollingHash::base_ =
    bases_[std::chrono::steady_clock::now().time_since_epoch().count() & 127];

// return hash value of [left, right)
unsigned int RollingHash::GetHash(int left, int right) {
  unsigned int ret =
      hash_[right] + mod_ - mul(hash_[left], power_[right - left]);
  if (ret >= mod_) ret -= mod_;
  return ret;
}

void RollingHash::Initialize() {
  int ssize = static_cast<int>(s_.size());
  hash_.assign(ssize + 1, 0);
  power_.assign(ssize + 1, 0);
  power_[0] = 1;
  for (int i = 0; i < ssize; ++i) {
    hash_[i + 1] = mul(hash_[i], base_) + s_[i];
    power_[i + 1] = mul(power_[i], base_);
    if (hash_[i + 1] >= mod_) hash_[i + 1] -= mod_;
  }
}

unsigned int RollingHash::mul(unsigned int a, unsigned int b) {
  unsigned long long x =
      static_cast<unsigned long long>(a) * static_cast<unsigned long long>(b);
  unsigned int xh = static_cast<unsigned int>(x >> 32),
               xl = static_cast<unsigned int>(x), d, m;
  asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod_));
  return m;
}