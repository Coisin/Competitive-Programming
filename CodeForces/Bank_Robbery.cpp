#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int n;
	cin >> n;
	int answer = 0;
	for(int i = 0; i < n; i++) {
		int note;
		cin >> note;
		if(note > b && note < c) answer++;
	}
	cout << answer << endl;
}