#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	int right_pointer = n - 1;
	int lowest_number = nums[0];
	int answer = 0;
	while(nums[right_pointer] <= lowest_number) {
		answer++;
		lowest_number = nums[right_pointer];
		right_pointer--;
	}
	for(int i = 0; i < right_pointer; i++)
		if(nums[i] > nums[i + 1]) {
			cout << -1 << endl;
			return 0;
		}
	if(answer == n)
		answer = 0;
	cout << answer << endl;
}