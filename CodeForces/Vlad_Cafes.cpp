#include <bits/stdc++.h>

using namespace std;

int last_visit[200001];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		last_visit[a] = i + 1;
	}
	int a = -1;
	for(int i = 0; i < 200001; i++) {
		if(last_visit[i] && (last_visit[i] < last_visit[a] || a == -1)) {
			a = i;
		}
	}
	cout << a << endl;
}