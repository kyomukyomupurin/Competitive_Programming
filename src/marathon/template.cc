/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 2020-02-15 09:16:55
**/

#include <iostream>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
#include <bitset>
#include <cassert>
#include <cctype>
#include <iomanip>
#include <random>
#include <utility>
#include <chrono>

using namespace std;

using int64 = long long;

template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) { os << '{'; size_t n = vec.size(); for (size_t i = 0; i < n; ++i) { os << vec[i]; if (i != n - 1) os << ','; } os << '}'; return os; }
template<class T, class U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) { return os << '{' << p.first << " " << p.second << '}'; }
template<class T, class U> std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) { os << '{'; for (auto it = mp.begin(); it != mp.end(); ++it) { os << '{' << it->first << ':' << it->second << '}'; if (it != --mp.end()) os << ','; } os << '}'; return os; }
template<class T> std::ostream& operator<<(std::ostream& os, const std::set<T>& st) { os << '{'; for (auto it = st.begin(); it != st.end(); ++it) { os << *it; if (it != --st.end()) os << ','; } os << '}'; return os; }
template<class T> std::istream& operator>>(std::istream& is, std::vector<T>& vec) { size_t n = vec.size(); for (size_t i = 0; i < n; ++i) is >> vec[i]; return is; }

#define all(_) begin(_), end(_)
#define rall(_) rbegin(_), rend(_)

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 1728
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}

class Timer {
 public:
  // (second)
  double GetElapsedTime() {
    return static_cast<double>(GetCycle() - start_) /
           static_cast<double>(clock_frequency_);
  }

  void Start() { start_ = GetCycle(); }

 private:
  int64_t start_;
  static constexpr int64_t clock_frequency_ = 2800000000;

  int64_t GetCycle() {
    uint32_t low, high;
    __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
    return (static_cast<int64_t>(low)) | (static_cast<int64_t>(high) << 32);
  }
};

class Xorshift {
 public:
  Xorshift() {
    seed0_ = static_cast<uint64_t>(
        std::chrono::steady_clock::now().time_since_epoch().count());
    seed1_ = static_cast<uint64_t>(
        std::chrono::steady_clock::now().time_since_epoch().count());
  }
  using result_type = uint64_t;
  static constexpr uint64_t min() {
    return std::numeric_limits<result_type>::min();
  }
  static constexpr uint64_t max() {
    return std::numeric_limits<result_type>::max();
  }

  uint64_t operator()() { return GetNext(); }

 private:
  uint64_t result_;
  uint64_t seed0_;
  uint64_t seed1_;

  uint64_t GetNext() {
    uint64_t s1 = seed0_;
    uint64_t s0 = seed1_;
    result_ = s0 + s1;
    seed0_ = s0;
    s1 ^= s1 << 23;
    seed1_ = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
    return result_;
  }
};

#ifdef LOCAL
constexpr double TIME_LIMIT = 2.95;
#else
constexpr double TIME_LIMIT = 2.95;
#endif

inline void modify() {}

inline int calc() {}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  Timer time;
  time.Start();

  // input

  #ifdef LOCAL
  ofstream outputfile("./out.txt");
  #endif

  Xorshift rng;

  double HIGH_TEMP, LOW_TEMP;

  uniform_real_distribution<double> p(0, 1);

  int loop = 0;

  while (time.GetElapsedTime() <= TIME_LIMIT) {
    // random choice
    int cur_score = calc();
    modify();
    int new_score = calc();

    double temp = HIGH_TEMP + (LOW_TEMP - HIGH_TEMP) * (time.GetElapsedTime()) / TIME_LIMIT;
    double prob = exp((new_score - cur_score) / temp);

    if (prob < p(rng) && new_score < cur_score) modify();

    #ifdef LOCAL
    outputfile << loop << " " << calc_score() << '\n';
    #endif
  }

  #ifdef LOCAL
  outputfile.close();
  #endif

  // output

  return 0;
}