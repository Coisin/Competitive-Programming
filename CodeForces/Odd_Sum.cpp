#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_elements;
	vector<int> sequence;
	vector<int> evens, odds;

	cin >> num_elements;
	sequence.resize(num_elements);
	for(int i = 0; i < num_elements; i++) {
		cin >> sequence[i];
		if(sequence[i] & 1) odds.push_back(sequence[i]);
		else evens.push_back(sequence[i]);
	}
	sort(evens.rbegin(), evens.rend());
	sort(odds.rbegin(), odds.rend());
	int sum = 0;
	int odd_index, even_index;
	odd_index = even_index = 0;
	while(true) {
		int front_even, front_odd;
		if(odd_index < odds.size())
			front_odd = odds[odd_index];
		if(even_index < evens.size())
			front_even = evens[even_index];
		if(sum % 2 == 0 && odd_index < odds.size()) {
			odd_index++;
			sum += front_odd;
		} else if(even_index < evens.size() && front_even >= 0) {
			even_index++;
			sum += front_even;
		} else if(odd_index < odds.size() - 1 && (front_odd + odds[odd_index + 1]) >= 0) {
			sum += front_odd + odds[odd_index + 1];
			odd_index += 2;
		} else break;
	}
	if((even_index == odd_index && odd_index == 0) || sum % 2 == 0)
		cout << -1 << endl;
	else cout << sum << endl;
}