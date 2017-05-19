#include <bits/stdc++.h>

using namespace std;

int num_cows, num_queries;
int prefix[4][100001];

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	cin >> num_cows >> num_queries;
	for(int i = 1; i <= num_cows; i++) {
		prefix[1][i] += prefix[1][i - 1];
		prefix[2][i] += prefix[2][i - 1];
		prefix[3][i] += prefix[3][i - 1];
		int breed;
		cin >> breed;
		prefix[breed][i]++;
	}
	for(int i = 0; i < num_queries; i++) {
		int a, b;
		cin >> a >> b;
		cout << prefix[1][b] - prefix[1][a - 1] << " "
		 << prefix[2][b] - prefix[2][a - 1] << " "
		 << prefix[3][b] - prefix[3][a - 1] << endl;
	}
}