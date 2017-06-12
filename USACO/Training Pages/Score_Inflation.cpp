/*

TASK: inflate
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int num_types;
int times[10001], points[10001];

int process(int time_left) {
	if(time_left == 0) return 0;
	if(time_left < 0) return -1000000000;
	if(dp[time_left] != -1) return dp[time_left];
	int answer = 0;
	for(int i = 0; i < num_types; i++) {
		answer = max(answer, process(time_left - times[i]) + points[i]);
	}
	return dp[time_left] = answer;
}

int main() {
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	memset(dp, -1, sizeof dp);
	int time;
	cin >> time >> num_types;
	for(int i = 0; i < num_types; i++)
		cin >> points[i] >> times[i];
	cout << process(time) << endl;
}