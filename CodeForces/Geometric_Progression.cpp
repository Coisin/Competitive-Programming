#include <bits/stdc++.h>

using namespace std;

long long n, des_ratio;
vector<long long> numbers;
map<pair<long long, long long>, long long> processor;

int main() {
	cin >> n >> des_ratio;
	numbers.resize(n);
	for(long long i = 0; i < n; i++) cin >> numbers[i];
	long long total = 0;
	for(long long i = 0; i < n; i++) {
		long long current_num = numbers[i];
		if(current_num % des_ratio) {
			processor[{current_num, 1}]++;
			continue;
		}
		long long last_number = current_num / des_ratio;
		total += processor[{last_number, 2}];
		processor[{current_num, 2}] += processor[{last_number, 1}];
		processor[{current_num, 1}]++;
	}
	cout << total << endl;
}