//
// Created by Stephen Ni on 2023-12-21.
//

//
// Created by Stephen Ni on 2023-12-21.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;

        int length = word.length();

        if (length <= 10) {
            cout << word << endl;
        }
        else {
            cout << word[0] << word.length()-2 << word[word.length()-1] << endl;
        }
    }




    return 0;
}