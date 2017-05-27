#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	for(int i = 1; a >= 0 && b >= 0; i++) {
		if(i % 2) {
			a -= i;
		} else b -= i;
	}
	cout << (a < 0 ? "Vladik" : "Valera") << endl;
}