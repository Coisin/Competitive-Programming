#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		int m;
		for(m = 1; m * m < s.size(); m++);
		for(; s.size() < m * m; s += "*");
		for(int col = 0; col < m; col++)
			for(int row = m - 1; row >= 0; row--) {
				int index = (row * m) + col;
				if(s[index] != '*')
					cout << s[index];
			}
		cout << endl;
	}
}