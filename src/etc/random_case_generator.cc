/**
 *  generate random case and try to detect corner case
**/

// input format:
// n
// v_0 v_1 v_2 ... v_n - 1

#include <chrono>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>

class Xorshift128plus {
 public:
  Xorshift128plus() { Initialize(); }
  using result_type = uint64_t;
  static constexpr uint64_t min() {
    return std::numeric_limits<result_type>::min();
  }
  static constexpr uint64_t max() {
    return std::numeric_limits<result_type>::max();
  }
  uint64_t operator()() { return GetNext(); }

 private:
  static uint64_t result_;
  static uint64_t seed0_;
  static uint64_t seed1_;
  void Next();
  void Initialize();
  uint64_t GetNext();
};

uint64_t Xorshift128plus::result_;
uint64_t Xorshift128plus::seed0_ = static_cast<uint64_t>(
    std::chrono::steady_clock::now().time_since_epoch().count());
uint64_t Xorshift128plus::seed1_ = static_cast<uint64_t>(
    std::chrono::steady_clock::now().time_since_epoch().count());

void Xorshift128plus::Initialize() {
  for (int i = 0; i < 40; ++i) {
    Next();
  }
}

void Xorshift128plus::Next() {
  uint64_t s1 = seed0_;
  uint64_t s0 = seed1_;
  result_ = s0 + s1;
  seed0_ = s0;
  s1 ^= s1 << 23;
  seed1_ = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
}

uint64_t Xorshift128plus::GetNext() {
  Next();
  return result_;
}

class Timer {
 public:
  Timer()
      : start_(std::chrono::system_clock::now()),
        stop_(std::chrono::system_clock::now()) {}
  void Start();
  void Stop();
  double GetElapsedTime();

 private:
  std::chrono::system_clock::time_point start_;
  std::chrono::system_clock::time_point stop_;
};

void Timer::Start() { start_ = std::chrono::system_clock::now(); }

void Timer::Stop() { stop_ = std::chrono::system_clock::now(); }

double Timer::GetElapsedTime() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(stop_ - start_)
      .count();
}

void generate_random_case() {
  std::ofstream outputfile("random_case.txt");
  Xorshift128plus xor128;
  std::uniform_int_distribution<int> n(1, 100);
  std::uniform_int_distribution<int> vec(1, 1000);
  int num = n(xor128);
  outputfile << num << '\n';
  for (int i = 0; i < num; ++i) {
    outputfile << vec(xor128) << " ";
  }
  outputfile.close();
}

int solve1() {
  // naive solution
  // it must be 100% correct!
}

int solve2() {
  // solution
}

void execute() {
  Timer t;
  t.Start();

  while (t.GetElapsedTime() < 10000) {
    generate_random_case();

    std::ifstream in("random_case.txt");
    std::cin.rdbuf(in.rdbuf());
    int ans1 = solve1();

    std::ifstream in2("random_case.txt");
    std::cin.rdbuf(in2.rdbuf());
    int ans2 = solve2();

    if (ans1 != ans2) {
      std::cout << "found!" << '\n';
      break;
    }
    t.Stop();
  }
}