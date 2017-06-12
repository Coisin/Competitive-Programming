/*

TASK: humble
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int indexes[101];

int main() {
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	for(int i = 0; i < 101; i++)
		indexes[i] = -1;
	long long n, k;
	cin >> k >> n;
	long long primes[k];
	vector<long long> sequence;
	for(long long i = 0; i < k; i++) {
		cin >> primes[i];
	}
	sort(primes, primes + k);
	long long front;
	long long last = -100;
	for(int i = 0; i < n; i++) {
		front = -1;
		int index  = -1;
		for(int j = 0; j < k; j++) {
			long long next_number;
			if(indexes[j] == -1) {
				next_number = primes[j];
			} else next_number = primes[j] * sequence[indexes[j]];
			if(next_number <= last) {
				indexes[j]++;
				j--;
				continue;
			}
			if(front > next_number || front == -1) {
				front = next_number;
				index = j;
			}
		}
		sequence.push_back(front);
		indexes[index]++;
		last = front;
	}
	cout << front << endl;
}