#include <bits/stdc++.h>

using namespace std;

int num_units, num_bars, largest_bar;
long long dp[55][55][2];

long long process(int pos, int bars_left, int prev) {
	if(pos == num_units) return bars_left == 0;
	if(pos > num_units) return 0;
	if(dp[pos][bars_left][prev] != -1) return dp[pos][bars_left][prev];

	long long answer = 0;
	for(int i = 1; i <= largest_bar; i++)
		answer += process(pos + i, bars_left - 1, 1 - prev);

	return dp[pos][bars_left][prev] = answer;
}

int main() {
	while(scanf("%d %d %d", &num_units, &num_bars, &largest_bar) != EOF) {
		memset(dp, -1, sizeof dp);
		cout << process(0, num_bars, 0) << endl;
	}
}