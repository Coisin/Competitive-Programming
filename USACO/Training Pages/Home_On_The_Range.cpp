/*

TASK: range
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

string grid[251];
int prefix[251][251];
int quantity[252];

bool is_square(int x1, int y1, int x2, int y2) {
	int answer = prefix[y2][x2];
	if(x1 > 0)
		answer -= prefix[y2][x1 - 1];
	if((y1 > 0))
		answer -= prefix[y1 - 1][x2];
	if(x1 > 0 && y1 > 0)
		answer += prefix[y1 - 1][x1 - 1];
	return answer == 0;
}

int main() {
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> grid[i];
		for(int j = 0; j < n; j++) {
			if(j > 0)
				prefix[i][j] += prefix[i][j - 1];
			if(i > 0)
				prefix[i][j] += prefix[i - 1][j];
			if(i > 0 && j > 0)
				prefix[i][j] -= prefix[i - 1][j - 1];
			if(grid[i][j] == '0')
				prefix[i][j]++;
		}
	}
	for(int y1 = 0; y1 < n; y1++) {
		for(int x1 = 0; x1 < n; x1++) {
			for(int width = 1; width < n; width++) {
				int y2 = y1 + width;
				int x2 = x1 + width;
				if(y2 >= n || x2 >= n)
					break;
				quantity[width + 1] += is_square(x1, y1, x2, y2);
			}
		}
	}
	for(int i = 0; i <= n; i++)
		if(quantity[i])
			cout << i << " " << quantity[i] << endl;
}