/*

TASK: comehome
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);

	int num_paths;
	vector<pair<int, int> > adjList[52];
	cin >> num_paths;
	while(num_paths--) {
		char a, b;
		int d;
		cin >> a >> b >> d;
		if(a >= 'a') {
			a -= 'a';
			a += 26;
		}
		else a -= 'A';
		if(b >= 'a') {
			b -= 'a';
			b += 26;
		}
		else b -= 'A';
		adjList[a].push_back({b, d});
		adjList[b].push_back({a, d});
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	int dist[52];
	for(int i = 0; i < 52; i++)
		dist[i] = 1000000000;
	dist[25] = 0;
	pq.push({0, 25});
	while(!pq.empty()) {
		int distance = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if(dist[vertex] < distance) continue;
		if(vertex < 25) {
			vertex += 'A';
			cout << (char)vertex << " " << distance << endl;
			break;
		}
		for(pair<int, int> n : adjList[vertex]) {
			int new_dist = distance + n.second;
			if(dist[n.first] > new_dist) {
				dist[n.first] = new_dist;
				pq.push({new_dist, n.first});
			}
		}
	}
}