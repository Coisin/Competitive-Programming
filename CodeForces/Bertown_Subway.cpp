#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> p;

vector<long long> visited;
vector<long long> component_sizes;

long long explore(long long current_node) {
	if(visited[current_node])
		return 0;
	visited[current_node] = 1;
	return 1 + explore(p[current_node]);
}

int main() {
	cin >> n;
	p.resize(n);
	for(long long i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}

	visited.assign(n, 0);

	for(long long i = 0; i < n; i++)
		if(!visited[i])
			component_sizes.push_back(explore(i));

	long long convenience = 0;

	sort(component_sizes.rbegin(), component_sizes.rend());

	for(long long i = 0; i < component_sizes.size(); i++) {
		long long component_size = component_sizes[i];
		if(i == 0 && component_sizes.size() > 1) {
			i++;
			component_size += component_sizes[i];
		}
		convenience += component_size * component_size;
	}

	cout << convenience << endl;
}