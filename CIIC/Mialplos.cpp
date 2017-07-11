#include <bits/stdc++.h>

using namespace std;

int ar[50002][102];
int seq[50002];

int main() {
	int num_elements, mod, q;
	cin >> num_elements >> mod >> q;
	ar[0][0]++;
	for(int i = 1; i <= num_elements; i++) {
		seq[i] = seq[i - 1];
		for(int j = 0; j < mod; j++) {
			ar[i][j] =  ar[i - 1][j];
		}
		int a;
		cin >> a;
		seq[i] += a;
		seq[i] %= mod;
		ar[i][seq[i]]++;
	}
	for(int j = 1; j <= q; j++) {
		int l, r;
		cin >> l >> r;
		long long answer = 0;
		for(int i = 0; i < mod; i++) {
			int a = ar[r][i] - (l == 1 ? 0 : ar[l - 2][i]);
			answer += (a * (a - 1)) / 2;
		}
		cout << answer << endl;
	}
}