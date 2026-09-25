// 計算兩個凸多邊形 A、B 之間的最短距離
// 兩者相交或接觸就回傳 0，否則回傳兩者邊界上最近兩點的距離
double convex_hull_dist(vector<Pt> A, vector<Pt> B) {
  Pt O(0, 0); for (auto &p : B) p = O - p;
  auto C = minkowski(A, B); // assert SZ(C) > 0
  if (point_in_convex(C, O)) return 0;
  double ans = point_segment_dist(C.back(), C[0], O);
  for (int i = 0; i + 1 < sz(C); ++i)
    ans = min(ans, point_segment_dist(C[i], C[i + 1], O));
  return ans;
}