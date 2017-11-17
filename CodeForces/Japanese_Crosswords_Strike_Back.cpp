#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		sum += num;
	}
	cout << (sum + n - 1 == l ? "YES" : "NO") << endl;
}