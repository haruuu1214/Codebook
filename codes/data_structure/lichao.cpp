// MIN LeeChao Segment Tree
struct line {
	int m, k;
	line *lc, *rc;
	line() { m = 0, k = INT_MAX, lc = nullptr, rc = nullptr; }
	line(int _m, int _k) { m = _m, k = _k, lc = nullptr, rc = nullptr; }
	int calc(int x) {
		return m * x + k;
	}
	void push(int l, int r) {
		if (l == r) return;
		if (!lc) lc = new line();
		if (!rc) rc = new line();
	}
};
struct Lee_Chao {
	line* root;
	Lee_Chao() : root(new line()) {}
	void update(line* node, int l, int r, line add) {
		if (l == r) {
			if (add.calc(l) < node->calc(l)) {
				swap(add.m, node->m);
				swap(add.k, node->k);
			}
			return;
		}
		// 預設 seg[node] 的斜率 < add 的斜率
		if (node->m > add.m) {
			swap(add.m, node->m);
			swap(add.k, node->k);
		}
		node->push(l, r);
		int mid = (l + r) >> 1;
		// 將小的 f(x) 留下
		if (node->calc(mid) > add.calc(mid)) {
			swap(add.m, node->m);
			swap(add.k, node->k);
			update(node->rc, mid + 1, r, add);
		} else {
			update(node->lc, l, mid, add);
		}
	}
	int query(line* node, int l, int r, int x) {
		if (node->k == INT_MAX) return INT_MAX;
		if (l == r) return node->calc(x);
		int mid = (l + r) >> 1;
		if (x <= mid)
			return min(node->calc(x), query(node->lc, l, mid, x));
		else
			return min(node->calc(x), query(node->rc, mid + 1, r, x));
	}
	void update(line l) { update(root, 1, N, l); }
	int query(int x) { return query(root, 1, N, x); }
};