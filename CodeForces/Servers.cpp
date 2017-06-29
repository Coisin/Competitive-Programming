#include <bits/stdc++.h>

using namespace std;

int num_servers;
int num_queries;

int finish_time[101];

int main() {
	cin >> num_servers >> num_queries;
	int current_time = 0;
	for(int i = 0; i < num_queries; i++) {
		int start_time, req_serv, dur;
		cin >> start_time >> req_serv >> dur;
		
		int sum = 0;
		int servers_left = req_serv;
		for(int j = 0; j < num_servers && servers_left; j++) {
			if(finish_time[j] <= start_time) {
				sum += j + 1;
				servers_left--;
			}
		}
		if(servers_left) {
			cout << -1 << endl;
		} else {
			servers_left = req_serv;
			for(int j = 0; j < num_servers && servers_left; j++) {
				if(finish_time[j] <= start_time) {
					finish_time[j] = start_time + dur;
					servers_left--;
				}
			}
			current_time = start_time + dur;
			cout << sum << endl;
		}
	}
}