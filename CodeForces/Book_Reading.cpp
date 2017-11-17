#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	int days;
	for(days = 1; t > 0; days++) {
		int day;
		cin >> day;
		t -= 86400 - day;
	}
	cout << days - 1 << endl;
}