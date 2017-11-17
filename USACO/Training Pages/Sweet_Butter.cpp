/*

TASK: butter
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int num_cows, num_fields, num_paths;
vector<int> cows_in_field;
vector<vector<pair<int, int> > > adjList;

int distan[801];

int main() {
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	cin >> num_cows >> num_fields >> num_paths;
	cows_in_field.assign(num_fields, 0);
	adjList.assign(num_fields, vector<pair<int, int> >());
	for(int i = 0; i < num_cows; i++) {
		int a;
		cin >> a;
		a--;
		cows_in_field[a]++;
	}
	for(int i = 0; i < num_paths; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		adjList[a].push_back({b, w});
		adjList[b].push_back({a, w});
	}
	for(int i = 0; i < num_fields; i++) {
		if(!cows_in_field[i])
			continue;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		int dist[num_fields];
		for(int j = 0; j < num_fields; j++)
			dist[j] = 10000000;

		dist[i] = 0;
		pq.push({0, i});

		while(!pq.empty()) {
			int d = pq.top().first;
			int u = pq.top().second; pq.pop();
			if(dist[u] < d)
				continue;
			for(pair<int, int> n : adjList[u]) {
				if(d + n.second < dist[n.first]) {
					dist[n.first] = d + n.second;
					pq.push({dist[n.first], n.first});
				}
			}
		}
		for(int j = 0; j < num_fields; j++)
			distan[j] += cows_in_field[i] * dist[j];
	}
	int minimum_walk = 10000000;
	for(int i = 0; i < num_fields; i++)
		minimum_walk = min(distan[i], minimum_walk);
	cout << minimum_walk << endl;
}