/*

TASK: contact
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int freq[5000][13];
string built_string[5000][13];

bool comp(string a, string b) {
	if(a.size() == b.size()) {
		for(int i = 0; i < a.size(); i++) {
			if(a[i] == '1' && b[i] == '0') return false;
			if(a[i] == '0' && b[i] == '1') return true;
		}
	}
	return a.size() < b.size();
}

int main() {
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
	int A, B, N;
	cin >> A >> B >> N;
	string line;
	string sequence = "";
	while(getline(cin, line)) {
		sequence += line;
	}
	for(int i = 0; i < sequence.size(); i++) {
		int current_num = 0;
		string bs = "";
		for(int j = i; j < min(i + B, (int)sequence.size()); j++) {
			if(sequence[j] == '1') {
				current_num |= 1 << (j - i);
				bs += "1";
			} else bs += "0";
			if((j - i) + 1 >= A) {
				freq[current_num][(j - i) + 1]++;
				built_string[current_num][(j - i) + 1] = bs;
			}
		}
	}
	vector<string> answer_1[200001];
	for(int i = 0; i < 200001; i++)
		answer_1[i] = vector<string>();
	for(int i = 0; i <= 5000; i++) {
		for(int j = B; j >= A; j--) {
			if(freq[i][j]) {
				answer_1[freq[i][j]].push_back(built_string[i][j]);
			}
		}
	}
	int num_found = 0;
	for(int i = 200000; i >= 0 && num_found < N; i--) {
		if(answer_1[i].size()) {
			sort(answer_1[i].begin(), answer_1[i].end(), comp);
			num_found++;
			cout << i << endl;
			for(int j = 0; j < answer_1[i].size(); j++) {
				cout << answer_1[i][j];
				if((j + 1) % 6 == 0 && j != answer_1[i].size() - 1) {
					cout << endl;
				} else cout << (j == answer_1[i].size() - 1 ? "" : " ");
			}
			cout << endl;
		}
	}
}