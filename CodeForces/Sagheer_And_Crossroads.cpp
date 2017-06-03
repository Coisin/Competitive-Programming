#include <bits/stdc++.h>

using namespace std;

int roads[4][4];

int main() {
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			cin >> roads[i][j];
	bool will_end_badly = false;
	for(int i = 0; i < 4 && !will_end_badly; i++) {
		if(roads[i][0] && roads[((i - 1) + 4) % 4][3]) will_end_badly = true;
		if(roads[i][1] && roads[((i + 2) + 4) % 4][3]) will_end_badly = true;
		if(roads[i][2] && roads[((i + 1) + 4) % 4][3]) will_end_badly = true;
		if(roads[i][0] && roads[i][3]) will_end_badly = true;
		if(roads[i][1] && roads[i][3]) will_end_badly = true;
		if(roads[i][2] && roads[i][3]) will_end_badly = true;
	}
	if(will_end_badly)
		cout << "YES" << endl;
	else cout << "NO" << endl;
}	