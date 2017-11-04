#include <bits/stdc++.h>

using namespace std;

bitset<10000> used;

int main() {
	int n;
	cin >> n;
	int cubes[n][6];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 6; j++)
			cin >> cubes[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 6; j++) {
			int number = cubes[i][j];
			if(number == 0)
				continue;
			used[number] = true;
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < 6; k++)
				for(int f = 0; f < 6; f++) {
					if(i == j)
						continue;
					int number_1 = cubes[i][k];
					int number_2 = cubes[j][f];
					int formed_1 = number_1 * 10 + number_2;

					if(number_1 != 0)
						used[formed_1] = true;
				}
	for(int a = 0; a < n; a++)
		for(int b = 0; b < n; b++)
			for(int c = 0; c < n; c++)
				for(int d = 0; d < 6; d++)
					for(int e = 0; e < 6; e++)
						for(int f = 0; f < 6; f++) {
							if(a == b || b == c || a == c)
								continue;
							int n1 = cubes[a][d];
							int n2 = cubes[b][e];
							int n3 = cubes[c][f];
							int f1 = n1 * 100 + n2 * 10 + n3;
							int f2 = n1 * 100 + n3 * 10 + n2;
							int f3 = n2 * 100 + n3 * 10 + n1;
							int f4 = n2 * 100 + n1 * 10 + n3;
							int f5 = n3 * 100 + n2 * 10 + n1;
							int f6 = n3 * 100 + n1 * 10 + n2;
							if(n1 != 0) {
								used[f1] = true;
								used[f2] = true;
							}
							if(n2 != 0) {
								used[f3] = true;
								used[f4] = true;
							}
							if(n3 != 0) {
								used[f5] = true;
								used[f6] = true;
							}
						}
	int answer = 1;
	for(; used[answer]; answer++);
	cout << answer - 1 << endl;
}