#include <bits/stdc++.h>

using namespace std;

string a, b;

int dp[2101];
int left_ans[2101], right_ans[2101];
int next_place[2101];

int process(int pos_in_b) {
	if(pos_in_b == b.size())
		return 0;
	if(dp[pos_in_b] != -1) return dp[pos_in_b];
	string one = "";
	string two = "";
	int f;
	int answer = 1000000000;
	int max_length_f = -1;
	int max_left, max_right;
	for(int i = 0; i < a.size(); i++) {
		for(int j = i, f = pos_in_b; j < a.size() && f < b.size(); j++, f++) {
			char c = a[j];
			if(c != b[f])
				break;
			if(max_length_f < f) {
				max_length_f = f;
				max_left = i;
				max_right = j;
			}
		}
	}
	if(max_length_f != -1) {
		int temp_answer = 1 + process(max_length_f + 1);
		if(answer > temp_answer) {
			answer = temp_answer;
			left_ans[pos_in_b] = max_left;
			right_ans[pos_in_b] = max_right;
			next_place[pos_in_b] = max_length_f + 1;
		}
	}
	for(int i = a.size() - 1; i >= 0; i--) {
		for(int j = i, f = pos_in_b; j >= 0 && f < b.size(); j--, f++) {
			char c = a[j];
			if(c != b[f])
				break;
			if(max_length_f < f) {
				max_length_f = f;
				max_left = i;
				max_right = j;
			}
		}
	}
	if(max_length_f != -1) {
		int temp_answer = 1 + process(max_length_f + 1);
		if(answer > temp_answer) {
			answer = temp_answer;
			left_ans[pos_in_b] = max_left;
			right_ans[pos_in_b] = max_right;
			next_place[pos_in_b] = max_length_f + 1;
		}
	}
	return dp[pos_in_b] = answer;
}

void derive_path(int pos_in_b) {
	if(pos_in_b == b.size())
		return;
	cout << left_ans[pos_in_b] + 1 << " " << right_ans[pos_in_b] + 1 << endl;
	derive_path(next_place[pos_in_b]);
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> a;
	cin >> b;
	int answer = process(0);
	if(answer > 2100)
		cout << -1 << endl;
	else {
		cout << answer << endl;
		derive_path(0);
	}
}