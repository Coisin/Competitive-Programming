#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int num_events;
		cin >> num_events;
		vector<pair<int, int> > events;
		while(num_events--) {
			int start, end;
			cin >> start >> end;
			events.push_back({end, start});
		}
		sort(events.begin(), events.end());
		int answer = 0;
		int time = 0;
		for(int i = 0; i < events.size(); i++) {
			int end = events[i].first;
			int start = events[i].second;
			if(start < time) continue;
			time = end;
			answer++;
		}
		cout << answer << endl;
	}
}