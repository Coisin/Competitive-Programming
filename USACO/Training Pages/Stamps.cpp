/*

TASK: stamps
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int max_depth, num_types;
vector<int> coins;

int dp[2000001];

int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);

	cin >> max_depth >> num_types;
	coins.resize(num_types);
	for(int i = 0; i < num_types; i++)
		cin >> coins[i];
	sort(coins.begin(), coins.end());

	int a;
	dp[0] = 0;
	for(a = 1; a <= 2000000; a++) {
		dp[a] = 1000000000;
		for(int c : coins) {
			if(c > a) break;
			dp[a] = min(dp[a], dp[a - c] + 1);
		}
		if(dp[a] > max_depth) break;
	}
	cout << (a - 1) << endl;
}