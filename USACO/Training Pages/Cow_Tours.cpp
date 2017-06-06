
/*

TASK: cowtour
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

vector<pair<long double, long double> > farms;
int num_farms;

bool connected_by_road[200][200];
long double dist[200][200];
long double max_dist[200];

long double get_dist(long double x1, long double y1, long double x2, long double y2) {
	return hypot(x2 - x1, y2 - y1);
}

int main() {
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);

	cin >> num_farms;
	for(int i = 0; i < num_farms; i++) {
		long double x, y;
		cin >> x >> y;
		farms.push_back({x, y});
	}
	long double current_diam = -1;
	for(int i = 0; i < num_farms; i++) {
		string line;
		cin >> line;
		for(int j = 0; j < num_farms; j++) {
			connected_by_road[i][j] = line[j] == '1';
			if(connected_by_road[i][j])
				dist[i][j] = get_dist(farms[i].first, farms[i].second, farms[j].first, farms[j].second);
			else dist[i][j] = 1000000000;
		}
		connected_by_road[i][i] = true;
		dist[i][i] = 0;
	}
	for(int i = 0; i < num_farms; i++) {
		for(int j = 0; j < num_farms; j++) {
			for(int k = 0; k < num_farms; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
				connected_by_road[j][k] |= connected_by_road[j][k] | (connected_by_road[j][i] & connected_by_road[i][k]);
			}
		}
	}

	for(int i = 0; i < num_farms; i++) {
		for(int j = 0; j < num_farms; j++) {
			if(connected_by_road[i][j]) {
				max_dist[i] = max(max_dist[i], dist[i][j]);
			}
		}
	}

	long double diam[num_farms] = {0};

	for(int a = 0; a < num_farms; a++) {
		long double dim = -1;
		for(int b = 0; b < num_farms; b++) {
			if(connected_by_road[a][b] && dim < max_dist[b])
				dim = max_dist[b];
		}
		diam[a] = dim;
	}

	long double min_diam = 1000000000;
	for(int i = 0; i < num_farms; i++) {
		for(int j = 0; j < num_farms; j++) {
			if(connected_by_road[i][j]) continue;
			long double new_diam = get_dist(farms[i].first, farms[i].second, farms[j].first, farms[j].second)
			+ max_dist[i] + max_dist[j];
			long double d1 = diam[i];
			long double d2 = diam[j];
			new_diam = max(new_diam, max(d1, d2));
			min_diam = min(min_diam, new_diam);
		}
	}
	printf("%.6Lf\n", min_diam);
}