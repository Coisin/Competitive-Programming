#include <bits/stdc++.h>

using namespace std;

int num_flowers, num_choices;
vector<int> values;

int main() {
	cin >> num_flowers >> num_choices;
	values.resize(num_flowers);
	for(int i = 0; i < num_flowers; i++)
		cin >> values[i];
	int answer = 0;
	for(int i = 0; i < num_choices; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int sum = 0;
		for(int j = l; j <= r; j++)
			sum += values[j];
		answer += max(0, sum);
	}
	cout << answer << endl;
}