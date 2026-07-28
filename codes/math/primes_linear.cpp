// Time Complexity : O(n)
// if lpf(i) = i, then it means that i is a prime.
// else lpf(i) is the smallest prime factor.
// The 199999-th of the prime is 2750131
bool is_prime[2750135];
int lpf[2750135];
vector<int> primes;
void init() {
	fill(is_prime, is_prime + 2750135, true);
	for (int i = 2; i <= 2750131; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			lpf[i] = i;
		}
		for (int p : primes) {
			if (p * i > 2750131) break;
			is_prime[p * i] = false;
			lpf[p * i] = p;
			if (i % p == 0) break;
		}
	}
}