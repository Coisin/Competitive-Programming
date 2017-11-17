#include <bits/stdc++.h>

using namespace std;

int width, height;

int main() {
	cin >> width >> height;
	cout << min(width, height) + 1 << endl;
	for(int index = min(width, height); index >= 0; index--)
		cout << min(width, height) - index << " " << index << endl;
}