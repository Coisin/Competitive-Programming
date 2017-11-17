#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long seq[n];
	for(long long i = 0; i < n; i++) {
		cin >> seq[i];
		if(i > 0)
			seq[i] += seq[i - 1];
	}
	long long div_3 = seq[n - 1] / 3;
	if(seq[n - 1] % 3) {
		cout << 0 << endl;
		return 0;
	}
	long long answer = 0;
	long long num_a = 0;
	for(long long i = 0; i < n - 1; i++) {
		if(seq[i] == div_3 * 2) {
			answer += num_a;
		}
		if(seq[i] == div_3) {
			num_a++;
		}
	}
	cout << answer << endl;
}