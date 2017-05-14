#include <bits/stdc++.h>

using namespace std;

long long num_strings;
vector<long long> costs;
vector<string> strings;

long long dp[100001][2];

long long process(long long pos, bool flipped) {
	if(pos == num_strings - 1) return 0;
	if(dp[pos][flipped] != -1) return dp[pos][flipped];
	long long answer = 1000000000000000000;
	string current = strings[pos];
	string next = strings[pos + 1];
	bool found = false;
	if(flipped) {
		// Both Reversed
		for(long long i = current.size() - 1, j = next.size() - 1; i >= 0, j >= 0; i--, j--) {
			if(current[i] > next[j]) {
				found = true;
				break;
			} else if(next[j] > current[i]) {
				answer = min(answer, costs[pos + 1] + process(pos + 1, true));
				found = true;
				break;
			}
		}
		if(!found && current.size() <= next.size()) {
			answer = min(answer, costs[pos + 1] + process(pos + 1, true));
		}
		// This Reversed, Last Straight
		found = false;
		for(long long i = current.size() - 1, j = 0; i >= 0, j < next.size(); i--, j++) {
			if(current[i] > next[j]) {
				found = true;
				break;
			} else if(next[j] > current[i]) {
				found = true;
				answer = min(answer, process(pos + 1, false));
				break;
			}
		}
		if(!found && current.size() <= next.size()) {
			answer = min(answer, process(pos + 1, false));
		}
	} else {
		// Both Straight
		found = false;
		for(long long i = 0; i < min(current.size(), next.size()); i++) {
			if(current[i] > next[i]) {
				found = true;
				break;
			} else if(next[i] > current[i]) {
				found = true;
				answer = min(answer, process(pos + 1, false));
				break;
			}
		}
		if(!found && current.size() <= next.size()) {
			answer = min(answer, process(pos + 1, false));
		}
		// This Straight, Last Reversed
		found = false;
		for(long long i = 0, j = next.size() - 1; i < current.size(), j >= 0; i++, j--) {
			if(current[i] > next[j]) {
				found = true;
				break;
			} else if(next[j] > current[i]) {
				found = true;
				answer = min(answer, costs[pos + 1] + process(pos + 1, true));
				break;
			}
		}
		if(!found && current.size() <= next.size()) {
			answer = min(answer, costs[pos + 1] + process(pos + 1, true));
		}
	}
	return dp[pos][flipped] = answer;
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> num_strings;
	costs.resize(num_strings);
	strings.resize(num_strings);
	for(long long i = 0; i < num_strings; i++) cin >> costs[i];
	for(long long i = 0; i < num_strings; i++) cin >> strings[i];
	long long answer = min(costs[0] + process(0, true), process(0, false));
	if(answer >= 1000000000000000000) answer = -1;
	cout << answer << endl;
}