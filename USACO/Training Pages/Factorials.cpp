/*

TASK: fact4
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("fact4.in", "r", stdin);
	//freopen("fact4.out", "w", stdout);
	long long n;
	cin >> n;
	long long answer = n;
	while(answer % 10 == 0) answer /= 10;
	answer %= 10;
	for(long long i = n - 1; i > 0; i--) {
		answer *= (n - i);
		while(answer % 10 == 0) answer /= 10;
		answer %= 1000;
	}
	cout << (answer % 10) << endl;
}