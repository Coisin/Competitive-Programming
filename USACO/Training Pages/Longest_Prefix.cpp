/*

PROB: prefix
LANG: C++11

 */

#include <bits/stdc++.h>

using namespace std;

set<string> partials;
string s="";

int dp[201000];

int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	string partial;
	while(cin >> partial && partial != ".")
		partials.insert(partial);
	while(cin >> partial)
		s += partial;
	for(int i = s.length() - 1; i >= 0; i--) {
		string current_partial = "";
		for(int j = i; j < (int)min(i + 10, (int)s.length()); j++) {
			current_partial += s[j];
			if(partials.count(current_partial)) {
				dp[i] = max(dp[i], (int)current_partial.length() + dp[j + 1]);
			}
		}
	}
	cout << dp[0] << endl;
}