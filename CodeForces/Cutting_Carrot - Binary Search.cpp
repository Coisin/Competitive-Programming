#include <bits/stdc++.h>

using namespace std;

double num_pieces;
double height;
double base = 1.0;

double get_area(double h) {
	double b = (base / height) * h;
	return (h * b) / 2;
}

int main() {
	cin >> num_pieces >> height;
	double incr = get_area(height) / num_pieces;
	for(int i = 1; i < num_pieces; i++) {
		double desired = incr * (float)i;
		double left = 0.0, right = height;

		while(abs(left - right) > .000000001) {
			double middle = (left + right) / 2.0;
			
			if(abs(get_area(middle) - desired) < .000000001) {
				cout << setprecision(20) << middle << " ";
				break;
			} else if(get_area(middle) - desired > .000000001)
				right = middle;
			else left = middle;
		}
	}
}

