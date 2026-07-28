struct Miller_Rabin {
	static constexpr uint32_t ws32[3] = {2, 7, 61};
	static constexpr uint64_t ws64[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	template <class uint>
	static constexpr uint fast_pow(uint b, uint p, uint mod) {
		using Uint = conditional_t<is_same_v<uint, uint32_t>, uint64_t, __uint128_t>;
		uint ret{1};
		for (; p; p >>= 1) {
			if (p & 1) ret = Uint{ret} * b % mod;
			b = Uint{b} * b % mod;
		}
		return ret;
	}
	template <class uint, class = enable_if_t<is_unsigned_v<uint>>>
	static constexpr bool is_prime(uint n) {
		const auto& witness = []() -> const auto& {
			if constexpr (is_same_v<uint, uint32_t>) return ws32;
			else return ws64;
		}();
		using Uint = conditional_t<is_same_v<uint, uint32_t>, uint64_t, __uint128_t>;
		if (n < 3 || !(n & 1)) return n == 2;
		auto u = n - 1, t = (uint)__builtin_ctzll(u);
		u >>= t;
		for (auto x : witness) {
			auto a = x % n;
			if (a == 0 || a == 1 || a == n - 1) continue;
			auto v = fast_pow(a, u, n);
			uint i = 0;
			for (; v != 1 && v != n - 1 && i < t; i++) v = Uint{v} * v % n;
			if (v != n - 1 && i > 0) return false;
		}
		return true;
	}
	template <class I, class = enable_if_t<is_integral_v<I>>>
	constexpr bool operator()(I x) const {
		if constexpr (is_signed_v<I>) if (x < 0) return false;
		using U = make_unsigned_t<I>;
		return is_prime((U)x);
	}
} is_prime;