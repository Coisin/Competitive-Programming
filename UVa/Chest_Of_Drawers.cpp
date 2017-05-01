#include <bits/stdc++.h>

using namespace std;

int num_drawers, num_secured;
long long dp[10][100][100];

long long process(bool prev, int pos, int num_done) {
	if(pos == num_drawers) return num_done == num_secured;
	if(dp[prev][pos][num_done] != -1) return dp[prev][pos][num_done];

	long long answer = 0;
	if(prev) {
		answer += process(1, pos + 1, num_done + 1) + process(0, pos + 1, num_done);
	} else {
		answer += process(1, pos + 1, num_done) + process(0, pos + 1, num_done);
	}

	return dp[prev][pos][num_done] = answer;
}

int main() {
	cin >> num_drawers >> num_secured;
	while(num_drawers >= 0 && num_secured >= 0) {
		memset(dp, -1, sizeof dp);
		cout << process(1, 0, 0) << endl;
		cin >> num_drawers >> num_secured;
	}
}