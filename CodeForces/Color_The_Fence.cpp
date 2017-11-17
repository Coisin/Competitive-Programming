#include <bits/stdc++.h>

using namespace std;

long long cost[10];
long long dp[1000001];
long long where_to[1000001];

long long process(long long v) {
	if(v == 0)
		return 0;
	if(v < 0)
		return -1000000000;
	if(dp[v] != -1)
		return dp[v];
	long long answer = 0;
	for(long long i = 1; i <= 9; i++) {
		long long response = 1 + process(v - cost[i]);
		if(response >= answer) {
			answer = response;
			where_to[v] = i;
		}
	}
	return dp[v] = answer;
}

void backtrace(long long v) {
	if(where_to[v] == 0)
		return;
	cout << where_to[v];
	backtrace(v - cost[where_to[v]]);
}

int main() {
	memset(dp, -1, sizeof dp);
	long long v;
	cin >> v;
	for(long long i = 1; i <= 9; i++)
		cin >> cost[i];
	long long response = process(v);
	if(response <= 0) {
		cout << -1;
	} else backtrace(v);
	cout << endl;
}