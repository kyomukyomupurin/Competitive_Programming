// 2-SAT

#include <cassert>
#include <vector>

#include "./graph.cc"
#include "./scc.cc"

// snippet-begin
class TwoSAT {
 public:
  std::vector<bool> solution_;

  TwoSAT(int n) : solution_(n), n_(n), g_(2 * n) {}

  void add_clause(int i, bool f, int j, bool g) {
    assert(0 <= i && i < n_);
    assert(0 <= j && j < n_);
    g_.add(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
    g_.add(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
  }

  bool satisfiable() {
    g_.build();
    std::vector<int> ids = g_.ids_;
    for (int i = 0; i < n_; ++i) {
      if (ids[2 * i] == ids[2 * i + 1]) return false;
      solution_[i] = ids[2 * i] < ids[2 * i + 1];
    }
    return true;
  }

 private:
  int n_;
  scc_digraph<int> g_;
};
// snippet-end