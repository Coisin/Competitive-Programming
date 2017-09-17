#include <bits/stdc++.h>

using namespace std;

int num_rows, num_cols;

char grid[51][51];
bool visited[51][51];

int cX[] = {-1, 0, 1, 0};
int cY[] = {0, -1, 0, 1};

void process(int depth, int row, int col, char type, int pR, int pC) {
	if(row < 0 || col < 0 || row >= num_rows || col >= num_cols)
		return;
	if(grid[row][col] != type) return;
	if(visited[row][col]) {
		if(depth > 4) {
			cout << "Yes" << endl;
			exit(0);
		}
		return;
	}
	visited[row][col] = 1;
	for(int i = 0; i < 4; i++) {
		int nR = row + cY[i];
		int nC = col + cX[i];
		if(nR == pR && nC == pC) continue;
		process(depth + 1, nR, nC, type, row, col);
	}
}

int main() {
	cin >> num_rows >> num_cols;
	for(int i = 0; i < num_rows; i++)
		for(int j = 0; j < num_cols; j++)
			cin >> grid[i][j];
	for(int i = 0; i < num_rows; i++)
		for(int j = 0; j < num_cols; j++) {
			memset(visited, 0, sizeof visited);
			process(1, i, j, grid[i][j], -1, -1);
		}
	cout << "No" << endl;
}