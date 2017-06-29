#include <bits/stdc++.h>

using namespace std;

int num_devices, power_charger;
vector<double> powers, volumes;

bool is_valid(double time) {
	double to_give = time * power_charger;
	for(int i = 0; i < num_devices; i++) {
		double power = powers[i];
		double vol = volumes[i];
		vol -= power * time;
		if(vol < 0) {
			vol = -vol;
			to_give -= vol;
		}
	}
	return to_give >= 0.00;
}

int main() {
	cin >> num_devices >> power_charger;
	powers.resize(num_devices);
	volumes.resize(num_devices);
	double total_output = 0;
	for(int i = 0; i < num_devices; i++) {
		cin >> powers[i] >> volumes[i];
		total_output += powers[i];
	}
	if(total_output <= power_charger) {
		cout << -1 << endl;
		return 0;
	}
	double L, R;
	L = 0;
	R = 10000000002;
	double middle;
	for(int t = 1; t <= 80; t++) {
		middle = (L + R) / 2;
		if(is_valid(middle)) {
			L = middle;
		} else {
			R = middle;
		}
	}
	printf("%.9f\n", middle);
}