#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n != 0) {
		int enc[n];
		for(int i = 0; i < n; i++)
			cin >> enc[i];
		string seq;
		cin.ignore();
		getline(cin, seq);
		for(; seq.size() % n; seq += " ");
		string answer = "";
		for(int i = 0; i < seq.size(); i += n) {
			string temp  = "";
			for(int j = 0; j < n; j++)
				temp += " ";
			for(int j = 0; j < n; j++)
				temp[j] = seq[(enc[j] - 1) + i];
			answer += temp;
		}
		cout << "'" << answer << "'" << endl;
		cin >> n;
	}
}