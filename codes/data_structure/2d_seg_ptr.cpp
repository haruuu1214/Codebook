struct Node2 {
	int val; Node2 *lc, *rc;
	Node2 () {
		val = 0;
		lc = rc = nullptr;
	}
};
struct Node1 {
	Node2 *c; Node1 *lc, *rc;
	Node1 () {
		c = nullptr;
		lc = rc = nullptr;
	}
};
int N;
int Val2(Node2 *n2) { return (n2 ? n2->val : 0ll); }
void pull2(Node2 *n2) { n2->val = Val2(n2->lc) + Val2(n2->rc); }
void update2(Node2 *n2, int l, int r, int id, int v) {
	if (l == r) {
		n2->val += v; return;
	}
	int mid = (l + r) >> 1;
	if (id <= mid) {
		if (!n2->lc) n2->lc = new Node2();
		update2(n2->lc, l, mid, id, v);
	} else {
		if (!n2->rc) n2->rc = new Node2();
		update2(n2->rc, mid + 1, r, id, v);
	}
	pull2(n2);
}
void update1(Node1 *n1, int l, int r, int qx, int qy, int v) {
	if (!n1->c) n1->c = new Node2();
	update2(n1->c, 1, N, qy, v);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (qx <= mid) {
		if (!n1->lc) n1->lc = new Node1();
		update1(n1->lc, l, mid, qx, qy, v);
	} else {
		if (!n1->rc) n1->rc = new Node1();
		update1(n1->rc, mid + 1, r, qx, qy, v);
	}
}
int query2(Node2 *n2, int l, int r, int ql, int qr) {
	if (!n2) return 0;
	if (ql <= l && r <= qr) return n2->val;
	int mid = (l + r) >> 1;
	if (qr <= mid)
		return query2(n2->lc, l, mid, ql, qr);
	else if (mid + 1 <= ql)
		return query2(n2->rc, mid + 1, r, ql, qr);
	else
		return query2(n2->lc, l, mid, ql, qr) + query2(n2->rc, mid + 1, r, ql, qr);
}
int query1(Node1 *n1, int l, int r, int qxl, int qxr, int qyl, int qyr) {
	if (!n1) return 0;
	if (qxl <= l && r <= qxr) return query2(n1->c, 1, N, qyl, qyr);
	int mid = (l + r) >> 1;
	if (qxr <= mid)
		return query1(n1->lc, l, mid, qxl, qxr, qyl, qyr);
	else if (mid + 1 <= qxl)
		return query1(n1->rc, mid + 1, r, qxl, qxr, qyl, qyr);
	else
		return query1(n1->lc, l, mid, qxl, qxr, qyl, qyr) + query1(n1->rc, mid + 1, r, qxl, qxr, qyl, qyr);
}