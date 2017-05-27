#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y, z;
	int n;
	cin >> x >> y;
	cin >> n;
	z = y - x;
	n--;
	int digit = n % 3;
	int answer;
	if(digit == 0)
		answer = x;
	else if(digit == 1)
		answer = y;
	else if(digit == 2)
		answer = z;
	if((n / 3) % 2)
		answer *= -1;
	if(answer < 0)
		while(answer < 0) answer += 1000000007;
	else answer %= 1000000007;
	cout << answer << endl;
}