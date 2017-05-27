/*

TASK: money
LANG: C++11

 */

#include <bits/stdc++.h>

using namespace std;

long long num_currencies;
vector<long long> values;

long long dp[26][10001];

long long process(long long cur_pos, long long sum) {
	if(sum == 0)
		return 1;
	if(sum < 0)
		return 0;
	if(cur_pos == num_currencies)
		return 0;
	if(dp[cur_pos][sum] != -1) return dp[cur_pos][sum];
	return dp[cur_pos][sum] = process(cur_pos, sum - values[cur_pos])
	 						  + process(cur_pos + 1, sum);
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	memset(dp, -1, sizeof dp);
	long long sum;
	cin >> num_currencies >> sum;
	values.resize(num_currencies);
	for(long long i = 0; i < num_currencies; i++)
		cin >> values[i];
	sort(values.begin(), values.end());
	cout << process(0, sum) << endl;
}