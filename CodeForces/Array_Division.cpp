#include <bits/stdc++.h>

using namespace std;

int main() {
	long long array_size;
	cin >> array_size;
	long long sequence[array_size], prefix_array[array_size];
	for(long long i = 0; i < array_size; i++) {
		cin >> sequence[i];
		if(i == 0) prefix_array[i] = sequence[i];
		else prefix_array[i] = prefix_array[i - 1] + sequence[i];
	}
	if(prefix_array[array_size - 1] % 2) {
		cout << "NO" << endl;
		return 0;
	}
	long long desired = prefix_array[array_size - 1] / 2;
	for(long long i = 0; i < array_size; i++) {
		long long current = sequence[i];
		if(prefix_array[i] == desired) {
			cout << "YES" << endl;
			return 0;
		}
		if(binary_search(prefix_array + i, prefix_array + array_size, desired + current)) {
			cout << "YES" << endl;
			return 0;
		}
		if(binary_search(prefix_array, prefix_array + i, desired - current)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}