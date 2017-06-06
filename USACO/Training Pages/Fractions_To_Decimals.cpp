/* 

TASK: fracdec
LANG: C++11

*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	string numerator;
	int denominator;
	cin >> numerator >> denominator;
	int dividing = 0;
	vector<int> divider;
	int visited[2000000];
	int repeats = -1;
	for(int i = 0; ; i++) {
		if(dividing == 0 && i >= numerator.size()) break;
		dividing *= 10;
		if(i < numerator.size()) {
			dividing += numerator[i] - '0';
		}
		if(i >= numerator.size()) {
			if(visited[dividing]) {
				repeats = visited[dividing];
				break;
			} else visited[dividing] = i;
		}
		divider.push_back(dividing / denominator);
		dividing %= denominator;
	}
	string answer = "";
	int i;
	for(i = 0; divider[i] == 0 && i < numerator.size() - 1; i++);
	for(; i < divider.size(); i++) {
		if(repeats == i) {
			if(i == numerator.size())
				answer += ".";
			answer += "(" + to_string(divider[i]);
		} else if(i == numerator.size()) answer += "." + to_string(divider[i]);
		else answer += to_string(divider[i]);
		if(repeats != -1 && i == divider.size() - 1)
			answer += ")";
	}
	if(i == numerator.size())
		answer += ".0";
	while(answer.size() > 76) {
		string x = answer.substr(0, 76);
		answer.erase(0, 76);
		cout << x << endl;
	}
	cout << answer << endl;
}