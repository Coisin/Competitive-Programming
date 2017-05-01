#include <bits/stdc++.h>

using namespace std;

int num_combinations;
int scores[9][9][9];
int full_group = (1 << 9) - 1;

int dp[(1 << 9) + 2];

int process(int bitmask) {
	if(dp[bitmask] != -1) return dp[bitmask];
	if(bitmask == full_group)
		return 0;
	int answer = -1000000000;
	int a, b, c;
	for(a = 0; a < 9; a++)
		if(!(bitmask & (1 << a)))
			for(b = a + 1; b < 9; b++)
				if(!(bitmask & (1 << b)))
					for(c = b + 1; c < 9; c++)
						if(!(bitmask & (1 << c)))
							answer = max(answer, scores[a][b][c] + process(bitmask | (1 << a) | (1 << b) | (1 << c)));
	return dp[bitmask] = answer;
}

int main() {
	cin >> num_combinations;
	int case_counter = 1;
	while(num_combinations != 0) {
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				for(int k = 0; k < 9; k++)
					scores[i][j][k] = -1000000000;
		for(int i = 0; i < num_combinations; i++) {
			int a, b, c, s;
			cin >> a >> b >> c >> s;
			a--, b--, c--;
			scores[a][b][c] = s;
		}
		int answer = process(0);
		cout << "Case " << case_counter << ": ";
		if(answer < 0)
			cout << -1 << endl;
		else
			cout << answer << endl;
		case_counter++;
		cin >> num_combinations;
	}
}