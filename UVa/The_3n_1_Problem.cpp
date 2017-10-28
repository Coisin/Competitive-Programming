#include <bits/stdc++.h>

using namespace std;

long long cycle_length(long long a) {
	long long length;
	for(length = 1; a != 1; length++, a = a & 1 ? (a * 3) + 1 : a / 2);
	return length;
}

int main() {
	long long i, j;
	while(scanf("%lld %lld", &i, &j) != EOF) {
		long long a, max_cycle;
		for(a = min(i, j), max_cycle = -1; a <= max(i, j); a++, max_cycle = max(max_cycle, cycle_length(a - 1)));
		printf("%lld %lld %lld\n", i, j, max_cycle);
	}
}