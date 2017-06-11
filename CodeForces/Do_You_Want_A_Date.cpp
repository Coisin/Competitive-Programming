#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

long long to_power(long long power, long long subject) {
	if(power == 1) return subject;
	if(power % 2 == 0) {
		long long x = to_power(power / 2, subject);
		return ((x % mod) * x) % mod;
	}
	return ((subject % mod) * to_power(power - 1, subject)) % mod;
}

int main() {
	long long num_elements;
	cin >> num_elements;
	long long sequence[num_elements];
	for(long long i = 0; i < num_elements; i++)
		cin >> sequence[i];
	sort(sequence, sequence + num_elements);
	long long answer = 0;
	for(long long i = 0; i < num_elements - 1; i++) {
		long long difference = sequence[i + 1] - sequence[i];
		difference %= mod;
		long long to_left = i + 1;
		long long to_right = (num_elements - i) - 1;
		long long sets_to_left = to_power(to_left, 2) - 1;
		long long sets_to_right = to_power(to_right, 2) - 1;
		answer += (((difference * sets_to_left) % mod) * sets_to_right) % mod;
	}
	answer %= mod;
	cout << answer << endl;
}