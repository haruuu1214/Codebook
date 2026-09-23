vector<int> G[N];
int spfa(int n, int s, int t) {
	vector<int> dis(n, INT_MAX), cnt(n);
	vector<bool> inq(n);
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	inq[s] = true;
	while (q.size()) {
		int u = q.front();
		q.pop();
		cnt[u]++;
		if (cnt[u] == n) // negative cycle
			return INT_MAX;
		inq[u] = false;
		for (auto [v, w] : G[u]) {
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	return dis[t];
}