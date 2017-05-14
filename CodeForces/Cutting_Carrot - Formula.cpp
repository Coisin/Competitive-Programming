#include <bits/stdc++.h>

using namespace std;

double get_area(double h, double b) {
	return (h * b) / 2;
}

int main() {
	double num_pieces, height;
	cin >> num_pieces >> height;
	double incr = get_area(height, 1.0) / num_pieces;
	for(int i = 1; i < num_pieces; i++) {
		double desired = incr * (double)i;

		cout << setprecision(30) << sqrt(2 * desired * height) << " ";
	}
}