// 原題：計算 [l, r] 中兩兩相鄰數字不同的數字數量
// 注意邊界
int dp[20][10]; // i 位數，尾數是 j
void init() {
	for (int j = 0; j <= 9; j++) dp[1][j] = 1;
	for (int i = 2; i <= 18; i++)
		for (int now = 0; now <= 9; now++) // 這個位數的數字
			for (int pre = 0; pre <= 9; pre++) // 上個位數的數字
				if (now != pre)
					dp[i][now] += dp[i - 1][pre];
}
int calc(int x) { // 小於等於 x 的數量
	if (x == 0) return 0;
	int arr[20] = {}, len = 0;
	while (x > 0) arr[++len] = x % 10, x /= 10;
	// 計算 len 位數 的數量
	int cnt = 0, pre = -1;
	for (int idx = len; idx >= 1; idx--) {
		for (int now = (idx == len); now < arr[idx]; now++)
			if (now != pre)
				cnt += dp[idx][now];
		if (arr[idx] == pre) break;
		pre = arr[idx];
		if (idx == 1) cnt++; // 特判
	}
	// 計算 小於 len 位數 的數量
	for (int i = 1; i < len; i++)
		for (int j = 1; j <= 9; j++)
			cnt += dp[i][j];
	return cnt;
}