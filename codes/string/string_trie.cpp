struct node {
	node* link[26] = {nullptr};
	bool flag = false;
	bool contain_key(char ch) { return (link[ch - 'a'] != nullptr); }
	void put(char ch, node* _node) { link[ch - 'a'] = _node; }
	node* get(char ch) { return link[ch - 'a']; }
	void set_end() { flag = true; }
	bool is_end() { return flag; }
};
struct Trie {
	node* root;
	Trie() { root = new node(); }
	void insert(string s) { // insert a string
		node* now = root;
		for (int i = 0; i < (int)s.size(); i++) {
			if (!now->contain_key(s[i])) now->put(s[i], new node());
			now = now->get(s[i]);
		}
		now->set_end();
	}
    // return if there is a word of the given string
	bool query(string s) {
		node* now = root;
		for (int i = 0; i < (int)s.size(); i++) {
			if (!now->contain_key(s[i])) return false;
			now = now->get(s[i]);
		}
		return now->is_end();
	}
	// return if there is any word that start with the given prefix
	bool query_prefix(string s) {
		node* now = root;
		for (int i = 0; i < (int)s.size(); i++) {
			if (!now->contain_key(s[i])) return false;
			now = now->get(s[i]);
		}
		return true;
	}
};