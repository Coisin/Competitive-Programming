#include <bits/stdc++.h>

using namespace std;

int num_rows;

int main() {
	cin >> num_rows;
	int lowest = 1000000001;
	bool is_decr = true;
	for(int i = 0; i < num_rows; i++) {
		int a, b;
		cin >> a >> b;
		if(a != b) {
			cout << "rated" << endl;
			return 0;
		}
		if(lowest < a) is_decr = false;
		lowest = min(lowest, a);
	}
	if(is_decr)
		cout << "maybe" << endl;
	else 
		cout << "unrated" << endl;
}