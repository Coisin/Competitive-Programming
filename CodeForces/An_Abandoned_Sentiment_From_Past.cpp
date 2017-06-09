#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int sequence[n];
	int replace[k];
	for(int i = 0; i < n; i++)
		cin >> sequence[i];
	for(int i = 0; i < k; i++)
		cin >> replace[i];
	sort(replace, replace + k);
	int k_counter = k - 1;
	for(int i = 0; i < n; i++)
		if(sequence[i] == 0) {
			sequence[i] = replace[k_counter];
			k_counter--;
		}
	for(int i = 1; i < n; i++)
		if(sequence[i] < sequence[i - 1]) {
			cout << "Yes" << endl;
			return 0;
		}
	cout << "No" << endl;
}