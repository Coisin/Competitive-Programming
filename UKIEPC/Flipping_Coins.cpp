#include <bits/stdc++.h>

using namespace std;

int n, k;
double prob[402][402];

int main() {
	cin >> n >> k;
	prob[0][0] = 1;
	for(int i = 1; i <= k; i++)
		for(int j = 0; j <= n; j++) {
			prob[i][j] = (0.5 * prob[i - 1][j]);
			if(j > 0)
				prob[i][j] += 0.5 * prob[i - 1][j - 1];
			if(j == n - 1)
				prob[i][j] += 0.5 * prob[i - 1][j + 1];
		}
	double answer = 0;
	for(int i = 0; i <= n; i++)
		answer += prob[k][i] * i;
	
	cout << setprecision(20) << answer << endl;
}