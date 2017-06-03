#include <bits/stdc++.h>

using namespace std;

string command, current_directory = "";

int main() {
	int num_commands;
	cin >> num_commands;
	while(num_commands--) {
		cin >> command;
		if(command == "pwd") {
			if(current_directory == "")
				cout << "/" << endl;
			else
				cout << current_directory << "/" << endl;
		} else {
			cin >> command;
			if(command[0] == '/')
				current_directory = command;
			else {
				current_directory += "/" + command;
				if(current_directory[current_directory.size() - 1] == '/')
					current_directory = current_directory.substr(0, current_directory.size() - 1);
			}
			int delete_counter = 0;
				string new_directory = "";
				string name = "";
				for(int i = current_directory.size() - 1; i >= 0; i--) {
					char c = current_directory[i];
					if(c == '/') {
						if(name == "")
							continue;
						if(name == "..")
							delete_counter++;
						else if(delete_counter)
							delete_counter--;
						else new_directory = "/" + name + new_directory;
						name = "";
					} else {
						name = c + name;
					}
				}
				current_directory = new_directory;
		}
	}
}