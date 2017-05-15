#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > cup_vols, answer;
int num_cups;
bool visited[101][101][10001];

bool process(int pos, int minimum, int to_pour) {
	if(pos == num_cups) return to_pour == 0;
	if(to_pour <= 0) return false;
	if(visited[pos][minimum][to_pour]) return false;
	visited[pos][minimum][to_pour] = true;
	for(int i = max(minimum, (cup_vols[pos].first + 1) / 2); i <= cup_vols[pos].first; i++) {
		if(process(pos + 1, i, to_pour - i)) {
			answer.push_back({cup_vols[pos].second, i});
			return true;
		}
	}
	return false;
}

int main() {
	int teapot_vol;
	cin >> num_cups >> teapot_vol;
	for(int i = 0; i < num_cups; i++) {
		int vol;
		cin >> vol;
		cup_vols.push_back({vol, i});
	}
	sort(cup_vols.begin(), cup_vols.end());
	if(process(0, 0, teapot_vol)) {
		sort(answer.begin(), answer.end());
		for(int i = 0; i < num_cups; i++)
			cout << answer[i].second << " ";
	} else cout << -1 << endl;
}