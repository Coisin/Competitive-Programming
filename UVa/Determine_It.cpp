#include <bits/stdc++.h>

using namespace std;

long long n, a_n_1;
long long dp[21][21];

long long process(long long i, long long j) {
	if(dp[i][j] != -1)
		return dp[i][j];
	long long answer = 0;
	if(i >= j) {
		if(i < n)
			for(long long k = i + 1; k <= n; k++)
				answer = max(answer, process(k, 1) + process(k, j));
		long long to_add = 0;
		if(j > 0)
			for(long long k = 1; k < j; k++)
				to_add = max(to_add, process(i, k) + process(n, k));
		answer += to_add;
	}
	if(i < j)
		for(long long k = i; k < j; k++)
			answer = max(answer, process(i, k) + process(k + 1, j));
	return dp[i][j] = answer;
}

int main() {
	while(scanf("%lld %lld", &n, &a_n_1) != EOF) {
		memset(dp, -1, sizeof dp);
		dp[n][1] = a_n_1;
		cout << process(1, n) << endl;
	}
}