#include <bits/stdc++.h>

using namespace std;

int prefix_array_1[200001], prefix_array_2[200001];

int main() {
	int num_ranges, k, num_queries;
	cin >> num_ranges >> k >> num_queries;
	for(int i = 0; i < num_ranges; i++) {
		int s, f;
		cin >> s >> f;
		s--, f--;
		prefix_array_1[s]++;
		prefix_array_1[f + 1]--;
	}
	for(int i = 1; i < 200001; i++)
		prefix_array_1[i] += prefix_array_1[i - 1];
	for(int i = 0; i < 200001; i++)
		if(prefix_array_1[i] >= k)
			prefix_array_2[i]++;
	for(int i = 1; i < 200001; i++)
		prefix_array_2[i] += prefix_array_2[i - 1];
	for(int i = 0; i < num_queries; i++) {
		int s, f;
		cin >> s >> f;
		s--, f--;
		cout << (prefix_array_2[f] - (s == 0 ? 0 : prefix_array_2[s - 1])) << endl;
	}
}