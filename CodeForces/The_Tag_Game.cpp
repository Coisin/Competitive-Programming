#include <bits/stdc++.h>

using namespace std;

int num_vertices, x;
vector<vector<int> > adjList;

int dist[2][200001];

void get_dist(int super_p, int p, int u) {
	for(int n : adjList[u]) {
		if(n == p) continue;
		dist[super_p][n] = dist[super_p][u] + 1;
		get_dist(super_p, u, n);
	}
}

int main() {
	cin >> num_vertices >> x;
	x--;
	adjList.assign(num_vertices, vector<int>() );
	for(int i = 0; i < num_vertices - 1; i++) {
		int a, b;
		cin >> a >> b;
		 a--, b--;
		 adjList[a].push_back(b);
		 adjList[b].push_back(a);
	}
	get_dist(0, -1, x);
	get_dist(1, -1, 0);
	int answer = 0;
	for(int i = 0; i < num_vertices; i++) {
		int a = dist[0][i];
		int b = dist[1][i];
		if(a < b) {
			int next_ans = 2 * max(a, b);
			answer = max(answer, next_ans);
		}
	}
	cout << answer << endl;
}