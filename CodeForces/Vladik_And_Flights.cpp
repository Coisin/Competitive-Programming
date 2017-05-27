#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_airports, start, finish;
	cin >> num_airports >> start >> finish;
	start--, finish--;
	string sequence;
	cin >> sequence;
	int val_fin, val_start;
	for(int i = 0; i < num_airports; i++) {
		int a = sequence[i] - '0';
		cin >> a;
		if(i == start)
			val_start = a;
		if(i == finish)
			val_fin = a;
	}
	if(val_fin == val_start) {
		cout << 0 << endl;
	} else cout << 1 << endl;
}