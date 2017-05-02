#include <bits/stdc++.h>

using namespace std;

int num_boys, num_girls;
vector<int> boy_ages;

int main() {
	cin >> num_boys >> num_girls;
	int case_counter = 0;
	while(num_boys != 0 || num_girls != 0) {
		boy_ages.resize(num_boys);

		int girl_age; // Not necessary for problem
		for(int i = 0; i < num_boys; i++) cin >> boy_ages[i];
		for(int i = 0; i < num_girls; i++) cin >> girl_age;
		sort(boy_ages.begin(), boy_ages.end());

		cout << "Case " << ++case_counter << ": " << max(0, num_boys - num_girls);
		if(num_boys > num_girls) {
			cout << " " << boy_ages[0];
		}
		cout << endl;

		cin >> num_boys >> num_girls;
	}
}