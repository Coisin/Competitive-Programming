#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	bool hit_1 = false;
	int zeroes = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1')
			hit_1 = true;
		if(hit_1 && s[i] == '0')
			zeroes++;
	}
	cout << (zeroes >= 6 ? "yes" : "no") << endl;
}