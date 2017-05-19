#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_phones, d;
	cin >> num_phones >> d;
	int last_phone = 0;
	int answer = 0;
	for(int i = 0; i < num_phones; i++) {
		int phone;
		cin >> phone;
		if(phone) last_phone = i;
		else if(i - last_phone >= d) {
			last_phone = i;
			answer++;
		}
	}
	cout << answer << endl;
}