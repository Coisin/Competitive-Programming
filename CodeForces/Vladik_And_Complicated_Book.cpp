#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> numbers(n);
	for(int i = 0; i < n; i++)
		cin >> numbers[i];
	for(int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		l--, r--, x--;
		int less_than = 0;
		for(int i = l; i <= r; i++)
			if(numbers[i] < numbers[x])
				less_than++;
		cout << (less_than + l == x ? "Yes" : "No") << endl;
	}
}