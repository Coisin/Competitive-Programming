#include <bits/stdc++.h>

using namespace std;

int dp[101][101][2][11];
int max_a, max_b;

int process(int a, int b, bool prev_a, int quantity) {
	if(a == 0 && b == 0)
		return 1;
	if(a < 0 || b < 0)
		return 0;
	if(dp[a][b][prev_a][quantity] != -1)
		return dp[a][b][prev_a][quantity];
	int answer = 0;
	if(!(prev_a && quantity == max_a))
		answer += process(a - 1, b, true, prev_a ? quantity + 1 : 1);
	if(!(!prev_a && quantity == max_b))
		answer += process(a, b - 1, false, prev_a ? 1 : quantity + 1);
	return dp[a][b][prev_a][quantity] = answer % 100000000;
}

int main() {
	memset(dp, -1, sizeof dp);
	int a, b;
	cin >> a >> b >> max_a >> max_b;
	cout << process(a, b, 0, 0) << endl;
}