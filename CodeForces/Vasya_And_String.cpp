#include <bits/stdc++.h>

using namespace std;

int sequence_length, num_changes;
string sequence;
int prefix_a[100000], prefix_b[100000];

int main() {
	cin >> sequence_length >> num_changes;
	cin >> sequence;
	for(int i = 0; i < sequence_length; i++) {
		prefix_a[i] = i == 0 ? 0 : prefix_a[i - 1];
		prefix_b[i] = i == 0 ? 0 : prefix_b[i - 1];
		if(sequence[i] == 'a') prefix_a[i]++;
		else prefix_b[i]++;
	}
	int left, right;
	left = right = 0;
	int maximum = 0;

	while(right < sequence_length) {
		int num_a, num_b;
		num_a = prefix_a[right] - (left > 0 ? prefix_a[left - 1] : 0);
		num_b = prefix_b[right] - (left > 0 ? prefix_b[left - 1] : 0);

		if(num_a > num_changes) left++;
		else {
			maximum = max(maximum, (right - left) + 1);
			right++;
		}
	}

	left = right = 0;
	while(right < sequence_length) {
		int num_a, num_b;
		num_a = prefix_a[right] - (left > 0 ? prefix_a[left - 1] : 0);
		num_b = prefix_b[right] - (left > 0 ? prefix_b[left - 1] : 0);

		if(num_b > num_changes) left++;
		else {
			maximum = max(maximum, (right - left) + 1);
			right++;
		}
	}
	cout << maximum << endl;
}