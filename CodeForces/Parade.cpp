#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_soldiers;
	cin >> num_soldiers;
	int max_change_l_l = 0;
	int max_change_l_r = 0;
	int max_change_r_l = 0;
	int max_change_r_r = 0;
	int index_l = -1;
	int index_r = -1;
	int total_r = 0, total_l = 0;
	for(int i = 0; i < num_soldiers; i++) {
		int l, r;
		cin >> l >> r;
		if(l - r > max_change_r_l - max_change_r_r) {
			max_change_r_l = l;
			max_change_r_r = r;
			index_r = i;
		}
		if(r - l > max_change_l_r - max_change_l_l) {
			max_change_l_l = l;
			max_change_l_r = r;
			index_l = i;
		}
		total_l += l;
		total_r += r;
	}
	index_l++;
	index_r++;
	int max_beauty_l = abs(((total_l - max_change_l_l) + max_change_l_r) - ((total_r - max_change_l_r) + max_change_l_l));
	int max_beauty_r = abs(((total_l - max_change_r_l) + max_change_r_r) - ((total_r - max_change_r_r) + max_change_r_l));
	if(max(max_beauty_r, max_beauty_l) == abs(total_r - total_l))
		cout << 0 << endl;
	else cout << (max_beauty_l > max_beauty_r ? index_l : index_r) << endl;
}