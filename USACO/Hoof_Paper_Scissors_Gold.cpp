#include <bits/stdc++.h>

using namespace std;

int num_moves;
int num_transitions;
int moves[100001];
int dp[25][100005][5];

int process(int current_moves, int pos, int state) {
	if(pos == num_moves) return 0;
	if(dp[current_moves][pos][state] != -1) return dp[current_moves][pos][state];
	int answer = process(current_moves, pos + 1, state);
	if(current_moves)
		for(int i = 0; i < 3; i++) {
			if(i == state) continue;
			answer = max(answer, process(current_moves - 1, pos + 1, i));
		}
	answer += state == (moves[pos] + 1) % 3;
	return dp[current_moves][pos][state] = answer;
}

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	memset(dp, -1, sizeof dp);
	cin >> num_moves >> num_transitions;
	for(int i = 0; i < num_moves; i++) {
		char a;
		cin >> a;
		if(a == 'S')
			moves[i] = 0;
		else if(a == 'H')
			moves[i] = 1;
		else if(a == 'P')
			moves[i] = 2;
	}
	cout << max(process(num_transitions, 0, 0), max(process(num_transitions, 0, 1), process(num_transitions, 0, 2)));
}