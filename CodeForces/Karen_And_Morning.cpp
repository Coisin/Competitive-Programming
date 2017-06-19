#include <bits/stdc++.h>

using namespace std;

bool is_pal(int a, int b) {
	int a1 = a % 10;
	int a2 = a / 10;
	int b1 = b % 10;
	int b2  = b / 10;
	return a1 == b2 && b1 == a2;
}

int main() {
	int h1, m1;
	char t;
	cin >> h1 >> t >> m1;
	int answer = 0;
	while(!is_pal(h1, m1)) {
		m1++;
		answer++;
		if(m1 == 60) {
			m1 = 0;
			h1++;
		}
		if(h1 == 24) {
			h1 = 0;
		}
	}
	cout << answer << endl;
}