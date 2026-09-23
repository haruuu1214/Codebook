const int N = 3005;
int n, k, a[N], pre[N], dp[N][N];
int cost(int l, int r) {}
void dc(int j, int l, int r, int best_l, int best_r) {
	if (l > r) return;
	int mid = (l + r) >> 1, pos = 1;
	for (int i = best_l; i <= best_r; i++) {
		if (dp[i][j - 1] + cost(i + 1, mid) < dp[mid][j]) {
				pos = i;
				dp[mid][j] = dp[i][j - 1] + cost(i + 1, mid);
		}
	}
	dc(j, l, mid - 1, best_l, pos);
	dc(j, mid + 1, r, pos, best_r);
}
void solve() {
	for (int i = 1; i <= n; i++)
		dp[i][1] = pre[i] * pre[i];
	for (int j = 2; j <= k; j++)
		dc(j, j, n, j - 1, n);
}