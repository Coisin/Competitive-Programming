#include <bits/stdc++.h>

using namespace std;

int num_schools;

int mod(int i) {
	return i % (num_schools + 1);
}

int main() {
	cin >> num_schools;
	int cost = 0;
	int current_vertex = 1;
	bool visited[num_schools + 1];
	memset(visited, false, sizeof visited);
	while(true) {
		visited[current_vertex] = true;
		int neighbour = (num_schools - current_vertex) + 1;
		if(visited[neighbour]) {
			if(visited[neighbour + 1] && visited[current_vertex - 1]) break;
			if(mod(neighbour + 1 + current_vertex) < mod((current_vertex - 1) + current_vertex)) {
				cost += mod(neighbour + 1 + current_vertex);
				current_vertex = neighbour + 1;
			} else {
				cost += mod((current_vertex - 1) + current_vertex);
				current_vertex = current_vertex - 1;
			}
		} else {
			current_vertex = neighbour;
		}
	}
	cout << cost;
}