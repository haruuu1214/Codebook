const int p = 1e6 + 3;
const int mod = 1e9 + 7;
int hash(string &s) {
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		res *= p;
		res += s[i] - 'a' + 1;
		res %= mod;
	}
	return res;
}
int pow_p[1000005];
vector <int> rh;
void build(string &s) {
	rh.resize(s.size() + 1);
	pow_p[0] = 1;
	for (int i = 1; i <= s.size(); i++)
		pow_p[i] = (pow_p[i - 1] * p) % mod;
	rh[0] = s[0] - 'a' + 1;
	for (int i = 1; i < s.size(); i++) {
		rh[i] = rh[i - 1] * p + (s[i] - 'a' + 1);
		rh[i] %= mod;
	}
}
int query(int l, int r) {
	int res = rh[r] - (l > 0 ? rh[l - 1] * pow_p[r - l + 1] : 0);
	res = (res % mod + mod) % mod;
	return res;
}