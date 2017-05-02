#include <bits/stdc++.h>

using namespace std;

int num_lessons;
vector<int> lessons;
int time_per_lecture, C;

pair<int, int> dp[1001];

pair<int, int> process(int pos) { // Returns {Num_Lectures, Unhappy Score}
	if(pos == num_lessons) return {0, 0};
	if(dp[pos] != make_pair(-1, -1)) return dp[pos];
	pair<int, int> answer = {1000000000, 1000000000};
	int time = 0;
	for(int i = pos; i < num_lessons; i++) {
		int lesson_time = lessons[i];
		if(time + lesson_time > time_per_lecture) break;
		pair<int, int> next_answer = process(i + 1);
		time += lesson_time;
		int t = time_per_lecture - time;
		int unhappy = (t == 0 ? 0 : (t <= 10 ? -C : ((t - 10) * (t - 10))));
		if(1 + next_answer.first < answer.first || (1 + next_answer.first == answer.first && unhappy + next_answer.second < answer.second)) {
			answer.first = next_answer.first + 1;
			answer.second = unhappy + next_answer.second;
		}
	}
	return dp[pos] = answer;
}

int main() {
	int case_count = 1;
	cin >> num_lessons;
	while(num_lessons != 0) {
		for(int i = 0; i < 1001; i++) dp[i] = {-1, -1};
		cin >> time_per_lecture >> C;
		lessons.resize(num_lessons);
		for(int i = 0; i < num_lessons; i++)
			cin >> lessons[i];
		cout << "Case " << case_count << ":" << endl;
		pair<int, int> answer = process(0);
		cout << "Minimum number of lectures: " << answer.first << endl;
		cout << "Total dissatisfaction index: " << answer.second << endl;
		cin >> num_lessons;
		if(num_lessons != 0) cout << endl;
		case_count++;
	}
}