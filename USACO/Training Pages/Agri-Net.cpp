
/* 

TASK: agrinet
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int> > > adjList;
priority_queue<pair<int, int> > pq;
bool visited[200];

void process(int u) {
	visited[u] = true;
	for(pair<int, int> n : adjList[u]) {
		if(!visited[n.first]) pq.push({-n.second, -n.first});
	}
}

int main() {
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);

	int num_farms;
	cin >> num_farms;
	adjList.assign(num_farms, vector<pair<int, int> >() );
	for(int i = 0; i < num_farms; i++) {
		for(int j = 0; j < num_farms; j++) {
			int dist;
			cin >> dist;
			adjList[i].push_back({j, dist});
			adjList[j].push_back({i, dist});
		}
	}
	int cost = 0;
	process(0);
	while(!pq.empty()) {
		int farm = -pq.top().second;
		int dist = -pq.top().first; pq.pop();
		if(!visited[farm]) {
			process(farm);
			cost += dist;
		}
	}
	cout << cost << endl;
}