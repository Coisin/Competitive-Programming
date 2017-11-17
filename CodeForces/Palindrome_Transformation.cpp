#include <bits/stdc++.h>

using namespace std;

int n, p;

int main() {
	string s;
	cin >> n >> p;
	cin >> s;
	int answer = 0;
	int l_most = n + 1;
	int r_most = -1;
	for(int l = 0; l < (n + 1) / 2; l++) {
		int r = n - l - 1;
		int dist = abs(s[r] - s[l]);
		dist = min(dist, abs(s[l] - 'a') + 1 + abs('z' - s[r]));
		dist = min(dist, abs(s[r] - 'a') + 1 + abs('z' - s[l]));
		answer += dist;
		if(!dist)
			continue;
		l_most = min(l_most, l);
		r_most = max(r_most, l);
	}
	if(r_most == -1) {
		cout << 0 << endl;
		return 0;
	}
	l_most++;
	r_most++;
	if(p > (n + 1) / 2)
		p = (n - p) + 1;
	int length = abs(p - l_most) + abs(r_most - l_most);
	length = min(length, abs(p - r_most) + abs(r_most - l_most));
	answer += length;

	cout << answer << endl;
}