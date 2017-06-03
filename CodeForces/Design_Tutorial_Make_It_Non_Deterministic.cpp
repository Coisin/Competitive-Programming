#include <bits/stdc++.h>

using namespace std;

int least_lex(string a, string b) {
	for(int i = 0; i < min(a.size(), b.size()); i++) {
		if(a[i] < b[i]) return 0;
		else if(b[i] < a[i]) return 1;
	}
	return a.size() > b.size();
}

int main() {
	int num_people;
	cin >> num_people;
	string people_first[num_people];
	string people_second[num_people];
	int perm[num_people];
	for(int i = 0; i < num_people; i++) {
		cin >> people_first[i];
		cin >> people_second[i];
	}
	for(int j = 0; j < num_people; j++) {
		cin >> perm[j];
		perm[j]--;
	}
	string prev_selected;
	for(int i = 0; i < num_people; i++) {
		string a, b;
		a = people_first[perm[i]];
		b = people_second[perm[i]];
		int comes_first = least_lex(a, b);
		string to_select = comes_first ? b : a;
		string not_to_select = comes_first ? a : b;
		if(i == 0)
			prev_selected = comes_first ? b : a;
		else {
			if(least_lex(to_select, prev_selected)) {
				prev_selected = to_select;
			} else {
				if(least_lex(prev_selected, not_to_select)) {
					cout << "NO" << endl;
					return 0;
				}
				prev_selected = not_to_select;
			}
		}
	}
	cout << "YES" << endl;
}