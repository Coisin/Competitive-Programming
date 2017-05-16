#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_people;
	cin >> num_people;
	string people;
	cin >> people;
	queue<int> d, r;
	for(int i = 0; i < num_people; i++)
		if(people[i] == 'D') d.push(i);
		else r.push(i);
	while(!d.empty() && !r.empty()) {
		int front_d = d.front(); d.pop();
		int front_r = r.front(); r.pop();
		if(front_d < front_r) d.push(front_d + num_people);
		else r.push(front_r + num_people);
	}
	cout << (d.empty() ? "R" : "D") << endl;
}