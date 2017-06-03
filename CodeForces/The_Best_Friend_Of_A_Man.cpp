#include <bits/stdc++.h>

using namespace std;

long long num_days, required_walks;
vector<long long> days;

long long dp[5000][501], answer_days[5000][501];

long long process(long long prev, long long pos) {
	if(pos == num_days) return 0;
	if(dp[prev][pos] != -1) return dp[prev][pos];
	long long cost = max(0ll, required_walks - (prev + days[pos]));
	long long answer = cost + process(cost + days[pos], pos + 1);
	answer_days[prev][pos] = cost + days[pos];
	for(long long needed = max(days[pos], days[pos] + (required_walks - (prev + days[pos]))); needed <= required_walks; needed++) {
		cost = (needed - days[pos]) + process(needed, pos + 1);
		if(cost < answer) {
			answer = cost;
			answer_days[prev][pos] = needed;
		}
	}
	return dp[prev][pos] = answer;
}

void print_path(long long prev, long long pos) {
	if(pos == num_days) return;
	cout << answer_days[prev][pos] << " ";
	print_path(answer_days[prev][pos], pos + 1);
}

int main() {
	memset(dp, -1, sizeof dp);
	memset(answer_days, -1, sizeof answer_days);
	cin >> num_days >> required_walks;
	days.resize(num_days);
	for(long long i = 0; i < num_days; i++)
		cin >> days[i];
	cout << process(required_walks, 0) << endl;
	print_path(required_walks, 0);
}