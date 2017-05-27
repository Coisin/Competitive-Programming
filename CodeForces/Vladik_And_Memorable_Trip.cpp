#include <bits/stdc++.h>

using namespace std;

long long n;
long long numbers[7000];
bool visited[7000];
long long first[7000];
long long last[7000];
long long prefix[7000];

long long dp[7000];

long long process(long long pos) {
	if(pos == n) return 0;
	if(dp[pos] != -1) return dp[pos];
	long long answer = -1;
	long long a = numbers[pos];
	long long next_pos = last[a];
	bool can_do_it = true;
	for(int i = pos; i <= next_pos; i++)
		if(first[numbers[i]] < pos) {
			can_do_it = false;
			break;
		} else if(last[numbers[i]] > next_pos)
			next_pos = last[numbers[i]];
	if(can_do_it && first[a] == pos) {
		long long score = prefix[next_pos] ^ (pos == 0 ? 0 : prefix[pos - 1]);
		answer = max(answer, score + process(next_pos + 1));
	}
	next_pos = pos + 1;
	answer = max(answer, process(next_pos));
	return dp[pos] = answer;
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(long long i = 0; i < n; i++) {
		cin >> numbers[i];

		if(i > 0)
			if(visited[numbers[i]])
				prefix[i] = prefix[i - 1];
			else prefix[i] = prefix[i - 1] ^ numbers[i];
		else prefix[i] = numbers[i];

		if(!visited[numbers[i]])
			first[numbers[i]] = i;
		last[numbers[i]] = i;
		visited[numbers[i]] = true;
	}
	cout << process(0) << endl;
}