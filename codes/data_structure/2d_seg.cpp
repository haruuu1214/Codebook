struct Node {
	int x;
	Node(int _x = 0) : x(_x) {}
};
Node combine(Node a, Node b) {
	return Node(max(a.x, b.x));
}
struct Segment_Tree {
	struct Segment_Tree2 {
		vector<Node> seg2;
		int n;
		Segment_Tree2(int _n) : n(_n), seg2(4 * _n + 5) {}
		void update2(int node, int l, int r, int id, int va) {
			if (l == r) {
				seg2[node].x = va;
				return;
			}
			int mid = (l + r) >> 1;
			if (id <= mid)
				update2((node << 1), l, mid, id, va);
			else
				update2(((node << 1) | 1), mid + 1, r, id, va);
			seg2[node] = combine(seg2[node << 1], seg2[(node << 1) | 1]);
		}
		Node query2(int node, int l, int r, int ql, int qr) {
			if (ql <= l && r <= qr) return seg2[node];
			int mid = (l + r) >> 1;
			if (qr <= mid)
				return query2((node << 1), l, mid, ql, qr);
			else if (mid + 1 <= ql)
				return query2(((node << 1) | 1), mid + 1, r, ql, qr);
			else
				return combine(query2((node << 1), l, mid, ql, qr), query2(((node << 1) | 1), mid + 1, r, ql, qr));
		}
	};
	vector<Segment_Tree2> seg;
	int n;
	Segment_Tree(int _n) : n(_n), seg(4 * _n + 5, Segment_Tree2(_n)) {}
	void update(int node, int l, int r, int x, int y, int va) {
		seg[node].update2(1, 1, n, y, va);
		if (l == r) return;
		int mid = (l + r) >> 1;
		if (x <= mid)
			update((node << 1), l, mid, x, y, va);
		else
			update(((node << 1) | 1), mid + 1, r, x, y, va);
	}
	Node query(int node, int l, int r, int xl, int xr, int yl, int yr) {
		if (xl <= l && r <= xr) return seg[node].query2(1, 1, n, yl, yr);
		int mid = (l + r) >> 1;
		if (xr <= mid)
			return query((node << 1), l, mid, xl, xr, yl, yr);
		else if (mid + 1 <= xl)
			return query(((node << 1) | 1), mid + 1, r, xl, xr, yl, yr);
		else
			return combine(query((node << 1), l, mid, xl, xr, yl, yr), query(((node << 1) | 1), mid + 1, r, xl, xr, yl, yr));
	}
};