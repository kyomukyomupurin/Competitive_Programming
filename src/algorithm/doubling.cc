// doubling algorithm

#include <vector>

using int64 = long long;

// snippet-begin
class Doubling {
 public:
  Doubling(int n, int64 k) : n_(n), lg_(64 - __builtin_clzll(k)) {
    table.assign(lg_, std::vector<int>(n_, -1));
  }

  void set(int pos, int val) { table[0][pos] = val; }

  void build() {
    for (int i = 0; i + 1 < lg_; ++i) {
      for (int j = 0; j < int(table[i].size()); ++j) {
        table[i + 1][j] = (table[i][j] == -1 ? -1 : table[i][table[i][j]]);
      }
    }
  }

  int query(int pos, int64 k) {
    for (int i = lg_ - 1; i >= 0; --i) {
      if (k & (1LL << i)) {
        pos = table[i][pos];
      }
    }
    return pos;
  }

 private:
  int n_;
  int lg_;
  std::vector<std::vector<int>> table;
};
// snippet-end
