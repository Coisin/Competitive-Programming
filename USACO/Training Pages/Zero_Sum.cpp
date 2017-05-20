/*

PROB: zerosum
LANG: C++11

 */

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> answer;

void process(int pos, int sum, int sign) {

	if(pos == n + 1) {
		if(sum == 0) {
			for(int i = 1; i <= n; i++) {
				if(i == 1) {
					cout << i;
					continue;
				}
				int sign = answer[i - 1];
				if(sign == 1)
					cout << "+";
				else if(sign == -1)
					cout << "-";
				else cout << " ";
				cout << i;
			}
			cout << endl;
		}
		return;
	}

	int number = pos;
	answer.push_back(sign);

	for(int i = pos + 1; i <= n; i++) {
		number = (number * 10) + i;
		answer.push_back(0);

		process(i + 1, sum + (number * sign), 1);
		if(i != n) process(i + 1, sum + (number * sign), -1);
	}
	for(int i = pos; i <= n; i++)
		answer.pop_back();

	number = pos;
	answer.push_back(sign);
	process(pos + 1, sum + (number * sign), 1);
	if(pos != n) process(pos + 1, sum + (number * sign), -1);
	answer.pop_back();
}

int main() {
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	cin >> n;
	process(1, 0, 1);

}