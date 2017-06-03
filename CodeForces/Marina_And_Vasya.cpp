#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	string a, b;
	cin >> a >> b;
	string c = "";
	int differ_counter = a.size();
	for(int i = 0; i < n; i++) {
		if(a[i] != 'a' && b[i] != 'a')
			c += 'a';
		else if(a[i] != 'b' && b[i] != 'b')
			c += 'b';
		else if(a[i] != 'c' && b[i] != 'c')
			c += 'c';
	}
	int a_counter = n;
	int b_counter = n;
	for(int i = 0; i < n && a_counter - t && b_counter - t; i++) {
		if(a[i] == b[i]) {
			a_counter--, b_counter--;
			c[i] = a[i];
		}
	}
	for(int i = 0; i < n && a_counter - t; i++) {
		if(a[i] != b[i]) {
			a_counter--;
			c[i] = a[i];
		}
	}
	for(int i = 0; i < n && b_counter - t; i++) {
		if(a[i] != b[i] && c[i] != a[i]) {
			b_counter--;
			c[i] = b[i];
		}
	}
	if(a_counter - t) cout << -1 << endl;
	if(b_counter - t) cout << -1 << endl;
	else cout << c << endl;
}