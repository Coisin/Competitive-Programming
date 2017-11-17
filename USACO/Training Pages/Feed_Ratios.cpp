/*

LANG: C++11
TASK: ratios

*/

#include <bits/stdc++.h>

using namespace std;

int goal_a, goal_b, goal_c;
int ratios[3][3];

int main() {
	cin >> goal_a >> goal_b >> goal_c;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> ratios[i][j];
	for(int a = 0; a <= 100; a++)
		for(int b = 0; b <= 100; b++)
			for(int c = 0; c <= 100; c++) {
				if(a == b && b == c && c == 0)
					continue;

				int sum[3];
				sum[0] = (ratios[0][0] * a) + (ratios[1][0] * b) + (ratios[2][0] * c);
				sum[1] = (ratios[0][1] * a) + (ratios[1][1] * b) + (ratios[2][1] * c);
				sum[2] = (ratios[0][2] * a) + (ratios[1][2] * b) + (ratios[2][2] * c);

				bool mod_a = goal_a && (sum[0] % goal_a);
				bool mod_b = goal_b && (sum[1] % goal_b);
				bool mod_c = goal_c && (sum[2] % goal_c);

				if(mod_a || mod_b || mod_c)
					continue;

				int div_a = goal_a ? sum[0] / goal_a : -1;
				int div_b = goal_b ? sum[1] / goal_b : -1;
				int div_c = goal_c ? sum[2] / goal_c : -1;

				if(!((div_a == div_b) || !goal_a || !goal_b))
					continue;
				if(!((div_b == div_c) || !goal_b || !goal_c))
					continue;
				if(!((div_a == div_c) || !goal_a || !goal_c))
					continue;

				int ratio;
				if(goal_a)
					ratio = sum[0] / goal_a;
				else if(goal_b)
					ratio = sum[1] / goal_b;
				else if(goal_c)
					ratio = sum[2] / goal_c;
				else continue;
				cout << a << " " << b << " " << c << " " << ratio << endl;
				exit(0);
			}
	cout << "NONE" << endl;
}