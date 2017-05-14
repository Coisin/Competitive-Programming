#include <bits/stdc++.h>

using namespace std;

long long num_pieces;
vector<long long> prefix_array;

long long dp[101];

long long process(long long pos) {
	if(pos == num_pieces) return 1;
	if(dp[pos] != -1) return dp[pos];
	long long answer = 0;
	for(long long next_start = pos + 1; next_start <= num_pieces; next_start++) {
		if(prefix_array[next_start - 1] - (pos > 0 ? prefix_array[pos - 1] : 0) > 1) break;
		if(prefix_array[next_start - 1] - (pos > 0 ? prefix_array[pos - 1] : 0) != 1) continue;
		answer += process(next_start);
	}
	return dp[pos] = answer;
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> num_pieces;
	prefix_array.resize(num_pieces);
	for(long long i = 0; i < num_pieces; i++) {
		cin >> prefix_array[i];
		prefix_array[i] += i > 0 ? prefix_array[i - 1] : 0;
	}
	cout << process(0) << endl;
}