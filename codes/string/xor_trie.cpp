struct node {
	node* link[2];
	bool contain_key(int val) { return (link[val] != nullptr); }
	node* get(int val) { return link[val]; }
	void put(int val, node* _node) { link[val] = _node; }
};
struct Trie {
	node* root;
	Trie() { root = new node(); }
	void update(int x) {
		node* now = root;
		for (int i = 30; i >= 0; i--) {
			if (x & (1 << i)) {
				if (!now->contain_key(1)) now->put(1, new node());
				now = now->get(1);
			} else {
				if (!now->contain_key(0)) now->put(0, new node());
				now = now->get(0);
			}
		}
	}
	int query(int x) { // query max xor with number x
		node* now = root;
		int mx = 0;
		for (int i = 30; i >= 0; i--) {
			int nowbit = (x >> i) & 1;
			int target = nowbit ^ 1;
			if (now->contain_key(target)) {
				mx += (1 << i);
				now = now->get(target);
			} else {
				now = now->get(nowbit);
			}
		}
		return mx;
	}
};