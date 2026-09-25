const int N = 100005;
vector<int> G[N];
struct HLD {
	vector<int> pa, sz, depth, mxson, topf, id;
	int n, idcnt = 0;
	HLD(int _n) : n(_n), pa(_n + 1), sz(_n + 1), depth(_n + 1), mxson(_n + 1), topf(_n + 1), id(_n + 1) {}
	void dfs1(int v = 1, int p = -1) {
		pa[v] = p; sz[v] = 1; mxson[v] = 0; 
		depth[v] = (p == -1 ? 0 : depth[p] + 1);
		for (int u : G[v]) {
			if (u == p) continue;
			dfs1(u, v);
			sz[v] += sz[u];
			if (sz[u] > sz[mxson[v]]) mxson[v] = u;
		}
	}
	void dfs2(int v = 1, int top = 1) {
		id[v] = ++idcnt;
		topf[v] = top;
		if (mxson[v]) dfs2(mxson[v], top);
		for (int u : G[v]) {
			if (u == mxson[v] || u == pa[v]) continue;
			dfs2(u, u);
		}
	}
	int path_query(int a, int b) {
		int res = 0;
		while (topf[a] != topf[b]) {
			if (depth[topf[a]] < depth[topf[b]]) swap(a, b);
			res = max(res, query(id[topf[a]], id[a])); // query : l = id[topf[a]], r = id[a]
			a = pa[topf[a]];
		}
		if (depth[a] < depth[b]) swap(a, b);
		res = max(res, query(id[b], id[a])); // query : l = id[b], r = id[a]
		return res;
	}
};