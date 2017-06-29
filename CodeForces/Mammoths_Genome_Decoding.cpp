#include <bits/stdc++.h>

using namespace std;

int counter[4];

int get_code(char c) {
	if(c == 'A') return 0;
	if(c == 'C') return 1;
	if(c == 'G') return 2;
	if(c == 'T') return 3;
	return 4;
}

char get_char(int code) {
	if(code == 0) return 'A';
	if(code == 1) return 'C';
	if(code == 2) return 'G';
	if(code == 3) return 'T';
	return '?';
}

int main() {
	int length;
	cin >> length;
	char seq[length];
	cin >> seq;
	if(length % 4) {
		cout << "===" << endl;
		exit(0);
	}
	int of_each_type = length / 4;
	for(int i = 0; i < length; i++)
		if(get_code(seq[i]) < 4)
			counter[get_code(seq[i])]++;
	for(int i = 0; i < 4; i++)
		if(counter[i] > of_each_type) {
			cout << "===" << endl;
			exit(0);
		}
	int index = 0;
	for(int i = 0; i < length; i++)
		if(get_code(seq[i]) == 4) {
			while(index < 4 && counter[index] == of_each_type)
				index++;
			if(index == 4) {
				cout << "===" << endl;
				exit(0);
			}
			counter[index]++;
			seq[i] = get_char(index);
		}
	cout << seq << endl;
}