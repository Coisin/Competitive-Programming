/*

TASK: spin
LANG: C++11

*/

#include <bits/stdc++.h>

using namespace std;

int speed[5];
int num_wedges[5];
vector<int> current_degree_start[5];
vector<int> current_degree_end[5];
vector<int> degree_size[5];
int t;
int current_degree[5];

vector<int> start_stack, end_stack;

bool visited[5][360];
bool completed_cycle[5];

bool overlaps(int wheel) {
	if(wheel == 5)
		return true;
	for(int i = 0; i < num_wedges[wheel]; i++) {
		int start = current_degree_start[wheel][i];
		int end = current_degree_end[wheel][i];

		if(end <= start) {
			end += 360;
		}

		bool works = true;
		for(int j = 0; j < wheel; j++) {
			int other_start = start_stack[j];
			int other_end = end_stack[j];

			bool this_works = false;

			this_works |= (start < other_end) && (end > other_start);

			start += 360;
			end += 360;
			this_works |= (start < other_end) && (end > other_start);
			start -= 360;
			end -= 360;

			start -= 360;
			end -= 360;
			this_works |= (start < other_end) && (end > other_start);
			start += 360;
			end += 360;

			works &= this_works;
		}
		if(works) {
			start_stack.push_back(start);
			end_stack.push_back(end);
			if(overlaps(wheel + 1))
				return true;
			start_stack.pop_back();
			end_stack.pop_back();
		}
	}
	return false;
}

int main() {

	for(int i = 0; i < 5; i++) {
		cin >> speed[i] >> num_wedges[i];
		current_degree_start[i].resize(num_wedges[i]);
		current_degree_end[i].resize(num_wedges[i]);
		degree_size[i].resize(num_wedges[i]);
		for(int j = 0; j < num_wedges[i]; j++) {
			cin >> current_degree_start[i][j] >> degree_size[i][j];
			degree_size[i][j]++;
			current_degree_end[i][j] = (current_degree_start[i][j] + degree_size[i][j]) % 360;
		}
	}
	for(int i = 0; i < 5; i++)
		visited[i][current_degree[i]] = true;
	for(t = 0; !overlaps(0); t++) {
		for(int i = 0; i < 5; i++) {
			current_degree[i] = (current_degree[i] + speed[i]) % 360;
			if(visited[i][current_degree[i]]) 
				completed_cycle[i] = true;
			visited[i][current_degree[i]] = true;
			for(int j = 0; j < num_wedges[i]; j++) {
				current_degree_start[i][j] = (current_degree_start[i][j] + speed[i]) % 360;
				current_degree_end[i][j] = (current_degree_end[i][j] + speed[i]) % 360;
			}
		}
		if(completed_cycle[0] && completed_cycle[1] && completed_cycle[2] && completed_cycle[3] && completed_cycle[4]) {
			cout << "none" << endl;
			exit(0);
		}
	}
	cout << t << endl;
}