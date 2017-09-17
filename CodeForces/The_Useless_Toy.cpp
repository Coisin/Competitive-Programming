#include <bits/stdc++.h>

using namespace std;

int get_num(char c) {
	if(c == '^') return 0;
	if(c == '>') return 1;
	if(c == '<') return 3;
	return 2;
}

int main() {
	int pos_a, pos_b;
	int end;
	long long seconds;
	char c1, c2;
	cin >> c1 >> c2;
	cin >> seconds;
	pos_a = get_num(c1);
	pos_b = get_num(c1);
	end = get_num(c2);
	seconds %= 4;
	while(seconds--) {
		pos_a++;
		pos_b--;
		if(pos_a == 4)
			pos_a = 0;
		if(pos_b == -1)
			pos_b = 3;
	}
	if(pos_a == pos_b)
		cout << "undefined" << endl;
	else if(pos_a == end)
		cout << "cw" << endl;
	else cout << "ccw" << endl;
}