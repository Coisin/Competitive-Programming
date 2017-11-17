#include <bits/stdc++.h>

using namespace std;

int people[6];
int sum = 0;

void process(int person, int s, int people_counted) {
	if(person == 6) {
		if(s == sum / 2 && people_counted == 3) {
			cout << "YES" << endl;
			exit(0);
		}
		return;
	}
	process(person + 1, s + people[person], people_counted + 1);
	process(person + 1, s, people_counted);
}

int main() {
	cin >> people[0] >> people[1] >> people[2] >> people[3] >> people[4] >> people[5];
	sum = people[0] + people[1] + people[2] + people[3] + people[4] + people[5];
	if(sum % 2) {
		cout << "NO" << endl;
	} else {
		process(0, 0, 0);
		cout << "NO" << endl;
	}
}