int a[N];
struct Sparse_table {
	int n;
	vector<vector<int>> st;
	Sparse_table(int _n) : n(_n), st(_n + 1, vector<int>(__lg(_n) + 1)) {
		for (int i = 1; i <= n; i++) st[i][0] = a[i];
		for (int lg = 1; lg <= __lg(n); lg++) {
			int len = 1 << (lg - 1);
			for (int i = 1; i + len <= n; i++)
				st[i][lg] = max(st[i][lg - 1], st[i + len][lg - 1]);
		}
	}
	int query(int l, int r) {
		int lg = __lg(r - l + 1);
		int len = 1 << lg;
		return max(st[l][lg], st[r - len + 1][lg]);
	}
};