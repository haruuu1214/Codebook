#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,avx2")
#define windows_system
#ifdef windows_system
/* For Windows */
inline int getchar_unlocked() { return getchar(); }
inline void putchar_unlocked(char _c) { putchar(_c); }
#endif
inline int in() {
	int re = 0;
	char c = getchar_unlocked();
	while (c == ' ' || c == '\n') c = getchar_unlocked();
	while (c >= '0' && c <= '9') re = (re << 3) + (re << 1) + c - '0', c = getchar_unlocked();
	return re;
}
inline void out(int x) {
	char str[20];
	int pos = 0;
	do {
		str[pos++] = x % 10 + '0';
		x /= 10;
	} while (x);
	for (int i = pos - 1; i >= 0; i--) putchar_unlocked(str[i]);
	putchar_unlocked('\n');
}