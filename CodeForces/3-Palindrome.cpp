#include <bits/stdc++.h>

using namespace std;

int sequence_length;

int main() {
	cin >> sequence_length;
	string answer = "";
	for(int i = 0, j = 0; i < sequence_length; i++, j++)
		if(j == 0) answer += "a";
		else if(j == 1) answer += "a";
		else if(j == 2) answer += "b";
		else if(j == 3) { answer += "b"; j = -1; }
	cout << answer << endl;	
}