#include <bits/stdc++.h>

using namespace std;

int main() {
	long long current_year;
	cin >> current_year;

	long long ten_mul = log10(current_year);
	long long answer;
	if(pow(10, ten_mul) * 9 > current_year)
		answer = pow(10, ten_mul) - (current_year % (long long)pow(10, ten_mul));
	else
		answer = pow(10, ten_mul + 1) - current_year;
	cout << answer << endl;
}