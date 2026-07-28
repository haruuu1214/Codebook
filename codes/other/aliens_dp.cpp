const int N = 2000005;
int n, k;
int a[N];
pii dp0[N], dp1[N];
pii calc(int c) {
	dp0[1] = {0, 0}; dp1[1] = {c - a[1], 1};
	for (int i = 2; i <= n; i++) {
		dp0[i] = max(dp0[i - 1], dp1[i - 1] + make_pair(+a[i], 0));
		dp1[i] = max(dp1[i - 1], dp0[i - 1] + make_pair(-a[i] + c, 1));
	}
	return dp0[n];
}
void solve() {
	pii p = calc(0);
	if (p.S <= k) {
		cout << p.F << "\n";
		return;
	}
	int l = -1e5, r = 1e6; pii res;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		res = calc(mid);
		if (res.S == k) {
			cout << res.F - mid * k << "\n";
			return;
		} else if (res.S > k)
			r = mid;
		else
			l = mid;
	}
	pii p1 = calc(l), p2 = calc(r);
	int dp_1 = p1.F - l * p1.S;
	int dp_2 = p2.F - r * p2.S;
	cout << (dp_1 + (dp_2 - dp_1) * (k - p1.S) / (p2.S - p1.S)) << "\n";
}