#include <bits/stdc++.h>

using namespace std;

int length, desired_sum;

map<pair<int, int>, pair<string, string> > dp;

pair<string, string> process(int pos, int sum) {
	if(pos == length) {
		if(sum == desired_sum) {
			return {"", ""};
		}
		return {"-", "-"};
	}
	if(sum > desired_sum) return {"-", "-"};
	
	if(dp.find({pos, sum}) != dp.end()) return dp[{pos, sum}];
	pair<string, string> answer = {"-", "-"};
	string str = "";
	for(char i = '0'; i <= '9'; i++) {
		pair<string, string> next_pair = process(pos + 1, sum + i - '0');
		if(next_pair.first == "-") continue;
		answer.second = str + i + next_pair.second;
		if(answer.first == "-") answer.first = str + i + next_pair.first;
	}
	return dp[{pos, sum}] = answer;
}

int main() {
	cin >> length >> desired_sum;
	if(desired_sum == 0) {
		if(length == 1)
			cout << 0 << " " << 0 << endl;
		else 
			cout << -1 << " " << -1 << endl;
	} else {
		pair<string, string> answer = {"-", "-"};
		string str = "";
		for(char i = '1'; i <= '9'; i++) {
			pair<string, string> next_pair = process(1, i - '0');
			if(next_pair.first == "-") continue;
			answer.second = str + i + next_pair.second;
			if(answer.first == "-") answer.first = str + i + next_pair.first;
		}
		if(answer.first == "-") answer.first = answer.second = "-1";
		cout << answer.first << " " << answer.second << endl;
	}
}