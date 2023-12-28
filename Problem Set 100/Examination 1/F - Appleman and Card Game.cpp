//
// Created by Stephen Ni on 2023-12-28.
//

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<unordered_map>

using namespace std;

int checkVector(vector<pair<char, int> > cards, char c) {
    for(int i = 0; i < cards.size(); i++) {
        if (cards[i].first == c) {
            return i;
        }
    }

    return 10000000;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<char, int> > cards;

    string strCards;
    cin >> strCards;

    for(int i = 0; i < n; i++) {
        char card = strCards[i];
        int index = checkVector(cards, card);

        if(index == 10000000) {
            pair<char, int> temp;
            temp.first = card;
            temp.second = 1;
            cards.push_back(temp);
        } else {
            cards[index].second++;
        }
    }

    int m = cards.size();

    int numCards[m];

    for(int i = 0; i < m; i++) {
        numCards[i] = cards[i].second;
    }

    sort(numCards, numCards+m);

    long long count = 0;
    long long iteration = 0;
    long long sum = 0;
    while(count < k) {
        long long num = numCards[m - 1 - iteration];
        iteration++;

        if(count + num >= k) {

            long long diff = count - k;
            sum += diff * diff;
            break;

        }

        count += num;
        sum += num * num;
    }
    cout << sum;


    return 0;
}