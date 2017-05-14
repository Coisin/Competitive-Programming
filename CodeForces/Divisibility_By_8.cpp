#include <bits/stdc++.h>

using namespace std;

string number;
bool visited[101][8];

void process(int pos, int sum, string answer) {
	if(sum == 0 && answer != "") {
		cout << "YES" << endl;
		cout << answer << endl;
		exit(0);
	}
	if(pos == number.size()) return;
	if(visited[pos][sum]) return;
	visited[pos][sum] = true;
	process(pos + 1, (sum * 10 + (number[pos] - '0')) % 8, answer + number[pos]);
	process(pos + 1, sum, answer);
}

int main() {
	cin >> number;
	process(0, 0, "");
	cout << "NO" << endl;
}