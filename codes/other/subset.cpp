// 枚舉子集，時間複雜度 O(3 ^ n)
for (int i = 0 ; i < (1 << n); i++) {
	for (int m = i; m; m = (m - 1) & i) {
		// m 是 i 的 非 空 子 集
	}
}