struct DSU {
	vector<int> parent, size, tag;
	vector<tuple<int, int, int, int, int>> history;
	DSU(int n) {
			parent.resize(n + 1);
			size.resize(n + 1, 1);
			tag.resize(n + 1, 0);
			for (int i = 1; i <= n; i++) parent[i] = i;
	}
	int find(int x) {
			if (parent[x] == x) return x;
			return find(parent[x]);
	}
	bool merge(int x, int y) {
			x = find(x), y = find(y);
			if (x == y) return false;
			if (size[x] < size[y]) swap(x, y);
			history.pb({x, y, parent[y], tag[x], size[x]});
			parent[y] = x;
			size[x] += size[y];
			return true;
	}
	void add_tag(int head, int val) {
			tag[head] += val;
	}
	void undo() {
			auto [px, py, parent_py, base, sz_x] = history.back();
			parent[py] = parent_py;
			size[px] = sz_x;
			int delta = tag[px] - base;
			tag[py] += delta;
			history.pop_back();
	}
};