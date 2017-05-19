#include <bits/stdc++.h>

using namespace std;

int main() {
	int n_power;
	cin >> n_power;
	int num_numbers = 1 << n_power;
	vector<int> numbers(num_numbers);
	vector<int> initial_state(num_numbers);
	for(int i = 0; i < num_numbers; i++) {
		cin >> numbers[i];
		initial_state[i] = numbers[i];
	}
	map<int, int> answers;
	sort(numbers.begin(), numbers.end());
	for(int i = 0; i < num_numbers; i++) {
		if(answers.find(numbers[i]) == answers.end()) answers[numbers[i]] = n_power;
		answers[numbers[i]] = min(answers[numbers[i]], n_power - (int)(log10(i + 1) / log10(2)));
	}
	for(int i = 0; i < num_numbers; i++)
		cout << answers[initial_state[i]] << " ";
}