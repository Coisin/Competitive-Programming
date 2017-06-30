#include <bits/stdc++.h>

using namespace std;

int main() {
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int pos = 1;
	int speed = v0;
	int answer = 0;
	while(pos <= c) {
		answer++;
		pos = max(1, pos - l);
		pos += speed;
		speed += a;
		if(speed > v1) speed = v1;
	}
	cout << answer << endl;
}