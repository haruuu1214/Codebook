// 判斷點是否在多邊形內
// -1: 在外面
//  0: 在邊上（只有 strict = 1 時會出現）
//  1: 在裡面 (strict = 0 時，在邊上也回傳 1)
// -1: out, 0: edge, 1: in
int point_in_poly(vector <Pt> poly, Pt o, int strict) {
  int cnt = 0;
  for (int i = 0; i < sz(poly); ++i) {
    Pt a = poly[i], b = poly[(i + 1) % sz(poly)];
    if (btw(o, a, b)) return !strict;
    cnt ^= ((o.y < a.y) - (o.y - b.y)) * ori(o, a, b) > 0;
  }
  return cnt ? 1 : -1;
}