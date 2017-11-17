#include <bits/stdc++.h>

using namespace std;

int rows, cols;
char grid[1001][1001];
bool row_used[1001];

int process(int r) {
	for(int i = 0; i < cols; i++) {
		bool flip = grid[r][i] != 'H';
		if(flip)
			for(int j = 0; j < rows; j++)
				grid[j][i] = grid[j][i] == 'H' ? 'T' : 'H';
	}
	int answer = 0;
	for(int i = 0; i < rows; i++) {
		bool harp = true;
		for(int j = 0; j < cols; j++) {
			harp &= grid[i][j] == 'H';
		}
		if(harp) {
			row_used[i] = true;
			answer++;
		}
	}
	return answer;
}

int main() {
	cin >> rows >> cols;
	for(int i = 0; i < rows; i++)
		cin >> grid[i];
	int answer = -1;
	for(int i = 0; i < rows; i++)
		if(!row_used[i])
			answer = max(answer, process(i));
	cout << answer << endl;
}