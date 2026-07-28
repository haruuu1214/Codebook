struct BIT {
  int N;
  vector<int> info;
  BIT(int n) : N(n), info(n + 1) {}
  void update(int idx, int val) {
    for (int i = idx; i <= N; i += i & -i)
      info[i] += val;
  }
  int query(int idx) {
    int res = 0;
    for (int i = idx; i > 0; i -= i & -i)
      res += info[i];
    return res;
  }
  int kth(int k) { // kth small
    int res = 0;
    for (int i = 1 << __lg(N); i > 0; i >>= 1) {
      if (res + i <= N && info[res + i] < k) {
        res += i;
        k -= info[res];
      }
    }
    return res + 1;
  }
};