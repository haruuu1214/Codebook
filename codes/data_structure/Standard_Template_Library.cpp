struct Data {
	int x, y;
};
// priority_queue
struct cmp {
	bool operator()(Data a, Data b) {
		return a.x < b.x;
	}
};
priority_queue<Data, vector<Data>, cmp> pq;
// set
struct cmp {
	bool operator() (Data p, Data q) {
		return p.x < q.x;
	}
};
set<Data, cmp> st;