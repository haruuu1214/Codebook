#define int long long
const int N = 25;
frac co[N][N];
// SIZE = n * (n + 1)
// a_1 x_1 + a_2 x_2 + ... + a_n * x_n = a_{n + 1}
void gaussian(int n) {
  for (int i = 1; i <= n; i++) {
    if (co[i][i].a == 0 && co[i][i].b == 1) { // swap
      int swapid = -1;
      for (int id = i + 1; id <= n; id++) {
        if (! (co[id][i].a == 0 && co[id][i].b == 1)) {
          swapid = id; break;
        }
      }
      if (swapid == -1)
        continue;
      else {
        for (int j = 1; j <= n + 1; j++)
          swap(co[i][j], co[swapid][j]);
      }
    }
    for (int id = i + 1; id <= n; id++) {
      if (! (co[id][i].a == 0 && co[id][i].b == 1)) {
        frac mul = co[id][i] / co[i][i];
        for (int j = 1; j <= n + 1; j++)
          co[id][j] = co[id][j] - co[i][j] * mul;
      }
    }
  }

  for (int i = n; i >= 1; i--) {
    if (! (co[i][i].a == 0 && co[i][i].b == 1)) {
      co[i][n + 1] = co[i][n + 1] / co[i][i];
      co[i][i] = {1, 1};
    } else
      continue;
    for (int id = 1; id < i; id++) {
      if (! (co[id][i].a == 0 && co[id][i].b == 1)) {
        frac mul = co[id][i] / co[i][i];
        for (int j = 1; j <= n + 1; j++)
          co[id][j] = co[id][j] - co[i][j] * mul;
      }
    }
  }
  bool check_inf = false, check_no = false;
  for (int i = 1; i <= n; i++) {
    bool allzro = true;
    for (int j = 1; j <= n; j++)
      if (! (co[i][j].a == 0 && co[i][j].b == 1))
        allzro = false;
    if (allzro) {
      if (! (co[i][n + 1].a == 0 && co[i][n + 1].b == 1))
        check_no = true;
      else
        check_inf = true;
    }
  }
  if (check_no) {
    cout << "no solutions\n";
  } else if (check_inf) {
    cout << "infinite many solutions\n";
  } else {
    for (int i = 1; i <= n; i++)
      cout << "X" << i << " = " << co[i][n + 1] << '\n';
  }
}