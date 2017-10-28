#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	while(a != 0 && b != 0) {
		long long first_a = a;
		long long first_b = b;
		map<long long, long long> visited_a;
		map<long long, long long> visited_b;

		for(long long i = 1; ; i++) {
			visited_a[a] = i;
			if(a == 1)
				break;
			if(a & 1)
				a = (a * 3) + 1;
			else
				a /= 2;
		}
		int min_value = -1;
		for(long long i = 1; ; i++) {
			visited_b[b] = i;
			if(visited_a[b] && (min_value == -1 || (visited_a[min_value] + visited_b[min_value]) > (visited_a[b] + visited_b[b])))
				min_value = b;
			if(b == 1)
				break;
			if(b & 1)
				b = (b * 3) + 1;
			else
				b /= 2;
		}
		cout << first_a << " needs " << visited_a[min_value] - 1 << " steps, " << first_b << " needs " << visited_b[min_value] - 1 << " steps, they meet at " << min_value << endl;
		cin >> a >> b;
	}
}