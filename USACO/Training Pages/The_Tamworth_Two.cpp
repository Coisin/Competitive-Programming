/*

LANG: C++11
TASK: ttwo

*/


#include <bits/stdc++.h>

using namespace std;

char grid[10][10];

bool out_of_bounds(int r, int c) { return r < 0 || r >= 10 || c < 0 || c >= 10 || grid[r][c] == '*'; }

pair<int, pair<int, int> > get_next_move(int r, int c, int orient) {
	int nr = r, nc = c;
	if(orient == 0) { nr--; }
	if(orient == 1) { nc++; }
	if(orient == 2) { nr++; }
	if(orient == 3) { nc--; }
	if(out_of_bounds(nr, nc)) return {(orient + 1) % 4, {r, c}};
	return {orient, {nr, nc}};
}

int main() {
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);

	for(int i = 0; i < 10; i++)
		cin >> grid[i];
	int farmer_row, farmer_col;
	int cow_row, cow_col;
	int farmer_or = 0, cow_or = 0;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++) {
			if(grid[i][j] == 'F') {
				farmer_row = i;
				farmer_col = j;
			}
			if(grid[i][j] == 'C') {
				cow_row = i;
				cow_col = j;
			}
		}
	int dist[10][10][4][10][10][4] = {-1};
	queue<pair<int, pair<pair<int, pair<int, int> >, pair<int, pair<int, int> > > > > q;

	dist[farmer_row][farmer_col][farmer_or][cow_row][cow_col][cow_or] = 0;
	q.push({0, {{farmer_or, {farmer_row, farmer_col}}, {cow_or, {cow_row, cow_col}}}});

	while(!q.empty()) {

		int distance = q.front().first;

		farmer_or = q.front().second.first.first;
		farmer_row = q.front().second.first.second.first;
		farmer_col = q.front().second.first.second.second;

		cow_or = q.front().second.second.first;
		cow_row = q.front().second.second.second.first;
		cow_col = q.front().second.second.second.second;

		q.pop();

		if(farmer_row == cow_row && farmer_col == cow_col) {
			cout << distance << endl;
			return 0;
		}

		pair<int, pair<int, int> > next_farmer = get_next_move(farmer_row, farmer_col, farmer_or);
		pair<int, pair<int, int> > next_cow = get_next_move(cow_row, cow_col, cow_or);

		farmer_row = next_farmer.second.first;
		farmer_col = next_farmer.second.second;
		farmer_or = next_farmer.first;

		cow_row = next_cow.second.first;
		cow_col = next_cow.second.second;
		cow_or = next_cow.first;

		if(dist[farmer_row][farmer_col][farmer_or][cow_row][cow_col][cow_or] == 0) {
			dist[farmer_row][farmer_col][farmer_or][cow_row][cow_col][cow_or] = distance + 1;
			q.push({distance + 1, {{farmer_or, {farmer_row, farmer_col}}, {cow_or, {cow_row, cow_col}}}});
		}
	}
	cout << 0 << endl;
}