template<int SZ> struct Sieve { 
	bitset<SZ> is_prime; vector<int> primes;
	Sieve() {
		is_prime.set(); is_prime[0] = is_prime[1] = 0;
		for (int i = 4; i < SZ; i += 2) is_prime[i] = 0;
		for (int i = 3; i*i < SZ; i += 2) if (is_prime[i])
			for (int j = i*i; j < SZ; j += i*2) is_prime[j] = 0;
		for(int i = 0; i < SZ; i++) if (is_prime[i]) primes.push_back(i);
	}
};
// Usage:
// Sieve<10000000> sieve;
// if(sieve.is_prime.test(sum) == 1)
