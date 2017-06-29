#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_elements, num_changes;
	cin >> num_elements >> num_changes;
	int num_zeroes[num_elements], sequence[num_elements];
	for(int i = 0; i < num_elements; i++) {
		num_zeroes[i] = i == 0 ? 0 : num_zeroes[i - 1];
		cin >> sequence[i];
		if(sequence[i] == 0)
			num_zeroes[i]++;
	}
	int L, R;
	L = R = 0;
	int ans_R = -1;
	int ans_L = -1;
	int answer = 0;
	while(L < num_elements && R < num_elements) {
		int zero_count = num_zeroes[R] - (L == 0 ? 0 : num_zeroes[L - 1]);
		if(zero_count > num_changes)
			if(L < R)
				L++;
			else L++, R++;
		else {
			if((R - L) + 1 > answer) {
				answer = (R - L) + 1;
				ans_R = R;
				ans_L = L;
			}
			R++;
		}
	}
	cout << answer << endl;
	for(int i = 0; i < num_elements; i++)
		if(i < ans_L || i > ans_R)
			cout << sequence[i] << " ";
		else cout << 1 << " ";
	cout << endl;
}