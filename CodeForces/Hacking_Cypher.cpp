#include <bits/stdc++.h>

using namespace std;

int main() {
	string number;
	cin >> number;
	long long a, b;
	cin >> a >> b;
	long long n = number.size();
	vector<long long> remainder(n, 0);

	for(long long i = 0; i < n - 1; i++) {
		long long digit = number[i] - '0';
		if(i > 0)
			digit += remainder[i - 1] * 10;
		digit %= a;
		remainder[i] = digit;
	}
	int power[1000001];
	power[0] = 1;
	for(int i = 1; i < 1000001; i++)
		power[i] = (power[i - 1] * 10) % b;

	for(long long i = n - 1; i > 0; i--) {
		long long digit = (number[i] - '0') * power[n - i - 1];
		if(i < n - 1)
			digit += remainder[i + 1];
		digit %= b;
		remainder[i] = digit;
		if(remainder[i - 1] == 0 && remainder[i] == 0 && number[i] != '0') {
			cout << "YES" << endl;
			cout << number.substr(0, i) << endl;
			cout << number.substr(i) << endl;
			exit(0);
		}
	}
	cout << "NO" << endl;
}