using T = complex<double>;
const double PI = acos(-1);
struct FFT {
	T w[N];
	FFT() {
		for (int i = 0; i < N; ++i) w[i] = T(cos(2 * PI * i / N), sin(2 * PI * i / N));
	}
	void operator()(vector<T>& a, bool inv = false) {
		int n = sz(a);
		for (int i = 1, j = 0; i < n; ++i) {
			for (int k = n >> 1; (j ^= k) < k; k >>= 1);
			if (i < j) swap(a[i], a[j]);
		}
		for (int L = 1; L < n; L <<= 1)
			for (int i = 0, st = N / (2 * L); i < n; i += 2 * L)
				for (int j = 0; j < L; ++j) {
					T x = a[i + j + L] * w[j * st];
					a[i + j + L] = a[i + j] - x;
					a[i + j] += x;
				}
		if (inv) {
			reverse(1 + all(a));
			T invn = 1.0 / n;
			for (int i = 0; i < n; ++i) a[i] = a[i] * invn;
		}
	}
} ntt;
// after mul, round i.real()
// for (int i = 0; i < m; ++i) a[i] = llround(a[i].real());