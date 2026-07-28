string s;
int extend(int l, int r, int N) {
	int i = 0;
	while (l - i >= 0 && r + i < N && s[l - i] == s[r + i])
		i++;
	return i;
}
int Longest_Palindromic_Substring(string &t) {
	int N = t.length();
	s.resize(2 * N + 1, '$');
	for (int i = 0; i < N; i++)
		s[2 * i + 1] = t[i];
	N = 2 * N + 1;
	vector <int> res;
	res.resize(N, 0);
	res[0] = 1;
	for (int i = 1, mid = 0, R = 0; i < N; i++) {
		int j = mid - (i - mid);
		int lst = R + 1 - i;
		if (i > R) {
			res[i] = extend(i, i, N);
			mid = i;
			R = i + res[i] - 1;
		} else if (res[j] == lst) {
			res[i] = lst + extend(i - R, i + R, N);
			mid = i;
			R = i + res[i] - 1;
		} else {
			res[i] = min(res[j], lst);
		}
	}
	int mx = -1, idx = -1;
	for (int i = 0; i < N; i++) {
		if (res[i] > mx) {
			mx = res[i];
			idx = i;
		}
	}
	cout << "Longest Palindromic Substring Length is " << (mx + 1) / 2 << "\n";
	for (int i = idx - res[idx] + 1; i <= idx + res[idx] + 1; i++)
		if (i & 1)
			cout << s[i];
	cout << "\n";
}