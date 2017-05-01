#include <bits/stdc++.h>

using namespace std;

int num_people, num_edges;
vector<vector<int> > adjList;
vector<vector<int> > adjList_backwards;
vector<int> topo_sort;
vector<bool> visited;

void get_topo_sort(int u) {
	if(visited[u]) return;
	visited[u] = 1;
	for(int n : adjList[u])
		get_topo_sort(n);
	topo_sort.push_back(u);
}

void explore(int u) {
	if(visited[u]) return;
	visited[u] = 1;
	for(int n : adjList_backwards[u])
		explore(n);
}

int main() {
	cin >> num_people >> num_edges;
	while(num_people != 0 || num_edges != 0) {

		topo_sort.clear();
		adjList.assign(num_people, vector<int>());
		adjList_backwards.assign(num_people, vector<int>());
		map<string, int> name_to_vertex;

		int vertex_counter = 0;

		string name;
		getline(cin, name);

		for(int i = 0; i < num_people; i++) {
			getline(cin, name);
			name_to_vertex[name] = vertex_counter++;
		}
		for(int i = 0; i < num_edges; i++) {
			string name1, name2;
			getline(cin, name1);
			getline(cin, name2);
			adjList[name_to_vertex[name1]].push_back(name_to_vertex[name2]);
			adjList_backwards[name_to_vertex[name2]].push_back(name_to_vertex[name1]);
		}

		int num_scc = 0;
		visited.assign(num_people, 0);
		for(int i = 0; i < num_people; i++)
			if(!visited[i])
				get_topo_sort(i);

		visited.assign(num_people, 0);
		for(int i = num_people - 1; i >= 0; i--)
			if(!visited[topo_sort[i]]) {
				num_scc++;
				explore(topo_sort[i]);
			}

		cout << num_scc << endl;

		cin >> num_people >> num_edges;
	}
}