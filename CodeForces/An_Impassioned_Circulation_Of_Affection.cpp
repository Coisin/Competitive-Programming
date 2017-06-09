#include <bits/stdc++.h>

using namespace std;

int num_latterns;
int original_array[1501];
int prefix_array[30][1501];

int main() {
	cin >> num_latterns;
	for(int i = 0; i < num_latterns; i++) {
		char lattern;
		cin >> lattern;
		original_array[i] = lattern - 'a';
		for(int j = 0; j < 26; j++) {
			prefix_array[j][i] = i == 0 ? 0 : prefix_array[j][i - 1];
		}
		prefix_array[original_array[i]][i]++;
	}
	int num_queries;
	cin >> num_queries;
	for(int i = 0; i < num_queries; i++) {
			int num_moves;
			char fav;
			cin >> num_moves >> fav;
			int favorite = fav - 'a';
			int answer = 0;
			int L, R;
			L = R = 0;
			while(L <= R && R < num_latterns) {
				int sum = prefix_array[favorite][R] - (L > 0 ? prefix_array[favorite][L - 1] : 0);
				if(((R - L) + 1) - sum <= num_moves) {
					answer = max(answer, (R - L) + 1);
					R++;
				} else L++;
			}
			cout << answer << endl;
	}
}