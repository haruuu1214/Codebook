struct frac {
	int a, b;
	frac(int _a = 0, int _b = 1) : a(_a), b(_b) {
		int g = __gcd(a, b);
		a /= g; b /= g;
		if (b < 0) { a *= -1; b *= -1; }
	}
};
frac operator+(frac x, frac y) { return frac(x.a * y.b + y.a * x.b, x.b * y.b); }
frac operator-(frac x, frac y) { return frac(x.a * y.b - y.a * x.b, x.b * y.b); }
frac operator*(frac x, frac y) { return frac(x.a * y.a, x.b * y.b); }
frac operator/(frac x, frac y) { return frac(x.a * y.b, x.b * y.a); }
bool operator>(frac x, frac y) { return x.a * y.b > y.a * x.b; }
bool operator<(frac x, frac y) { return x.a * y.b < y.a * x.b; }
bool operator>=(frac x, frac y) { return x.a * y.b >= y.a * x.b; }
bool operator<=(frac x, frac y) { return x.a * y.b <= y.a * x.b; }
bool operator==(frac x, frac y) { return x.a * y.b == y.a * x.b; }
frac abs(frac x) { return frac(abs(x.a), abs(x.b)); }
ostream& operator<<(ostream &os, const frac& x) { os << x.a << "/" << x.b; return os; }