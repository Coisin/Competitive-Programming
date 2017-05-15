#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_days, week_length;
	cin >> num_days >> week_length;
	int sleeps[num_days];
	double sleep = 0;
	double current_week = 0;
	for(int i = 0; i < num_days; i++) {
		cin >> sleeps[i];
		current_week += sleeps[i];
		if(i >= week_length) current_week -= sleeps[i - week_length];
		if(i >= week_length - 1) sleep += current_week;
	}
	sleep /= num_days - week_length + 1;
	cout << setprecision(20) << sleep << endl;
}