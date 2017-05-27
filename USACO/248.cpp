#include <bits/stdc++.h>

using namespace std;

long long num_elements;
vector<long long> elements;

long long dp[300][300];
long long largest_number = -1;

long long process(long long start, long long end) {
	if(start == end)
		return elements[start];
	if(dp[start][end] != -1) return dp[start][end];
	long long answer = 0;
	for(long long i = start; i < end; i++) {
		long long left = process(start, i);
		long long right = process(i + 1, end);
		if(left == right && left != 0)
			answer = max(answer, left + 1);
	}
	largest_number = max(largest_number, answer);
	return dp[start][end] = answer;
}

int main() {
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
	memset(dp, -1, sizeof dp);
	cin >> num_elements;
	elements.resize(num_elements);
	for(long long i = 0; i < num_elements; i++)
		cin >> elements[i];
	process(0, num_elements - 1);
	cout << largest_number << endl;
}