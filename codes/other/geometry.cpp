double eps = 0.000001;
pdd operator + (pdd a, pdd b) { return {a.X + b.X, a.Y + b.Y}; }
pdd operator - (pdd a, pdd b) { return {a.X - b.X, a.Y - b.Y}; }
double dot(pdd a, pdd b) { return a.X * b.X + a.Y * b.Y; }
double cross(pdd a, pdd b) { return a.X * b.Y - a.Y * b.X; }
int sign(double x) { return (fabs(x) < eps ? 0 : (x > 0 ? 1 : -1)); }
int ori(pdd a, pdd b, pdd c) { return sign(cross(b - a, c - a)); }
// c is between a and b
bool btw(pdd a, pdd b, pdd c) {
	return (sign(cross(a - c, b - c)) == 0 && sign(dot(a - c, b - c)) <= 0);
}
// ab is touch cd
bool banana(pdd a, pdd b, pdd c, pdd d) {
	int a123 = ori(a, b, c), a124 = ori(a, b, d);
	int a341 = ori(c, d, a), a342 = ori(c, d, b);
	if (btw(a, b, c) || btw(a, b, d) || btw(c, d, a) || btw(c, d, b))
		return true;
	return (a123 * a124 < 0 && a341 * a342 < 0);
}
vector <pdd> convex_hull(vector <pdd> pts) {
	sort(pts.begin(), pts.end());
	pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
	vector <pdd> hull(1, pts[0]);
	for (int t = 0; t < 2; t++) {
		int sz = hull.size();
		for (int i = 1; i < (int)pts.size(); i++) {
			while ((int)hull.size() > sz && ori(hull[(int)hull.size() - 2], hull.back(), pts[i]) < 0)
				hull.pop_back();
			hull.push_back(pts[i]);
		}
		reverse(pts.begin(), pts.end());
	}
	hull.pop_back();
	return hull;
}
double area(vector <pdd> pt) {
	double cnt = 0.0;
	for (int i = 0; i < (int)pt.size() - 1; i++)
		cnt += cross(pt[i], pt[i + 1]);
	cnt += cross(pt[(int)pt.size() - 1], pt[0]);
	return fabs(cnt);
}
void solve() {
	int n;
	cin >> n;
	vector <pdd> pts;
	pts.resize(n);
	for (int i = 0; i < n; i++)
		cin >> pts[i].X >> pts[i].Y;
	int ans = area(convex_hull(pts));
	if (ans % 2 == 1)
		cout << ans / 2 << ".5\n";
	else
		cout << ans / 2 << ".0\n";
}