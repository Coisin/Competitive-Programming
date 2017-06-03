#include <bits/stdc++.h>

using namespace std;

int num_trees;
vector<pair<int, int> > trees;

int dp[100001][2];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int process(int pos, bool can_left) {
	if(pos == num_trees) return 0;
	if(dp[pos][can_left] != -1) return dp[pos][can_left];

	int next_tree = pos +  1;
	bool next_can_left = false;
	if(next_tree < num_trees && trees[next_tree].first - trees[next_tree].second > trees[pos].first)
		next_can_left = true;
	int answer = can_left + process(next_tree, next_can_left);

	next_can_left = false;
	bool can_use = true;
	if(next_tree < num_trees && trees[next_tree].first <= trees[pos].first + trees[pos].second) can_use = false;
	next_tree = (lower_bound(trees.begin(), trees.end(), make_pair(trees[pos].first + trees[pos].second + 1, 0), cmp) - trees.begin());
	if(next_tree < num_trees && trees[next_tree].first - trees[next_tree].second > trees[pos].first + trees[pos].second)
		next_can_left = true;
	answer = max(answer, can_use + process(next_tree, next_can_left));
	return dp[pos][can_left] = answer;
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> num_trees;
	for(int i = 0; i < num_trees; i++) {
		int x, h;
		cin >> x >> h;
		trees.push_back({x, h});
	}
	cout << process(0, 1) << endl;
}