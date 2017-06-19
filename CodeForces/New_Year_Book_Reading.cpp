#include <bits/stdc++.h>

using namespace std;

vector<int> weights, order, actual_order;

bool comp(int a, int b) {
	return actual_order[a] > actual_order[b];
}

int main() {
	int num_books, num_days;
	cin >> num_books >> num_days;
	order.resize(num_days);
	weights.resize(num_books);
	actual_order.resize(num_books);
	for(int i = 0; i < num_books; i++)
		actual_order[i] = num_days;
	for(int i = 0; i < num_books; i++) cin >> weights[i];
	for(int i = 0; i < num_days; i++) {
		cin >> order[i];
		order[i]--;
		actual_order[order[i]] = min(i, actual_order[order[i]]);
	}
	int books[num_books];
	for(int i = 0; i < num_books; i++) books[i] = i;
	sort(books, books + num_books, comp);
	stack<int> book_stack;
	for(int i = 0; i < num_books; i++) book_stack.push(books[i]);
	int answer = 0;
	for(int i = 0; i < num_days; i++) {
		stack<int> to_add;
		while(book_stack.top() != order[i]) {
			to_add.push(book_stack.top());
			answer += weights[book_stack.top()];
			book_stack.pop();
		}
		book_stack.pop();
		while(to_add.size()) {
			book_stack.push(to_add.top());
			to_add.pop();
		}
		book_stack.push(order[i]);
	}
	cout << answer << endl;
}