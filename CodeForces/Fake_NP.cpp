#include <bits/stdc++.h>

using namespace std;

int left_bound, right_bound;

int main() {
	cin >> left_bound >> right_bound;
	int answer;
	if(left_bound == right_bound) answer = left_bound;
	else if(right_bound - (left_bound - 1) == 3) {
		int gcd = __gcd(left_bound, right_bound);
		answer = gcd == 1 ? 2 : gcd;
	} else answer = 2;
	cout << answer << endl;
}