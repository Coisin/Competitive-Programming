#include <bits/stdc++.h>

using namespace std;

int room_number_at_time[200001];
int last_time_at_room[200001];
int tim[200001];
int n;

int main() {
	int time = 1;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tim[i];
		tim[i]++;
	}
	room_number_at_time[time] = 1;
	last_time_at_room[1] = time;
	int current_room = 1;
	int number_rooms = 1;
	for(int i = 0; i < n; i++) {
		time++;
		int t = tim[i];
		int room_at_t = room_number_at_time[t];
		if(last_time_at_room[room_at_t] == t) {
			current_room = room_at_t;
		} else {
			number_rooms++;
			current_room = number_rooms;
		}
		last_time_at_room[current_room] = time;
		room_number_at_time[time] = current_room;
	}
	cout << number_rooms << endl;
}