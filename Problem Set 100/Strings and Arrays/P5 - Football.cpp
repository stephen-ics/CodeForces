//
// Created by Stephen Ni on 2023-12-21.
//

#include<iostream>
#include<string>

using namespace std;

int main() {
    string players;

    cin >> players;

    int count = 0;
    int lastPlayer;

    bool safe = true;

    for(int i = 0; i < players.length(); i++) {
        if(i == 0) {
            lastPlayer = players[i];
            count++;
        }
        else {
            if(players[i] == lastPlayer) {
                count++;
                if(count == 7) {
                    cout << "YES";
                    safe = false;
                    break;
                }
            }
            else {
                count = 1;
            }
            lastPlayer = players[i];
        }
    }

    if(safe) {
        cout << "NO";
    }

    return 0;
}