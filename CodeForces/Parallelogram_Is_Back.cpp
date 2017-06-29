#include <bits/stdc++.h>

using namespace std;

pair<pair<int, int>, pair<int, int> > as_base(int x1, int y1, int x2, int y2, int x3, int y3) {
	int dif_x = x1 - x2;
	int dif_y = y1 - y2;
	pair<pair<int, int>, pair<int, int> > answer = {{dif_x + x3, dif_y + y3}, {-dif_x + x3, -dif_y + y3}};
	return answer;
}

int main() {
	int x1, y1;
	int x2, y2;
	int x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	set<pair<int, int> > answers;
	answers.insert(as_base(x1, y1, x2, y2, x3, y3).first);
	answers.insert(as_base(x1, y1, x2, y2, x3, y3).second);
	answers.insert(as_base(x1, y1, x3, y3, x2, y2).first);
	answers.insert(as_base(x1, y1, x3, y3, x2, y2).second);
	answers.insert(as_base(x2, y2, x3, y3, x1, y1).first);
	answers.insert(as_base(x2, y2, x3, y3, x1, y1).second);
	cout << answers.size() << endl;
	for(set<pair<int, int> >::iterator it = answers.begin(); it != answers.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}
}