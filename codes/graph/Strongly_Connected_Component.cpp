const int N = 200005;
vector<int> G[N], rev_G[N], order;
bool vis[N]; int scc[N];
void rev_dfs(int v) {
	vis[v] = true;
	for (int u : rev_G[v])
		if (!vis[u])
			rev_dfs(u);
	order.push_back(v);
}
void dfs(int v, int block) {
	scc[v] = block;
	for (int u : G[v])
		if (scc[u] == -1)
			dfs(u, block);
}
void kosaraju(int n) {
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			rev_dfs(i);
	int scc_cnt = 0;
	fill(scc, scc + N, -1);
	for (int i = n - 1; i >= 0; i--)
		if (scc[order[i]] == -1)
			dfs(order[i], ++scc_cnt);
}