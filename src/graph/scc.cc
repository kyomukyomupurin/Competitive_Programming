// Strongly Connected Component

#include <vector>

#include "./graph.cc"

// snippet-begin
template <class T>
class scc_digraph : public digraph<T> {
 public:
  using digraph<T>::n_;
  using digraph<T>::data_;
  using digraph<T>::edges_;

  std::vector<int> ids_;
  std::vector<std::vector<int>> components_;

  scc_digraph(int n)
      : digraph<T>(n),
        ids_(n),
        components_(n),
        cnt_(0),
        visited_(n, false),
        rg_(n) {}

  void build() {
    for (int i = 0; i < n_; ++i) {
      if (!visited_[i]) dfs(i);
    }
    visited_.assign(n_, false);
    rg_ = (*this).reverse();
    for (int i = n_ - 1; i >= 0; --i) {
      if (!visited_[order_[i]]) dfs2(order_[i], cnt_++);
    }
    components_.resize(cnt_);
  }

  int operator[](int v) const noexcept {
    assert(0 <= v && v < n_);
    return ids_[v];
  }

 private:
  int cnt_;
  std::vector<int> order_;
  std::vector<bool> visited_;
  digraph<T> rg_;

  void dfs(int cur) {
    visited_[cur] = true;
    for (int id : data_[cur]) {
      const auto& [from, to, cost] = edges_[id];
      int nxt = from ^ to ^ cur;
      if (visited_[nxt]) continue;
      dfs(nxt);
    }
    order_.emplace_back(cur);
  }

  void dfs2(int cur, int k) {
    visited_[cur] = true;
    components_[k].emplace_back(cur);
    ids_[cur] = k;
    for (int id : rg_.data_[cur]) {
      const auto& [from, to, cost] = rg_.edges_[id];
      int nxt = from ^ to ^ cur;
      if (visited_[nxt]) continue;
      dfs2(nxt, k);
    }
  }
};
// snippet-end