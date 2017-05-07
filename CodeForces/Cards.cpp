#include <bits/stdc++.h>

using namespace std;

int main() {
	int reds, greens, blues;
	reds = greens = blues = 0;

	bool pos_blue, pos_green, pos_red;
	pos_red = pos_green = pos_blue = false;

	int seq_length;
	char sequence[200];

	cin >> seq_length;
	cin >> sequence;

	for(int i = 0; i < seq_length; i++)
		if(sequence[i] == 'R') reds++;
		else if(sequence[i] == 'B') blues++;
		else if(sequence[i] == 'G') greens++;

	if(reds && greens && blues) pos_blue = pos_red = pos_green = true;
	if(reds && greens) pos_blue = true;
	if(reds && blues) pos_green = true;
	if(blues && greens) pos_red = true;
	if(blues >= 2 && reds) pos_red = true;
	if(blues >= 2 && greens) pos_green = true;
	if(reds >= 2 && blues) pos_blue = true;
	if(reds >= 2 && greens) pos_green = true;
	if(greens >= 2 && blues) pos_blue = true;
	if(greens >= 2 && reds) pos_red = true;
	if(reds && (greens == 0) && (blues == 0)) pos_red = true;
	if(greens && (blues == 0) && (reds == 0)) pos_green = true;
	if(blues && (greens == 0) && (reds == 0)) pos_blue = true;

	if(pos_blue) cout << "B";
	if(pos_green) cout << "G";
	if(pos_red) cout << "R";
	cout << endl;
}