namespace number_theory {
	ll gcd(ll x, ll y) {
		if (x == 0) return y;
		if (y == 0) return x;
		return gcd(y, x % y);
	}
	bool isprime(ll n) { 
		if (n <= 1) return false; 
		if (n <= 3) return true; 
		if (n % 2 == 0 || n % 3 == 0) return false; 
		for (ll i = 5; i * i <= n; i += 6) 
			if (n % i == 0 || n % (i+2) == 0) 
				return false; 
		return true; 
	}
	vector<bool>prime(15000105);
	void sieve(int n) { 
		for (ll i = 3; i <= n; i+=2) prime[i] = true;
		for (ll p = 3; p * p <= n; p+=2) { 
			if (prime[p]) { 
				for (ll i = p * p; i <= n; i += p) 
					prime[i] = false; 
				} 
			} 
		prime[0] = prime[1] = false;
	}
	vector<ll> primelist;
	bool __primes_generated__ = 0;
	void genprimes(int n) {
		__primes_generated__ = 1;
		sieve(n + 1);
		primelist.push_back(2);
		for (ll i = 3; i <= n; i+=2) if (prime[i]) primelist.push_back(i);
	}
	vector<ll> factors(ll n) {
		if (!__primes_generated__) {
			cerr << "Call genprimes you dope" << endl;
			exit(1);
		}
		vector<ll> facs;
		for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
			if (n % primelist[i] == 0) {
				while (n % primelist[i] == 0) {
					n /= primelist[i];
					facs.push_back(primelist[i]);
				}
			}
		}
		if (n > 1) {
			facs.push_back(n);
		}
		sort(facs.begin(), facs.end());
		return facs;
	}
	vector<ll> getdivs(ll n) {
		vector<ll> divs;
		for (ll i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				divs.push_back(i);
				divs.push_back(n / i);
			}
		}
		getunique(divs);
		return divs;
	}
	}
	using namespace number_theory;