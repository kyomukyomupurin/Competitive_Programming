// Graph template

#include <vector>

// snippet-begin
namespace Graph {
template <class T> 
class graph {
 public:
  graph(int n) : n_(n) { data_.resize(n_); }
  struct edge {
    int from, to;
    T cost;
  };
  int n_;
  std::vector<std::vector<int>> data_;
  std::vector<edge> edges_;

  virtual void add(int from, int to, T cost) = 0;
};

template <class T>
class digraph : public graph<T> {
 public:
  using Graph::graph<T>::n_;
  using Graph::graph<T>::data_;
  using Graph::graph<T>::edges_;

  digraph(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    int id = edges_.size();
    data_[from].emplace_back(id);
    edges_.push_back({from, to, cost});
  }

  digraph<T> reverse() const {
    digraph<T> rev(n_);
    for (auto& e : edges_) {
      rev.add(e.to, e.from, e.cost);
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
    int id = edges_.size();
    data_[from].emplace_back(id);
    data_[to].emplace_back(id);
    edges_.push_back({from, to, cost});
  }
};
}

using namespace Graph;
// snippet-end
