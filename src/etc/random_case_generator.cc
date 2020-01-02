// Automatic generation of random cases to find corner cases
// input format:
// n
// v_0 v_1 v_2 ... v_n - 1

#include <chrono>
#include <ext/random>
#include <fstream>
#include <iostream>
#include <vector>

class RandomCase {
 public:
  RandomCase(double run_time)
      : run_time_(run_time),
        rng_(std::chrono::steady_clock::now().time_since_epoch().count()) {}
  void Run();

 private:
  double run_time_;
  __gnu_cxx::sfmt19937_64 rng_;
  void Generate();
  int Solve1();
  int Solve2();
};

void RandomCase::Run() {
  std::chrono::system_clock::time_point start =
      std::chrono::system_clock::now();
  std::chrono::system_clock::time_point stop = std::chrono::system_clock::now();
  while (std::chrono::duration_cast<std::chrono::milliseconds>(stop - start)
             .count() < run_time_) {
    Generate();
    std::ifstream in("random_case.txt");
    std::cin.rdbuf(in.rdbuf());
    int ans1 = Solve1();

    std::ifstream in2("random_case.txt");
    std::cin.rdbuf(in2.rdbuf());
    int ans2 = Solve2();

    if (ans1 != ans2) {
      std::cout << "found!" << '\n';
      break;
    }
    stop = std::chrono::system_clock::now();
  }
}

void RandomCase::Generate() {
  std::ofstream outputfile("random_case.txt");
  std::uniform_int_distribution<int> n(1, 100);
  std::uniform_int_distribution<int> vec(1, 1000);
  int num = n(rng_);
  outputfile << num << '\n';
  for (int i = 0; i < num; ++i) {
    outputfile << vec(rng_) << " ";
  }
  outputfile.close();
}

// naive solution
// it must be 200% correct!
int RandomCase::Solve1() {}

// your solution
int RandomCase::Solve2() {}