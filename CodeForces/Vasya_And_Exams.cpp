#include <bits/stdc++.h>

using namespace std;

int main() {
	long long num_exams, required, max_marks;
	long double sum = 0;
	cin >> num_exams >> max_marks >> required;
	vector<pair<long long, long long> > tests;
	for(int i = 0; i < num_exams; i++) {
		long long score, essays;
		cin >> score >> essays;
		tests.push_back({essays, score});
		sum += score;
	}
	sort(tests.begin(), tests.end());
	long long to_add = (required * num_exams) - sum;
	if(to_add < 0) to_add = 0;
	long long answer = 0;
	for(long long i = 0; i < num_exams; i++) {
		long long counter = max_marks - tests[i].second;
		answer += min(counter, to_add) * tests[i].first;
		to_add -= min(counter, to_add);
	}
	cout << answer << endl;
}