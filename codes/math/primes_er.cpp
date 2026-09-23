// Time Complexity : O(nloglogn)
const int N = 200005;
bool is_prime[N];
vector <int> primes;
void build() {
	fill(is_prime, is_prime + N, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= 200000; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			if (1ll * i * i <= 200000)
				for (int j = i * i; j <= 200000; j += i)
					is_prime[j] = false;
		}
	}
}