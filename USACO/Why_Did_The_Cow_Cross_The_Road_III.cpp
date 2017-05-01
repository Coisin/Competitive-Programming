#include <bits/stdc++.h>

using namespace std;

int num_roads, num_cows, size_of_grid;
int farm[101][101];
bool visited[101][101];

int cX[] = {-1, 0, 1, 0};
int cY[] = {0, -1, 0, 1};

set<pair<pair<int, int>, pair<int, int> > > roads;

int floodfill(int row, int column) {
	visited[row][column] = true;
	int answer = farm[row][column];
	for(int i = 0; i < 4; i++) {
		int nR = row + cY[i];
		int nC = column + cX[i];
		if(nR < 0 || nC < 0 || nR >= size_of_grid || nC >= size_of_grid) continue;
		if(visited[nR][nC]) continue;
		if(roads.count({{row, column}, {nR, nC}}) || roads.count({{nR, nC}, {row, column}})) continue;
		answer += floodfill(nR, nC);
	}
	return answer;
}

int main() {
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
	cin >> size_of_grid >> num_cows >> num_roads;
	for(int i = 0; i < num_roads; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--, c1--, r2--, c2--;
		roads.insert({{r1, c1}, {r2, c2}});
	}
	vector<pair<int, int> > cows;
	for(int j = 0; j < num_cows; j++) {
		int r, c;
		cin >> r >> c;
		r--, c--;
		cows.push_back({r, c});
		farm[r][c] = true;
	}
	vector<int> scc_size;
	for(int i = 0; i < num_cows; i++) 
		if(!visited[cows[i].first][cows[i].second])
			scc_size.push_back(floodfill(cows[i].first, cows[i].second));
	int answer = 0;
	for(int i = 0; i < scc_size.size(); i++)
		for(int j = i + 1; j < scc_size.size(); j++)
			answer += scc_size[i] * scc_size[j];
	cout << answer;
}