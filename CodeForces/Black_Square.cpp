#include <bits/stdc++.h>

using namespace std;

int num_rows, num_cols;
char grid[101][101];

int main() {
	cin >> num_rows >> num_cols;
	for(int i = 0; i < num_rows; i++)
		cin >> grid[i];
	int left_most, right_most, top_most, bottom_most;
	bottom_most = right_most = -1;
	left_most = top_most = 100;
	int num_black = 0;
	for(int i = 0; i < num_rows; i++)
		for(int j = 0; j < num_cols; j++)
			if(grid[i][j] == 'B') {
				right_most = max(j, right_most);
				left_most = min(j, left_most);
				bottom_most = max(i, bottom_most);
				top_most = min(i, top_most);
				num_black++;
			}
	int side_length = (right_most - left_most) + 1;
	side_length = max(side_length, (bottom_most - top_most) + 1);
	if(num_black == 0)
		cout << 1 << endl;
	else if(num_cols < side_length || num_rows < side_length)
		cout << -1 << endl;
	else
		cout << (side_length * side_length) - num_black << endl; 
}