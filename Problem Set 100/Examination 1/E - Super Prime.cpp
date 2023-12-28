//
// Created by Stephen Ni on 2023-12-28.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkInVector(vector<int> nums, int num) {
    for(int i = 0; i < nums.size(); i++) {
        if(num == nums[i]) {
            return true;
        }
    }

    return false;
}

int main() {
    // this problem is find all primes within + 2 sum
    int n;
    cin >> n;

    vector<bool> isPrime(n+1, true);
    for(int i = 2; i < n; i++) {
        if(isPrime[i]) {
            for(int j = i*2; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    unordered_map<int, int> hash_table_primes;
    unordered_map<int, int> hash_table_super_primes;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            hash_table_primes[i] = i;
        }
    }

    for(int i = 2; i < n-1; i++) {
        if(hash_table_primes.find(i) != hash_table_primes.end()) {
            int sum = i + 2;
            if(hash_table_primes.find(sum) != hash_table_primes.end()) {
                if(hash_table_super_primes.find(sum) == hash_table_super_primes.end()) {
                    hash_table_super_primes[sum] = 0;
                }
            }
        }
    }

    int count = hash_table_super_primes.size();

    cout << count;

    return 0;
}

// prime sieve is n * logn
// pushing primes to vector is n
// i need to use hash map to make it O(1) to check