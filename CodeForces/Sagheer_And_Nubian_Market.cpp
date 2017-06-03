#include <bits/stdc++.h>

using namespace std;

long long middle;

bool comp(pair<long long, long long> a, pair<long long, long long> b) {
	return (a.first + (middle * a.second)) < (b.first + (middle * b.second));
}

int main() {
	long long num_items, money;
	cin >> num_items >> money;
	pair<long long, long long> items[num_items];
	for(long long i = 0; i < num_items; i++) {
		long long price;
		cin >> price;
		items[i] = {price, i + 1};
	}
	long long left = 0;
	long long right = num_items;
	long long minimum_price = 1000000000;
	long long maximum_items = -1;
	long long price;
	for(long long t = 0; t <= 100; t++) {
		middle = (left + right) / 2;
		sort(items, items + num_items, comp);
		price = 0;
		for(long long i = 0; i < middle; i++)
			price += items[i].first + (items[i].second * middle);
		if(price > money) right = middle;
		else {
			if(maximum_items == middle)
				minimum_price = min(minimum_price, price);
			else minimum_price = price;
			maximum_items = middle;
			left = middle + 1;
		}
	}

	cout << maximum_items << " " << minimum_price << endl;
}