/*

PROB: nocows
LANG: C++11

 */

#include <bits/stdc++.h>

using namespace std;

int dp[300][300][2];

int process(int vertices, int height, bool to_hit) {
	if(vertices == 1) return to_hit ? (height == 1) : (height > 0);
	if(height <= 0) return 0;

	if(dp[vertices][height][to_hit] != -1) return dp[vertices][height][to_hit];

	vertices--;
	int answer = 0;
	
	if(!to_hit) for(int i = 1; i < vertices; i++) {
		int left = process(i, height - 1, false);
		int right = process(vertices - i, height - 1, false);
		answer += left * right;
		answer %= 9901;
	} else for(int i = 1; i < vertices; i++) {
		int left = process(i, height - 1, true);
		int right = process(vertices - i, height - 1, false);
		answer += left * right;

		left = process(i, height - 1, false);
		right = process(vertices - i, height - 1, true);
		answer += left * right;

		answer -= process(i, height - 1, true) * process(vertices - i, height - 1, true);
		answer %= 9901;
	}

	return dp[vertices + 1][height][to_hit] = answer;
}

int main() {
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	memset(dp, -1, sizeof dp);
	int n, k;
	cin >> n >> k;
	cout << process(n, k, true) << endl;
}