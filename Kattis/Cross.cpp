#include <bits/stdc++.h>

using namespace std;

string grid[9];
set<char> cols[9], rows[9];
bool avoid_row[9], avoid_col[9];

int main() {
	bool error = false;
	for(int i = 0; i < 9; i++)
		cin >> grid[i];
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(grid[i][j] != '.') {
				if(cols[j].count(grid[i][j]) || rows[i].count(grid[i][j]))
					error = true;
				cols[j].insert(grid[i][j]);
				rows[i].insert(grid[i][j]);
			}
	bool change = true;
	while(change) {
		change = false;
		for(char i = '1'; i <= '9'; i++) { 
			memset(avoid_row, 0, sizeof avoid_row);
			memset(avoid_col, 0, sizeof avoid_col);
			for(int j = 0; j < 9; j++) {
				if(rows[j].count(i))
					avoid_row[j] = 1;
				if(cols[j].count(i))
					avoid_col[j] = 1;
			}
			for(int start_row = 0; start_row < 9; start_row += 3) {
				for(int start_col = 0; start_col < 9; start_col += 3) {
					int empty_row = -1;
					int empty_col = -1;
					int empty_count = 0;
					bool has_i = false;
					bool all_blocked = 1;
					int i_count = 0;
					for(int row = start_row; row < start_row + 3; row++) {
						for(int col = start_col; col < start_col + 3; col++) {
							all_blocked &= avoid_col[col] || avoid_row[row] || (grid[row][col] != '.' && grid[row][col] != i);
							has_i |= grid[row][col] == i;
							if(i == grid[row][col])
								i_count++;
							if(avoid_row[row])
								continue;
							if(avoid_col[col])
								continue;
							if(grid[row][col] == '.') {
								empty_count++;
								empty_row = row;
								empty_col = col;
							}
						}
					}
					all_blocked &= !has_i;
					if(all_blocked)
						error = 1;
					if(empty_count == 1 && !has_i) {
						grid[empty_row][empty_col] = i;
						rows[empty_row].insert(i);
						cols[empty_col].insert(i);
						avoid_row[empty_row] = 1;
						avoid_col[empty_col] = 1;
						change = 1;
					}
				}
			}
		}
	}

	if(error)
		cout << "ERROR" << endl;
	for(int i = 0; i < 9 && !error; i++)
		cout << grid[i] << endl;
}