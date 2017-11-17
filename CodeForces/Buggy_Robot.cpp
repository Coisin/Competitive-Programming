#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int U, D, L, R;
	int count[] = {0, 0, 0, 0};
	string seq;
	cin >> seq;
	for(int i = 0; i < n; i++)
		if(seq[i] == 'U')
			count[0]++;
		else if(seq[i] == 'D')
			count[1]++;
		else if(seq[i] == 'L')
			count[2]++;
		else if(seq[i] == 'R')
			count[3]++;
	int answer = (min(count[0], count[1]) + min(count[2], count[3])) * 2;
	cout << answer << endl;
}