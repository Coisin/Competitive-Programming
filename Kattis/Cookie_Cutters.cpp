#include <bits/stdc++.h>

using namespace std;

double left_x = 1000000, bottom_y = 1000000;

double get_area(vector<pair<double, double> > points, double M) {
	double answer = 0;
	for(int i = 1; i <= points.size(); i++) {
		double x1 = points[(i - 1) % points.size()].first, y1 = points[(i - 1) % points.size()].second;
		double x2 = points[i % points.size()].first, y2 = points[i % points.size()].second;
		x1 = (x1 - left_x) * M;
		x2 = (x2 - left_x) * M;
		y1 = (y1 - bottom_y) * M;
		y2 = (y2 - bottom_y) * M;
		answer += (x1 * y2) - (y1 * x2);
	}
	return answer / 2;
}

int main() {
	int num_vertices;
	vector<pair<double, double> > points;
	int desired_area;

	cin >> num_vertices;
	for(int i = 0; i < num_vertices; i++) {
		double x, y;
		cin >> x >> y;
		points.push_back({x, y});
		bottom_y = min(bottom_y, y);
		left_x = min(left_x, x);
	}
	cin >> desired_area;

	double L, H, M;
	L = 0;
	H = 10000001;
	double area = -1;

	while(abs(area - desired_area) > 10e-10) {
		M = (L + H) / 2;
		area = get_area(points, M);
		if(area > desired_area) {
			H = M;
		} else {
			L = M;
		}
	}
	cout << setprecision(10);
	for(int i = 0; i < points.size(); i++) {
		double x1 = points[i].first, y1 = points[i].second;
		x1 = (x1 - left_x) * M;
		y1 = (y1 - bottom_y) * M;
		cout << fixed << x1 << " " << fixed << y1 << endl;
	}
}