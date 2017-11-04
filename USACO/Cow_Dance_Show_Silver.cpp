#include <bits/stdc++.h>

using namespace std;

int n, t_max;
vector<int> cows;

bool works(int k) {
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i = 0; i < k; i++)
		pq.push(cows[i]);
	int index = k;
	int time = 0;
	while(!pq.empty()) {
		int top = pq.top(); pq.pop();
		time = top;
		if(index < n)
			pq.push(top + cows[index++]);
	}
	return time <= t_max;
}

int main() {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	cin >> n >> t_max;
	cows.resize(n);
	for(int i = 0; i < n; i++)
		cin >> cows[i];
	int L = 1;
	int R = n;
	while(L != R) {
		int M = (L + R) / 2;
		if(works(M)) {
			R = M;
		} else {
			L = M + 1;
		}
	}
	cout << L << endl;
}