#include <bits/stdc++.h>

using namespace std;

bitset<1000000001> toys;

int main() {
	int num_toys_owned, money;
	cin >> num_toys_owned >> money;
	for(int i = 0; i < num_toys_owned; i++) {
		int toy;
		cin >> toy;
		toys[toy] = 1;
	}
	int counter = 1;
	vector<int> answer;
	while(money && counter <= money) {
		if(toys[counter] == 0) {
			answer.push_back(counter);
			money -= counter;
		}
		counter++;
	}
	cout << answer.size() << endl;
	for(int i = 0; i < answer.size(); i++)
		cout << answer[i] << (i == answer.size() - 1 ? "" : " ");
}