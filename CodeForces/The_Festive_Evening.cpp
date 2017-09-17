#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_guests, num_guards;
	cin >> num_guests >> num_guards;
	string seq;
	cin >> seq;
	int first[26], last[26];
	memset(first, -1, sizeof first);
	memset(last, -1, sizeof last);
	for(int i = 0; i < num_guests; i++) {
		if(first[seq[i] - 'A'] == -1)
			first[seq[i] - 'A'] = i;
		last[seq[i] - 'A'] = i;
	}
	for(int i = 0; i < num_guests; i++) {
		int count = 0;
		for(int j = 0; j < 26; j++)
			if(first[j] <= i && last[j] >= i)
				count++;
		if(count > num_guards) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}