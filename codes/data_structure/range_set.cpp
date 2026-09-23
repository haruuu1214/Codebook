struct RangeSet { // [l, r)
	set<pii> st;
	void cut(int x) {
		auto it = st.lower_bound({x + 1, -1});
		if (it == st.begin()) return;
		auto [l, r] = *prev(it);
		if (l >= x || x >= r) return;
		st.erase(prev(it));
		st.insert({l, x});
		st.insert({x, r});
	}
	vector<pii> split(int l, int r) {
		// remove and return ranges in [l, r)
		cut(l), cut(r);
		vector<pii> res;
		while (true) {
			auto it = st.lower_bound({l, -1});
			if (it == st.end() || r <= it->first) break;
			res.push_back(*it), st.erase(it);
		}
		return res;
	}
	void insert(int l, int r) {
		// add a range [l, r), [l, r) not in st
		auto it = st.lower_bound({l, r});
		if (it != st.begin() && prev(it)->second == l)
			l = prev(it)->first, st.erase(prev(it));
		if (it != st.end() && r == it->first)
			r = it->second, st.erase(it);
		st.insert({l, r});
	}
	bool count(int x) {
		auto it = st.lower_bound({x + 1, -1});
		return it != st.begin() && prev(it)->first <= x && x < prev(it)->second;
	}
};