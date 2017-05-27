#include <bits/stdc++.h>

using namespace std;

int m;
int best_answer = 1000000000;

int best_at[40000];

void recurse(int n, int moves) {
	if(n == m) {
		best_answer = min(best_answer, moves);
		return;
	}
	if(moves >= best_answer) return;

	if(best_at[n] != -1 && moves > best_at[n]) return;
	best_at[n] = moves;

	int answer = 1000000000;
	if(n < m) {
		recurse(n * 2, moves + 1);
		recurse(n - 1, moves + 1);
	}
	else
		recurse(m, moves + (n - m));
}

int main() {
	memset(best_at, -1, sizeof best_at);
	int n;
	cin >> n >> m;
	recurse(n, 0);
	cout << best_answer << endl;
}