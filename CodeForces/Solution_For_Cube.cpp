#include <bits/stdc++.h>

using namespace std;

vector<int> colors(24);

bool all_perfect(vector<int> c) {
	for(int i = 0; i < 6; i++) {
		int color = c[i * 4];
		bool perfect = true;
		for(int j = 0; j < 4; j++) {
			int index = (i * 4) + j;
			if(c[index] != color)
				perfect = false;
		}
		if(!perfect)
			return false;
	}
	return true;
}

int main() {
	for(int i = 0; i < 24; i++)
		cin >> colors[i];
	int perfect_side_1 = -1;
	int perfect_side_2 = -1;
	bool possible = true;
	for(int i = 0; i < 6; i++) {
		int color = colors[i * 4];
		bool perfect = true;
		for(int j = 0; j < 4; j++) {
			int index = (i * 4) + j;
			if(colors[index] != color)
				perfect = false;
		}
		if(perfect) {
			if(perfect_side_1 == -1)
				perfect_side_1 = i;
			else if(perfect_side_2 == -1)
				perfect_side_2 = i;
			else possible = false;
		}
	}
	perfect_side_1++;
	perfect_side_2++;
	bool found = false;
	if(perfect_side_1 == 1 && perfect_side_2 == 3) {
		int row[] = {13, 14, 5, 6, 17, 18, 21, 22};
		vector<int> colors_2 = colors;
		for(int i = 0; i < 8; i++) {
			int next_i = (i + 2) % 8;
			colors_2[row[next_i] - 1] = colors[row[i]- 1];
		}
		if(all_perfect(colors_2))
			found = true;
		vector<int> colors_3 = colors;
		for(int i = 0; i < 8; i++) {
			int next_i = (i + 2) % 8;
			colors_3[row[i] - 1] = colors[row[next_i] - 1];
		}
		if(all_perfect(colors_3))
			found = true;
	}
	if(perfect_side_1 == 4 && perfect_side_2 == 5) {
		int row[] = {2, 4, 6, 8, 10, 12, 23, 21};
		vector<int> colors_2 = colors;
		for(int i = 0; i < 8; i++) {
			int next_i = (i + 2) % 8;
			colors_2[row[next_i] - 1] = colors[row[i] - 1];
		}
		if(all_perfect(colors_2))
			found = true;
		vector<int> colors_3 = colors;
		for(int i = 0; i < 8; i++) {
			int next_i = (i + 2) % 8;
			colors_3[row[i] - 1] = colors[row[next_i] - 1];
		}

		if(all_perfect(colors_3))
			found = true;
	}
	if(perfect_side_1 == 2 && perfect_side_2 == 6) {
		int row[] = {17, 19, 10, 9, 16, 14, 3, 4};
		vector<int> colors_2 = colors;
		for(int i = 0; i < 8; i++) {
			int next_i = (i + 2) % 8;
			colors_2[row[next_i] - 1] = colors[row[i] - 1];
		}
		if(all_perfect(colors_2))
			found = true;
		vector<int> colors_3 = colors;
		for(int i = 0; i < 8; i++) {
			int next_i = (i + 2) % 8;
			colors_3[row[i] - 1] = colors[row[next_i] - 1];
		}
		if(all_perfect(colors_3))
			found = true;
	}
	if(!found)
		possible = false;
	cout << (possible ? "YES" : "NO") << endl;
}