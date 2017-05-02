#include <bits/stdc++.h>

using namespace std;

int num_crossings, num_broken, desired;
bitset<200001> lights;

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	cin >> num_crossings >> desired >> num_broken;
	for(int i = 0; i < num_broken; i++) {
		int a;
		cin >> a;
		a--;
		lights[a] = 1;
	}
	int required = 0;
	int answer = 1000000000;
	for(int i = 0; i < num_crossings; i++) {
		required += lights[i];
		if(i >= desired) {
			required -= lights[i - desired];
			answer = min(answer, required);
		}
	}
	cout << answer;
}