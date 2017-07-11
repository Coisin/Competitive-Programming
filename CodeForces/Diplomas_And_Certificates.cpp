#include <bits/stdc++.h>

using namespace std;

int main() {
	long long num_students, ratio;
	cin >> num_students >> ratio;
	long long num_winners = num_students / 2;
	long long num_diplomas = num_winners / (ratio + 1);
	long long num_certificates = num_diplomas * ratio;
	num_winners = num_diplomas + num_certificates;
	long long num_losers = num_students - num_winners;
	cout << num_diplomas << " " << num_certificates << " " << num_losers << endl;
}