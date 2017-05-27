#include <bits/stdc++.h>

using namespace std;

set<pair<long long, pair<long long, long long> > > vis;
long long n, a, b, c;
long long best_answer = 10000000000000;

void process(long long ba, long long bb, long long bc, long long depth) {
	if(depth > 5) return;
	if((ba + bb * 2 + bc * 3 + n) % 4 == 0) {
		best_answer = min(best_answer,  (a * ba) + (b * bb) + (c * bc));
		return;
	}

	if(vis.count({ba, {bb, bc}})) return;
	vis.insert({ba, {bb, bc}});

	if((a * ba) + (b * bb) + (c * bc) >= best_answer) return;

	process(ba + 1, bb, bc, depth + 1);
	process(ba, bb + 1, bc, depth + 1);
	process(ba, bb, bc + 1, depth + 1);
}

int main() {
	cin >> n >> a >> b >> c;
	process(0, 0, 0, 0);
	cout << best_answer << endl;
}