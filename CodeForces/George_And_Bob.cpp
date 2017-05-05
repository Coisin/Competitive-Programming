#include <bits/stdc++.h>

using namespace std;

long long n, m, k;
vector<long long> numbers, prefix_array;
long long dp[5000][5000];

long long process(long long pos, long long pair_pos) {
	if(pair_pos == k) return 0;
	if(dp[pos][pair_pos] != -1) return dp[pos][pair_pos];

	long long answer;
	long long next_number = pos + m;
	long long sum = prefix_array[next_number - 1] - (pos > 0 ? prefix_array[pos - 1] : 0);

	if(next_number == n) return sum;
	if(next_number > n) return -1000000000;
	
	answer = max(process(pos + 1, pair_pos), process(next_number, pair_pos + 1) + sum);
	return dp[pos][pair_pos] = answer;
}

int main() {
	cin >> n >> m >> k;
	numbers.resize(n);
	prefix_array.resize(n);
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++) {
		cin >> numbers[i];
		prefix_array[i] = numbers[i] + (i > 0 ? prefix_array[i - 1] : 0);
	}
	cout << process(0, 0) << endl;
}