#include <bits/stdc++.h>

using namespace std;

int rows, cols;
bool going_right = true;

pair<int, int> next_cell(int row, int col) {
	if(col == cols && going_right) {
		row++;
		going_right = false;
	} else if(col == 1 && !going_right) {
		row++;
		going_right = true;
	} else col += going_right ? 1 : -1;
	return {row, col};
}

int main() {
	int k;
	cin >> rows >> cols >> k;
	int row, col;
	row = col = 1;
	int current_counter = 0;
	vector<vector<pair<int, int> > > tubes(k, vector<pair<int, int> >() );
	while(k) {
		current_counter++;
		tubes[k - 1].push_back({row, col});
		pair<int, int> new_point = next_cell(row, col);
		row = new_point.first;
		col = new_point.second;
		if((current_counter == 2 && k > 1) || row > rows) {
			current_counter = 0;
			k--;
		}
	}
	for(vector<pair<int, int> > tube : tubes) {
		cout << tube.size();
		for(pair<int, int> a : tube)
			cout << " " << a.first << " " << a.second;
		cout << endl;
	}
}