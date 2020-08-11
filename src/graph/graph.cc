// Graph template

#include <cassert>
#include <vector>

// snippet-begin
template <class T>
class graph {
 public:
  graph(int n) : n_(n) { data_.resize(n_); }
  struct edge {
    int from, to;
    T cost;

    edge(int from_, int to_, T cost_) : from(from_), to(to_), cost(cost_) {}
  };
  int n_;
  std::vector<std::vector<int>> data_;
  std::vector<edge> edges_;

  virtual void add(int from, int to, T cost) = 0;
};

template <class T>
class forest : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::data_;
  using graph<T>::edges_;

  forest(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n_ && 0 <= to && to < n_);
    int id = edges_.size();
    assert(id < n_ - 1);
    data_[from].emplace_back(id);
    data_[to].emplace_back(id);
    edges_.emplace_back(from, to, cost);
  }
};

template <class T>
class digraph : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::data_;
  using graph<T>::edges_;

  digraph(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n_ && 0 <= to && to < n_);
    int id = edges_.size();
    data_[from].emplace_back(id);
    edges_.emplace_back(from, to, cost);
  }

  digraph<T> reverse() const {
    digraph<T> rev(n_);
    for (const auto& [from, to, cost] : edges_) {
      rev.add(to, from, cost);
    }
    return rev;
  }
};

template <class T>
class undigraph : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::data_;
  using graph<T>::edges_;

  undigraph(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n_ && 0 <= to && to < n_);
    int id = edges_.size();
    data_[from].emplace_back(id);
    data_[to].emplace_back(id);
    edges_.emplace_back(from, to, cost);
  }
};
// snippet-end
