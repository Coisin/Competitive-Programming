#include <bits/stdc++.h>

using namespace std;

int cards_each;
vector<int> cards;
int other_cards_prefix[100002], used_prefix[100002];

int main() {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	cin >> cards_each;
	other_cards_prefix[cards_each + 1] = used_prefix[cards_each + 1] = 0;
	cards.resize(cards_each);
	for(int i = 0; i < cards_each; i++)
		cin >> cards[i];
	sort(cards.begin(), cards.end());
	for(int i = 2 * cards_each; i >= 1; i--) {
		other_cards_prefix[i] = other_cards_prefix[i + 1];
		if(!binary_search(cards.begin(), cards.end(), i))
			other_cards_prefix[i]++;
	}
	int games_won = 0;
	for(int i = 2 * cards_each; i >= 1; i--) {
		used_prefix[i] = used_prefix[i + 1];
		if(binary_search(cards.begin(), cards.end(), i)) {
			if(other_cards_prefix[i] - used_prefix[i]) {
				games_won++;
				used_prefix[i]++;
			}
		}
	}
	cout << games_won << endl;
}