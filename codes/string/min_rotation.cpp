int minRotation(const vector<int>& a) {
    int n = a.size(), i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int x = a[(i + k) % n], y = a[(j + k) % n];
        if (x == y) { k++; continue; }
        if (x > y) i += k + 1;
        else       j += k + 1;
        if (i == j) j++;
        k = 0;
    }
    return min(i, j);
}