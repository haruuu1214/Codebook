const int N = 200005;
vector<int> G[N];
int low[N], depth[N];
bool vis[N], cut[N];
void dfs(int v, int p) {
	vis[v] = true;
	int child = 0;
	low[v] = depth[v] = (p == -1 ? 1 : depth[p] + 1);
	for (int u : G[v]) {
		if (u == p) continue;
		if (!vis[u]) {
			// (v, u) 是樹邊
			dfs(u, v);
			child++;
			low[v] = min(low[v], low[u]);
			// u 無法在不經過父邊的情況走到 v 的祖先
			if (low[u] >= depth[v] && p != -1)
				cut[v] = true;
		} else {
			// (v, u) 是回邊
			low[v] = min(low[v], depth[u]);
		}
	}
	// 根節點有超過 2 個子節點
	if (p == -1 && child >= 2)
		cut[v] = true;
}