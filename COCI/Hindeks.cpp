#include <bits/stdc++.h>

using namespace std;

int main() {
	int num_papers;
	cin >> num_papers;
	vector<int> papers(num_papers);
	for(int i = 0; i < num_papers; i++)
		cin >> papers[i];
	sort(papers.begin(), papers.end());
	int answer = 0;
	for(int i = 0; i < num_papers; i++)
		answer = max(answer, min(num_papers - i , papers[i]));
	cout << answer;
}