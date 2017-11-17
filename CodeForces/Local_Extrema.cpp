#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int seq[n];
	int answer = 0;
	for(int i = 0; i < n; i++)
		cin >> seq[i];
	for(int i = 1; i < n - 1; i++)
		if((seq[i - 1] > seq[i] && seq[i + 1] > seq[i]) || (seq[i - 1] < seq[i] && seq[i + 1] < seq[i]))
			answer++;
	cout << answer << endl;
}