mt19937 seed(chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(seed);
}
inline double drnd(double l, double r) {
	return uniform_real_distribution<double>(l, r)(seed);
}