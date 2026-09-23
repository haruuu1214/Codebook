#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
void solve() {
	tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> bst;
	bst.insert(1);
	int a = *bst.find_by_order(2); // 第 k + 1 大的數
	int b = bst.order_of_key(2);   // 有幾個數 > k
	// ------------------------------------------------
	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> bst;
	bst.insert(1);
	int a = *bst.find_by_order(2); // 第 k + 1 小的數
	int b = bst.order_of_key(2);   // 有幾個數 < k
}