#include <bits/stdc++.h>

using namespace std;

string s;

bool process(int k) {
	bool has_character[26];
	int visited[26];
	memset(has_character, 0, sizeof has_character);
	memset(visited, 0, sizeof visited);
	for(int i = 0; i < k; i++)
		has_character[s[i] - 'a'] = true;
	for(int i = 0; i < s.size(); i++) {
		if(i >= k) {
			visited[s[i - k] - 'a']--;
		}
		visited[s[i] - 'a']++;
		if(i >= k - 1) {
			for(int j = 0; j < 26; j++)
				has_character[j] &= visited[j] > 0;
		}
	}
	for(int i = 0; i < 26; i++)
		if(has_character[i])
			return true;
	return false;
}

int main() {
	cin >> s;
	int L = 1;
	int R = s.size();
	while(L != R) {
		int M = (L + R) / 2;
		if(process(M))
			R = M;
		else
			L = M + 1;
	}
	cout << L << endl;
}