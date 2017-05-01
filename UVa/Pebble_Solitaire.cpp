#include <bits/stdc++.h>

using namespace std;

int num_columns = 12;

int dp[1 << 13];

int process(int bitmask) {
	if(dp[bitmask] != -1) return dp[bitmask];
	bool is_valid_move = false;
	int answer = 1e9;
	for(int i = 0; i <= num_columns - 3; i++) {
		int hole1, hole2, hole3;
		hole1 = bitmask & (1 << i);
		hole2 = bitmask & (1 << (i + 1));
		hole3 = bitmask & (1 << (i + 2));
		
		int new_bitmask = bitmask;
		new_bitmask ^= (1 << i);
		new_bitmask ^= (1 << (i + 1));
		new_bitmask ^= (1 << (i + 2));
		if((hole1 == 0 && hole2 && hole3) || (hole1 && hole2 && hole3 == 0)) {
			is_valid_move = true;
			answer = min(answer, process(new_bitmask));
		}
	}
	if(!is_valid_move) {
		return dp[bitmask] = __builtin_popcount(bitmask);
	}
	return dp[bitmask] = answer;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		memset(dp, -1, sizeof dp);
		string sequence;
		cin >> sequence;
		int bitmask = 0;
		for(int i = 0; i < num_columns; i++) {
			if(sequence[i] == 'o') {
				bitmask |= (1 << i);
			}
		}
		cout << process(bitmask) << endl;
	}
}