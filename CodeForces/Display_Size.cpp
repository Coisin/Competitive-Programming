#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans_r, ans_c;
	ans_r = -1;
	ans_c = 1000000000;
	for(int r = 1; r <= n; r++) {
		int c = n / r;
		if(n % r == 0 && ans_c - ans_r > r - c) {
			if(c < r) break;
			ans_r = r;
			ans_c = c;
		}
	}
	cout << ans_r << " " << ans_c << endl;
}