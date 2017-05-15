#include <bits/stdc++.h>

using namespace std;

int main() {
	long long num_elements;
	cin >> num_elements;
	long long prefix_array[num_elements];
	long long numbers[num_elements];
	for(long long i = 0; i < num_elements; i++) {
		cin >> prefix_array[i];
		numbers[i] = prefix_array[i];
		prefix_array[i] += i == 0 ? 0 : prefix_array[i - 1];
	}
	if(prefix_array[num_elements - 1] % 2) {
		cout << "NO" << endl;
		return 0;
	}
	long long wanted = prefix_array[num_elements - 1] / 2;
	for(long long i = 0; i < num_elements; i++) {
		if(prefix_array[i] > wanted && binary_search(prefix_array, prefix_array + i + 1, wanted - numbers[i])) {
			cout << "YES" << endl;
			return 0;
		} else if(prefix_array[i] < wanted && binary_search(prefix_array + i + 1, prefix_array + num_elements, wanted + numbers[i])) {
			cout << "YES" << endl;
			return 0;
		} else if(prefix_array[i] == wanted) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}