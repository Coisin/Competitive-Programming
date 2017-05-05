#include <bits/stdc++.h>

using namespace std;

int values_left[501][501];
int values_up[501][501];

char grid[501][501];
int rows, columns;

char empty = '.';
char blocked = '#';

void build_values() {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(i > 0) {
				values_up[i][j] += values_up[i - 1][j];
				values_left[i][j] += values_left[i - 1][j];
			}
			if(j > 0) {
				values_up[i][j] += values_up[i][j - 1];
				values_left[i][j] += values_left[i][j - 1];
			}
			if(i > 0 && j > 0) {
				values_up[i][j] -= values_up[i - 1][j - 1];
				values_left[i][j] -= values_left[i - 1][j - 1];
			}
			if(grid[i][j] == blocked) continue;
			if(i > 0 && grid[i - 1][j] == empty) {
				values_up[i][j]++;
			}
			if(j > 0 && grid[i][j - 1] == empty) {
				values_left[i][j]++;
			}
		}
	}
}

int handle_query(int top_left_row, int top_left_col, int bottom_right_row, int bottom_right_column) {
	int answer = 0;

	answer += values_up[bottom_right_row][bottom_right_column];
	if(top_left_col > 0) {
		answer -= values_up[bottom_right_row][top_left_col - 1];
		answer += values_up[top_left_row][top_left_col - 1];
	}
	answer -= values_up[top_left_row][bottom_right_column];

	answer += values_left[bottom_right_row][bottom_right_column];
	answer -= values_left[bottom_right_row][top_left_col];
	if(top_left_row > 0) {
		answer -= values_left[top_left_row - 1][bottom_right_column];
		answer += values_left[top_left_row - 1][top_left_col];
	}

	return answer;
}

int main() {
	cin >> rows >> columns;
	for(int i = 0; i < rows; i++) cin >> grid[i];
	build_values();
	int num_queries;
	cin >> num_queries;
	for(int i = 0; i < num_queries; i++) {
		int top_left_row, top_left_col, bottom_right_row, bottom_right_column;
		cin >> top_left_row >> top_left_col >> bottom_right_row >> bottom_right_column;
		cout << handle_query(top_left_row - 1, top_left_col - 1, bottom_right_row - 1, bottom_right_column - 1) << endl;
	}
}