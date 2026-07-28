const int N = 200005;
vector<int> G[N];
int low[N], depth[N];
bool vis[N];
vector<pair<int, int>> bridge;
void dfs(int v, int p) {
	vis[v] = true;
	low[v] = depth[v] = (p == -1 ? 1 : depth[p] + 1);
	for (int u : G[v]) {
		if (u == p) continue;
		if (!vis[u]) {
			// (v, u) 是樹邊
			dfs(u, v);
			low[v] = min(low[v], low[u]);
		} else {
			// (v, u) 是回邊
			low[v] = min(low[v], depth[u]);
		}
	}
	// v 在不依靠父邊的情況下永遠沒辦法走到它的祖先
	// (root, -1) 不算
	if (low[v] == depth[v] && p != -1)
		bridge.push_back({v, p});
}