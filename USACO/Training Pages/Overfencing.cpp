/*

TASK: maze1
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int width, height;
int dist[300][300];
string grid[300];

int main() {

	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);

	cin >> width >> height;
	width = (width * 2) + 1;
	height = (height * 2) + 1;

	getline(cin, grid[0]);
	for(int i = 0; i < height; i++)
		getline(cin, grid[i]);

	int x1, y1, x2, y2;
	x1 = x2 = y1 = y2 = -1;

	for(int i = 1; i < width - 1; i++)
		if(grid[0][i] == ' ')
			if(x1 == -1) {
				x1 = i;
				y1 = 0;
			} else {
				x2 = i;
				y2 = 0;
			}
	for(int i = 1; i < width - 1; i++)
		if(grid[height - 1][i] == ' ')
			if(x1 == -1) {
				x1 = i;
				y1 = height - 1;
			} else {
				x2 = i;
				y2 = height - 1;
			}
	for(int i = 1; i < height - 1; i++)
		if(grid[i][0] == ' ')
			if(x1 == -1) {
				x1 = 0;
				y1 = i;
			} else {
				x2 = 0;
				y2 = i;
			}
	for(int i = 1; i < height - 1; i++)
		if(grid[i][width - 1] == ' ')
			if(x1 == -1) {
				x1 = width - 1;
				y1 = i;
			} else {
				x2 = width - 1;
				y2 = i;
			}
	queue<pair<int, int> > q;
	int dist[height][width];
	for(int i = 0; i < height; i++)
		for(int j = 0; j < width; j++)
			dist[i][j] = 1000000000;
	dist[y1][x1] = 0;
	dist[y2][x2] = 0;
	q.push({x1, y1});
	q.push({x2, y2});
	int cX[4] = {1, 0, -1, 0};
	int cY[4] = {0, 1, 0, -1};
	int worst = -1;
	while(!q.empty()) {
		int y = q.front().second;
		int x = q.front().first;
		q.pop();
		worst = max(worst, dist[y][x]);
		for(int i = 0; i < 4; i++) {
			int nX = x + cX[i];
			int nY = y + cY[i];
			if(nX < 0 || nX >= width || nY < 0 || nY >= height) continue;
			if(grid[nY][nX] != ' ') continue;
			if(dist[nY][nX] > dist[y][x] + 1) {
				dist[nY][nX] = dist[y][x] + 1;
				q.push({nX, nY});
			}
		}
	}
	cout << (worst + 1) / 2 << endl;
}