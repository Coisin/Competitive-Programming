#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_groups;
	int vacant_one, vacant_two, one_at_two;
	cin >> num_groups >> vacant_one >> vacant_two;
	int groups[num_groups];
	for(int i = 0; i < num_groups; i++)
		cin >> groups[i];
	one_at_two = 0;
	int answer = 0;
	for(int i = 0; i < num_groups; i++) {
		if(groups[i] == 1) {
			if(vacant_one) {
				vacant_one--;
			} else if(vacant_two) {
				vacant_two--;
				one_at_two++;
			} else if(one_at_two) {
				one_at_two--;
			} else answer++;
		} else {
			if(vacant_two) {
				vacant_two--;
			} else answer+=2;
		}
	}
	cout << answer << endl;
}