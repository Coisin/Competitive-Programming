#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> words;
vector<vector<int> > adjList;

bool can_jump_with_deletion(string a, string b) {
	if(b.size() != a.size() + 1)
		return false;
	for(int i = 0; i < b.size(); i++) {
		int index;
		for(index = 0; index < i; index++)
			if(a[index] != b[index])
				goto test;
		for(; index < a.size(); index++)
			if(a[index] != b[index + 1])
				goto test;
		return true;
		test:
		continue;
	}
	return false;
}

bool can_jump_with_replacement(string a, string b) {
	if(a.size() != b.size())
		return false;

	bool found_character[26];
	memset(found_character, false, sizeof found_character);

	bool different = false;
	for(int i = a.size(); i >= 0; i--) {
		if(a[i] != b[i]) {
			if(different)
				return false;
			if(found_character[a[i] - 'a'] && a[i] > b[i])
				different = true;
			else return false;
		}
		found_character[b[i] - 'a'] = true;
	}
	return different;
}

bool can_jump(int i, int j) {
	string a = words[i];
	string b = words[j];
	if(a == b)
		return false;
	if(can_jump_with_replacement(b, a))
		return true;
	if(a.size() > b.size() && can_jump_with_deletion(b, a))
		return true;
	return false;
}

vector<int> topSort;
bool visited[101];
int dist[101];

void explore(int u) {
	if(visited[u])
		return;
	visited[u] = true;
	for(int ne : adjList[u])
		explore(ne);
	topSort.push_back(u);
}

int main() {
	cin >> n;
	adjList.assign(n, vector<int>() );
	words.resize(n);
	for(int i = 0; i < n; i++)
		cin >> words[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(can_jump(i, j))
				adjList[i].push_back(j);
	int answer = -1;
	for(int i = 0; i < n; i++)
		dist[i] = 1;
	for(int i = 0; i < n; i++)
		if(!visited[i])
			explore(i);
	for(int i = n - 1; i >= 0; i--) {
		int v = topSort[i];
		for(int w : adjList[v])
			if(dist[w] <= dist[v] + 1)
				dist[w] = dist[v] + 1;
	}
	for(int i = 0; i < n; i++)
		answer = max(answer, dist[i]);
	cout << answer << endl;
}