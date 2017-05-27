/*

TASK: concom
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int num_vertices;

int percent[101][101], ownership[101][101], controls[101][101];

int main() {
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	cin >> num_vertices;
	for(int i = 0; i < num_vertices; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		ownership[a][b] = c;
	}
	bool change;
	do {
		change = false;
		for(int a = 0; a < 101; a++) {
			for(int b = 0; b < 101; b++) {
				if((a == b || percent[a][b] > 50) && !controls[a][b]) {
					change = true;
					controls[a][b] = true;
					for(int c = 0; c < 101; c++)
						percent[a][c] += ownership[b][c];
				}
			}
		}
	} while(change);
	for(int a = 0; a < 101; a++)
		for(int b = 0; b < 101; b++)
			if(a != b && controls[a][b])
				cout << (a + 1) << " " << (b + 1) << endl;
}