struct Flow {
	struct Edge {
		// rc : residual capcity
		int u, rc, rev;
	};
	vector<vector<Edge>> G;
	vector<int> dis, it;
	Flow(int n) : G(n), dis(n), it(n) {}
	void add(int v, int u, int c) {
		G[v].push_back({u, c, sz(G[u])});
		G[u].push_back({v, 0, sz(G[v]) - 1});
	}
	int dfs(int v, int t, int f) {
		if (v == t || f == 0) return f;
		for (int &i = it[v]; i < sz(G[v]); i++) {
			auto &[u, rc, rev] = G[v][i];
			if (dis[u] != dis[v] + 1) continue;
			int res = dfs(u, t, min(f, rc));
			if (res <= 0) continue;
			rc -= res;
			G[u][rev].rc += res;
			return res;
		}
		return 0;
	}
	int flow(int s, int t) {
		int ans = 0;
		for (int l = 30; l >= 0; l--) while (true) {
			fill(all(dis), INT_MAX);
			queue<int> Q;
			Q.push(s);
			dis[s] = 0;
			while (! Q.empty()) {
				int v = Q.front(); Q.pop();
				for (auto [u, rc, rev] : G[v]) {
					if ((rc >> l) <= 0 || dis[u] < INT_MAX) continue;
					dis[u] = dis[v] + 1;
					Q.push(u);
				}
			}
			if (dis[t] == INT_MAX) break;

			fill(all(it), 0);
			while (true) {
				int res = dfs(s, t, INT_MAX);
				if (res <= 0) break;
				ans += res;
			}
		}
		return ans;
	}
};