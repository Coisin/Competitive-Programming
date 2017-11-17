#include <bits/stdc++.h>

using namespace std;

long long n;

long long choose(long long k) {
	double answer = 1;
	for(int i = 0; i < k; i++) {
		answer *= n - i;
		answer /= i + 1;
	}
	return (long long)ceil(answer);
}

int main() {
	long long k;
	cin >> n >> k;
	long long answer = 1;
	if(k >= 4)
		answer += choose(4) * 9;
	if(k >= 3)
		answer += choose(3) * 2;
	if(k >= 2)
		answer += choose(2) * 1;
	cout << answer << endl;
}