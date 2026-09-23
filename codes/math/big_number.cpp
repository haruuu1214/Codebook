void init(string &a, string &b) {
	while (a.size() < b.size()) a = '0' + a;
	while (a.size() > b.size()) b = '0' + b;
}
int Compare(string &a, string &b) {
	if (a < b) {
		swap(a, b); return -1;
	}
	return 1;
}
bool del(string &a) {
	if (a[0] == '0') {
		a.erase(0, 1); return true;
	}
	return false;
}
void del_all_zero(string &a) {
	while (del(a)) ;
}
string add(string a, string b) {
	init(a, b);
	a = '0' + a; b = '0' + b;
	for (int i = a.size() - 1; i >= 0; i--) {
		int p = a[i] - '0', q = b[i] - '0';
		if (p + q >= 10) {
			a[i - 1] = '0' + (a[i - 1] - '0' + 1);
			a[i] = '0' + (p + q - 10);
		} else {
			a[i] = '0' + (p + q);
		}
	}
	del(a);
	return a;
}
string sub(string a, string b) {
	init(a, b);
	if (a == b) return "0";
	int flag = Compare(a, b);
	for (int i = a.size() - 1; i >= 0; i--) {
		int p = a[i] - '0', q = b[i] - '0';
		if (p < q) {
			a[i - 1] = '0' + (a[i - 1] - '0' - 1);
			a[i] = '0' + (p - q + 10);
		} else {
			a[i] = '0' + (p - q);
		}
	}
	del_all_zero(a);
	if (flag == -1) a = "-" + a;
	return a;
}
string mul(string a, string b) {
	string res = "0";
	init(a, b);
	Compare(a, b);
	del_all_zero(b);
	for (int i = b.size() - 1; i >= 0; i--) {
		int x = b[i] - '0';
		if (i != b.size() - 1) a = a + '0';
		for (int i = 0; i < x; i++)
			res = add(a, res);
	}
	return res;
}
string div(string a, string b) {
	init(a, b);
	if (a < b) return "0";
	del_all_zero(b);
	string res = "0", restmp = "1", tmp = b;
	for (int i = 0; i < (a.size() - b.size()); i++) {
		restmp += '0';
		tmp += '0';
	}
	init(a, b);
	while (a >= b) {
		init(a, tmp);
		if (a >= tmp) {
			a = sub(a, tmp);
			res = add(res, restmp);
		} else {
			restmp.erase(restmp.size() - 1);
			tmp.erase(tmp.size() - 1);
		}
		init(a, b);
	}
	return res;
}