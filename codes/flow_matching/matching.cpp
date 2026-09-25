const int N = 2005;
vector <int> G[N];
struct Matching {
	int n;
	vector<bool> vis; vector<int> match;
	Matching(int _n) : n(_n), vis(_n + 1), match(_n + 1, -1) {}
	bool dfs(int v) {
		vis[v] = true;
		for (int u : G[v])
			if (match[u] == -1 || (! vis[match[u]] && dfs(match[u]))) {
				match[u] = v;
				return true;
			}
		return false;
	}
	int solve() {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			vis.assign(n + 1, 0);
			if (dfs(i)) cnt++;
		}
		return cnt;
	}
};