/*

TASK: game1
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int n;
int sequence[101];
int where_to[101][101][2];
int dp[101][101][2];

int process(int left, int right, bool player) {
	if(left == right)
		return sequence[left];
	if(dp[left][right][player] != -1)
		return dp[left][right][player];
	int option_1 = sequence[left] - process(left + 1, right, !player);
	int option_2 = sequence[right] - process(left, right - 1, !player);
	if(option_1 > option_2) {
		where_to[left][right][player] = 1;
		return dp[left][right][player] = option_1;
	} else {
		where_to[left][right][player] = 2;
		return dp[left][right][player] = option_2;
	}
}

int score[] = {0, 0};

void backtrace(int left, int right, bool player) {
	if(left == right) {
		score[player] += sequence[left];
		return;
	}
	if(where_to[left][right][player] == 1) {
		score[player] += sequence[left];
		backtrace(left + 1, right, !player);
	} else {
		score[player] += sequence[right];
		backtrace(left, right - 1, !player);
	}
}

int main() {
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	memset(dp, -1, sizeof dp);
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++)
		cin >> sequence[i];
	int response = process(0, n - 1, true);
	backtrace(0, n - 1, true);
	cout << score[1] << " " << score[0] << endl;
}