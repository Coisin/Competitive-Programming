/*

TASK:msquare
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

struct sheet {
public:
	int a, b, c, d;
	int e, f, g, h;
	int count;
	string operations;
	sheet(int _a, int _b, int _c, int _d, int _e, int _f, int _g, int _h):a(_a), b(_b), c(_c), d(_d), e(_e), f(_f), g(_g), h(_h) {
		operations = "";
	}
	long long get_key() {
		return (a * 10000000) + (b * 1000000) + (c * 100000) + (d * 10000) +
				(e * 1000) + (f * 100) + (g * 10) + (h * 1);
	}
	bool operator==(const sheet& two) const {
		return a == two.a &&
				b == two.b &&
				c == two.c &&
				d == two.d &&
				e == two.e &&
				f == two.f &&
				g == two.g &&
				h == two.h;
	}
};

sheet A(sheet a) {
	swap(a.a, a.e);
	swap(a.b, a.f);
	swap(a.c, a.g);
	swap(a.d, a.h);
	a.operations += "A";
	return a;
}

sheet B(sheet a) {
	int placeholder = a.d;
	a.d = a.c;
	a.c = a.b;
	a.b = a.a;
	a.a = placeholder;
	placeholder = a.h;
	a.h = a.g;
	a.g = a.f;
	a.f = a.e;
	a.e = placeholder;
	a.operations += "B";
	return a;
}

sheet C(sheet a) {
	int placeholder = a.b;
	a.b = a.f;
	a.f = a.g;
	a.g = a.c;
	a.c = placeholder;
	a.operations += "C";
	return a;
}

map<long long, int> dist;

int distance(sheet a) {
	if(dist.count(a.get_key()) == 0)
		return -1;
	return dist[a.get_key()];
}

void set_distance(sheet a, int v) {
	dist[a.get_key()] = v;
}

int main() {
	int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d >> h >> g >> f >> e;
	sheet goal(a, b, c, d, e, f, g, h);
	sheet current(1, 2, 3, 4, 8, 7, 6, 5);

	set_distance(current, 0);
	queue<sheet> q;
	q.push(current);
	while(!q.empty()) {
		current = q.front(); q.pop();
		if(current == goal)
			break;
		sheet after_a = A(current);
		sheet after_b = B(current);
		sheet after_c = C(current);
		if(distance(after_a) == -1 || distance(after_a) > distance(current) + 1) {
			q.push(after_a);
			set_distance(after_a, distance(current) + 1);
		}
		if(distance(after_b) == -1 || distance(after_b) > distance(current) + 1) {
			q.push(after_b);
			set_distance(after_b, distance(current) + 1);
		}
		if(distance(after_c) == -1 || distance(after_c) > distance(current) + 1) {
			q.push(after_c);
			set_distance(after_c, distance(current) + 1);
		}
	}
	cout << distance(current) << endl;
	cout << current.operations << endl;
}