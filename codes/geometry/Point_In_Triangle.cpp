// S: 點集（排序、去重）
// dirs[i]: 所有 p > S[i] 的向量 p - S[i]，依極角排序
// 這些向量都落在半平面 (x > 0 或 x == 0 && y > 0)，所以用外積比較是合法的全序
vector<Pt> S;
vector<vector<Pt>> dirs;
int id(Pt p) { return lower_bound(all(S), p) - S.begin(); }
void init(vector<Pt> pts) {
  S = pts; sort(all(S)); S.erase(unique(all(S)), S.end());
  int n = sz(S); dirs.assign(n, {});
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) dirs[i].push_back(S[j] - S[i]);
    sort(all(dirs[i]), [](Pt u, Pt v) { return (u ^ v) > 0; });
  }
}
// q 必須在 S 裡；在所有 p > q 中，數 (d ^ (p - q)) < 0 與 == 0 的個數
pair<int, int> cnt(Pt q, Pt d) {
  auto &v = dirs[id(q)];
  auto cmp = [](Pt u, Pt w) { return (u ^ w) > 0; };
  auto lo = lower_bound(all(v), d, cmp), hi = upper_bound(all(v), d, cmp);
  return {int(lo - v.begin()), int(hi - lo)};
}
// check if this number is calculated（p 本身是不是點集裡的點）
bool check(Pt p) { int i = id(p); return i < sz(S) && S[i] == p; }
// number of points p with a < p < b such that ori(p, a, b) < 0
int under(Pt a, Pt b) {
  Pt d = b - a;
  return cnt(a, d).first - cnt(b, d).first;
}
// number of points with a < p < b and ori(p, a, b) = 0
int edge(Pt a, Pt b) {
  Pt d = b - a;
  return cnt(a, d).second - cnt(b, d).second - check(b);
}
// number of points that strictly inside the triangle
int in_tri(array<Pt, 3> arr) {
  sort(all(arr), [&](Pt i, Pt j) {
    return i.x == j.x ? i.y < j.y : i.x < j.x; });
  auto [a, b, c] = arr;
  int x = ori(b, a, c);
  if (x == 0) return 0;
  if (x == 1) return under(a, b) + under(b, c) - under(a, c) - edge(a, c);
  return under(a, c) - under(a, b) - under(b, c) - edge(a, b) - edge(b, c) - check(b);
}
int main() {
  int n; cin >> n;
  vector<Pt> pts(n);
  for (auto &p : pts) cin >> p.x >> p.y;
  init(pts);
  int q; cin >> q;
  while (q--) {
    int i, j, k; cin >> i >> j >> k;  // 三個頂點在輸入中的編號（0-indexed）
    cout << in_tri({pts[i], pts[j], pts[k]}) << '\n';
  }
}