#include <bits/stdc++.h>

using namespace std;

int _sieve_size;
bitset<5000010> bs;
vector<long long> primes;
vector<int> prefix_array, factors;

void generate_sieve(int size) {
	bs.set();
	_sieve_size = size;
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= _sieve_size; i++) {
		if(bs[i]) {
			for(long long j = i * i; j <= _sieve_size; j += i) {
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

void build_values() {
	prefix_array.assign(_sieve_size, 0);
	factors.assign(_sieve_size, 0);
	for(long long prime : primes) {
		factors[prime] = 1;
		long long i = prime + prime;
		while(i < _sieve_size) {
			long long current_num = i;
			while(current_num % prime == 0) {
				factors[i]++;
				current_num /= prime;
			}
			i += prime;
		}
	}
	for(int i = 0; i <= _sieve_size; i++)
		prefix_array[i] = factors[i] + (i > 0 ? prefix_array[i - 1] : 0);
}

int main() {
	generate_sieve(5000001);
	build_values();
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", prefix_array[a] - prefix_array[b]);
	}
}