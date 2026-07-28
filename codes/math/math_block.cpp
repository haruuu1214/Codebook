// the sum of floor(n / i) for i = 1 ~ n
int f(int n) {
	int ans = 0;
	int l = 1, r = 0;
	while (l <= n) {
		r = n / (n / l);
		ans += (r - l + 1) * (n / l);
		l = r + 1;
	}
	return ans;
}
// the sum of ceil(n / i) for i = 1 ~ n
int f(int n) {
	int ans = 0;
	int l = 1, r = 0;
	while (l < n) {
		r = (n - 1) / ((n - 1) / l);
		ans += (r - l + 1) * ((n + l - 1) / l);
		l = r + 1;
	}
	if (l == n) ans += (n + l - 1) / l;
	return ans;
}