//
// Created by Stephen Ni on 2023-12-25.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string cardsStr;

    cin >> cardsStr;

    vector<int> cards;
    vector<int> eights;

    for(int i = 0; i < n; i++) {
        int card;
        card = cardsStr[i] - '0';

        if (card == 8) {
            eights.push_back(0);
        } else {
            cards.push_back(0);
        }
    }

    if (eights.size() == 0) {
        cout << 0;
    } else if (eights.size() * 10 <= cards.size()) {
        cout << eights.size();
    } else { // eights.size() * 10 > cards.size()
        int r = cards.size() % 10;
        int cardsFormed = (cards.size() - r) / 10;
        int cardsLeft = cards.size() - cardsFormed * 10;
        int r2 = (eights.size() + cardsLeft - cardsFormed) % 11;
        cout << cardsFormed + ((eights.size() + cardsLeft - cardsFormed - r2) / 11);
    }

    return 0;
}
// you can also use 8's as normal digits in the case that there are more 8s than card sizes (the else statement)