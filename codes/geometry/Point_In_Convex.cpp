// strict: if true, point on edge is considered outside
bool point_in_convex(vector<Pt> &C, Pt p, bool strict = true) {
  // only works when no three points are collinear
  int a = 1, b = sz(C) - 1, r = !strict;
  if (sz(C) == 0) return false;
  if (sz(C) < 3) return r && btw(C[0], C.back(), p);
  if (ori(C[0], C[a], C[b]) > 0) swap(a, b);
  if (ori(C[0], C[a], p) >= r || ori(C[0], C[b], p) <= -r) return false;
  while (abs(a - b) > 1) {
    int c = (a + b) / 2;
    (ori(C[0], C[c], p) > 0 ? b : a) = c;
  }
  return ori(C[a], C[b], p) < r;
}
// 回傳 p 所在的邊 {i, j}
// p 不在邊界上時回傳 {-1, -1}
pair<int, int> point_on_convex_edge(vector<Pt> &C, Pt p) {
  int a = 1, b = sz(C) - 1;
  if (ori(C[0], C[a], C[b]) > 0) swap(a, b);
  if (ori(C[0], C[a], p) == 0 && btw(C[0], C[a], p)) return {0, a};
  if (ori(C[0], C[b], p) == 0 && btw(C[0], C[b], p)) return {0, b};
  if (ori(C[0], C[a], p) > 0 || ori(C[0], C[b], p) < 0) return {-1, -1};
  while (abs(a - b) > 1) {
    int c = (a + b) / 2;
    (ori(C[0], C[c], p) > 0 ? b : a) = c;
  }
  if (ori(C[a], C[b], p) == 0) return {a, b};
  return {-1, -1};
}