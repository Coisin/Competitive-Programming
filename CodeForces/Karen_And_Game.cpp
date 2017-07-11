#include <bits/stdc++.h>

using namespace std;

int num_rows, num_cols;
int grid[101][101];

int cols[101], rows[101];
int current_answer;
int answer = 1000000000;
int min_a;

bool works(int first_row_flips) {
	rows[0] = first_row_flips;
	current_answer = first_row_flips;
	for(int i = 0; i < num_cols; i++) {
		cols[i] = grid[0][i] - first_row_flips;
		current_answer += cols[i];
		if(cols[i] < 0) return false;
	}
	for(int i = 1; i < num_rows; i++) {
		rows[i] = grid[i][0] - cols[0];
		current_answer += rows[i];
		if(rows[i] < 0) return false;
		for(int j = 0; j < num_cols; j++)
			if(grid[i][j] - cols[j] != rows[i])
				return false;
	}
	return true;
}

int main() {
	cin >> num_rows >> num_cols;
	for(int i = 0; i < num_rows; i++)
		for(int j = 0; j < num_cols; j++)
			cin >> grid[i][j];
	for(int a = 0; a <= 500; a++) {
		if(works(a) && current_answer < answer) {
			answer = current_answer;
			min_a = a;
		}
	}
	if(answer == 1000000000)
		cout << -1 << endl;
	else {
		works(min_a);
		cout << answer << endl;
		for(int i = 0; i < num_rows; i++)
			while(rows[i]--)
				cout << "row " << i + 1 << endl;
		for(int i = 0; i < num_cols; i++)
			while(cols[i]--)
				cout << "col " << i + 1 << endl;
	}
}