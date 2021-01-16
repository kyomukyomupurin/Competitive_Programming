#include <chrono>

// snippet-begin
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

struct splitmix64_hash {
  // http://xorshift.di.unimi.it/splitmix64.c
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <class Key, class Value, class Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template <class Key, class Hash = splitmix64_hash>
using hash_set = hash_map<Key, __gnu_pbds::null_type, Hash>;

template <class T>
using pbds_tree = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

// find_by_order(k) : returns an iterator to the k-th largest element(0-origin)
// order_of_key(k)  : returns the number of items in a set that are strictly smaller than k
// snippet-end