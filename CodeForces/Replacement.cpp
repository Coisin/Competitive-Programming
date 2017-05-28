#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string sequence;
	cin >> sequence;

	bool in_island = false;
	int num_islands = 0;
	int num_spaces = 0;
	for(int i = 0; i < n; i++) {
		if(sequence[i] == '.') {
			num_spaces++;
			if(!in_island) {
				num_islands++;
				in_island = true;
			}
		} else in_island = false;
	}
	for(int i = 0; i < m; i++) {
		int a;
		char c;
		cin >> a >> c;
		a--;
		bool to_left = false;
		bool to_right = false;
		if(a > 0 && sequence[a - 1] == '.') to_left = true;
		if(a < n - 1 && sequence[a + 1] == '.') to_right = true;
		if(sequence[a] == '.' && c != '.') {
			if(!to_left && !to_right) num_islands--;
			if(to_left && to_right) num_islands++;
			num_spaces--;
		} else if(sequence[a] != '.' && c == '.') {
			if(!to_left && !to_right) num_islands++;
			if(to_left && to_right) num_islands--;
			num_spaces++;
		}
		sequence[a] = c;
		cout << (num_spaces - num_islands) << endl;
	}
}