#include <bits/stdc++.h>

using namespace std;

int num_sticks;
vector<int> sticks;

double total_length, side_length;
int counter = 0;

int dp[1 << 21];

bool process(int stick_pos, int taken, int length) {
	if(dp[taken] != -1) return dp[taken];
	if(stick_pos == 4) return true;
	if(length > side_length) return false;
	if(length == side_length) return dp[taken] = process(stick_pos + 1, taken, 0);
	bool answer = false;
	for(int i = 0; i < num_sticks; i++) {
		if(taken & (1 << i)) continue;
		answer |= process(stick_pos, taken | (1 << i), length + sticks[i]);
	}
	return dp[taken] = answer;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		memset(dp, -1, sizeof dp);
		cin >> num_sticks;
		sticks.resize(num_sticks);
		total_length = 0;
		for(int i = 0; i < num_sticks; i++) { 
			cin >> sticks[i];
			total_length += sticks[i];
		}
		if((int)total_length % 4) {
			cout << "no" << endl;
			continue;
		}
		side_length = total_length / 4;
		cout << (process(0, 0, 0) ? "yes" : "no") << endl;
	}
}