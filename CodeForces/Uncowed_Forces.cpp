#include <bits/stdc++.h>

using namespace std;

int main() {
	double answer = 0;
	double times[5], wrongs[5];
	double totals[5] = {500, 1000, 1500, 2000, 2500};
	int hacks, failed_hacks;
	for(int i = 0; i < 5; i++)
		cin >> times[i];
	for(int i = 0; i < 5; i++) {
		cin >> wrongs[i];
		answer += max(0.3 * totals[i], ((1 - (times[i] / 250)) * totals[i]) - (50 * wrongs[i]));
	}
	cin >> hacks >> failed_hacks;
	answer += (hacks * 100);
	answer -= (failed_hacks * 50);
	cout << answer << endl;
}