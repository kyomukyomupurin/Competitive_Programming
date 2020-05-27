// include __gnu_pbds::tree
// find_by_order(k) : returns an iterator to the k-th largest element(0-origin)
// order_of_key(k)  : returns the number of items in a set that are strictly smaller than k

// snippet-begin
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>

template<class T> 
using pbds_tree = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// snippet-end

// example
//
// pbds_tree<int> tree;
// tree.insert(1);
// tree.insert(2);
// tree.insert(4);
// tree.insert(8);
// tree.insert(16);
//
// cout << *tree.find_by_order(0) << '\n'; // 1
// cout << *tree.find_by_order(2) << '\n'; // 4
// cout << *tree.find_by_order(4) << '\n'; // 16
//
// cout << tree.order_of_key(-1) << '\n';  // 0
// cout << tree.order_of_key(1) << '\n';   // 0
// cout << tree.order_of_key(8) << '\n';   // 3
// cout << tree.order_of_key(100) << '\n'; // 5
//
// cout << distance(tree.begin(), tree.lower_bound(-1)) << '\n';  // 0
// cout << distance(tree.begin(), tree.lower_bound(1)) << '\n';   // 0
// cout << distance(tree.begin(), tree.lower_bound(8)) << '\n';   // 3
// cout << distance(tree.begin(), tree.lower_bound(100)) << '\n'; // 5
