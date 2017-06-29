#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int seq[n];
	bool vis[n];
	queue<int> q;
	int dist[n];
	for(int i = 0; i < n; i++) {
		cin >> seq[i];
		vis[i] = 0;
		if(seq[i] == 0) {
			vis[i] = 1;
			dist[i] = 0;
			q.push(i);
		}
	}
	while(!q.empty()) {
		int front = q.front(); q.pop();
		if(front > 0 && !vis[front - 1]) {
			dist[front - 1] = dist[front] + 1;
			q.push(front - 1);
			vis[front - 1] = 1;
		}
		if(front < n - 1 && !vis[front + 1]) {
			dist[front + 1] = dist[front] + 1;
			q.push(front + 1);
			vis[front + 1] = 1;
		}
	}
	for(int i = 0; i < n; i++)
		cout << dist[i] << " ";
	cout << endl;
}