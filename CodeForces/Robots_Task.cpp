#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_computers;
	cin >> num_computers;
	int requirement[num_computers];
	for(int i = 0; i < num_computers; i++) cin >> requirement[i];
		if(num_computers == 1) {
			cout << 0 << endl;
			return 0;
		}

	int pos = 0;
	bool direction = true;
	int num_turns = 0;
	int num_info = 0;
	while(true) {
		if(requirement[pos] != -1 && num_info >= requirement[pos]) {
			requirement[pos] = -1;
			num_info++;
			if(num_info == num_computers) {
				if(pos == 0) num_turns--;
				if(pos == num_computers - 1) num_turns--;
				break;
			}
		}
		if(direction) pos++;
		else pos--;
		if(pos == 0) {
			direction = true;
			num_turns++;
		} else if(pos == num_computers - 1) {
			direction = false;
			num_turns++;
		}
	}
	cout << num_turns << endl;
}