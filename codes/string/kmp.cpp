vector <int> F;
void build_failure_function(string &s) {
	F.clear();
	F.resize(s.size(), -1);
	for (int i = 1; i < s.size(); i++) {
		int j = F[i - 1];
		while (j != -1 && s[i] != s[j + 1])
			j = F[j];
		if (s[i] == s[j + 1])
			F[i] = j + 1;
	}
}
void KMP_matching(string &a, string &b) {
	// i -> a 的指針， j -> b 的指針
	for (int i = 0, j = -1; i < a.size(); i++) {
		while (j != -1 && a[i] != b[j + 1]) // 匹配失敗
			j = F[j];
		if (a[i] == b[j + 1]) // 匹配成功
			j++;
		if (j + 1 == b.size()) { // 找到了，當作匹配失敗 重新匹配 找下一個
			cout << "found a matching start at " << i - j << "\n";
			j = F[j];
		}
	}
}