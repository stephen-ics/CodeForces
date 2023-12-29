# Bit Manipulation
## Bit Representation
- In programming, an n bit integer is internally stored as a binary number that consists of n bits
- The C++ type `int` is a 32-bit type
- The bit representation of a number is either `signed` or `unsigned`
  - A `signed` representation allows for both negative and positive numbers, a signed variable of `n` bits can contain any integer between `-2^(n-1)` and `2^(n-1) -1`
    - For example the `int` type in C++ is a signed type so an `int` variable can contain any integer between `-2^31` and `2^31 - 1`
      - The first bit a signed representation is the sign of the number (0 for positive, 1 for negative), `twos complement form` is used
  - A `unsigned` representation only positive numbers can be used, so the upper bound for the values is larger, an unsigned integer variable can contain any integer between `0` and `2^n - 1`
  - There is a connection between the representations: a signed number `-x` equals an unsigned number `2^n - x`
  - If a number is larger than the upper bound of the bit representation, the number will overflow
    - In a signed representation the next number after `2^(n-1) - 1` is `-2^(n-1)`
    - In an unsigned representation the next number after `2^n - 1` is `0`

## Bit Operations
### And Operation
- The `and` operation `x & y` produces a number that has one bits in positions where both `x` and `y` have one bits
  - For example `22 & 26 = 18` because
  ```c++
    10110 (22)
  & 11010 (26)
    ----------
  = 10010 (18) 
  ```
  - Using the and operation, **we can check if a number `x` is even** because `x & 1 = 0` if `x` is even
  - More generally, if `x` is divisible by `2^k` exactly when `x & (2^k - 1) = 0`
  
### Or Operation
- The `or` operation `x | y` produces a number that has one bits in positions where at least one of `x` and `y` have one bits
- For example `22 | 26 = 30`, because
  ```c++
    10110 (22)
  | 11010 (26)
    ----------
  = 11110 (30)
  ```
  
### Xor Operation
- The `xor` operation `x ^ y` produces a number that has one bits in positions where exactly one of `x` and `y` have one bits
- For example `22 ^ 6 = 12`, because
  ```c++
    10110 (22)
  | 11010 (26)
    ----------
  = 01100 (12)
  ```
  
### Not Operation
- The `not` operation `~x` produces a number where all the bits of `x` have been inverted
- The formula `~x = -x - 1` holds, for example, `~29 = -30`
- The result of the `not` operation at the bit level depends on the length of the bit representation, because the operation inverts all bits
- For example, if the numbers are 32-bit `int` numbers, the result is as follows
  ```c++
   x =  29 00000000000000000000000000011101
  ~x = -30 11111111111111111111111111100010
  ```
  
## Applications
- A number of the form `1 << k` has a one bit in position `k` and all other bits are zero, so we can use such numbers to access single bits of numbers
- The `kth` bit of a number is one exactly when x & (1 << k) is not zero
- The following code prints the bit representation of an `int` number `x`
  ```c++
  for(int i = 31; i >= 0; i--) {
    if(x&(1<<i)) cout << "1";
    else cout << "0";
  }
  ```
- It is possible to modify single bits of numbers using similar ideas
- For example, the formula `x | (1 << k)` sets the `kth` bit of `x` to one, the formula `x & ~(1<<k)` sets the `kth` bit of `x` to zero, and the formula `x ^ (1 << k)` inverts the kth bit of `x`
- The formula `x & (x - 1)` sets the last one bit of `x` to zero, the formula `x & -x` sets all one bits to zero, and the formula `x | (x - 1)` inverts all bits after the one bit
- A positive number `x` is **a power of two exactly when** `x & (x - 1) = 0`

## Additional Functions
- The g++ compiler provides the following functions for counting bits
  - `__builtin__clz(x)`: the number of zeroes at the beginning of the number
  - `__builtin__ctz(x)`: the number of zeroes at the end of a number
  - `__builtin_popcount(x)`: the number of ones in the number
  - `__builtin_parity(x)`: the parity (even or odd) of the number of ones
  - The function can be used as follows
  ```c++
  int x = 5328 //00000000000000000001010011010000
  cout << __builtin_clz(x) << "\n"; // 19
  cout << __builtin_ctz(x) << "\n"; // 4
  cout << __builtin_popcount(x) << "\n"; // 5
  cout << __builtin_parity(x) << "\n"; // 1
  ```
  - While the above functions only support `int` numbers, there are also `long long` versions of the function available with the suffix `ll`

## Representing Sets
- Every subset of a set `{0, 1, 2, ..., n - 1}` can be represented as an `n` bit integer whose one bits indicate which elements belong to the subset
- This is an efficient way to represent sets because every element only requires one bit of memory and set operations can be implemented as bit operations
- Since `int` is a 32-bit type, an `int` number can represent any subset of the set `{0, 1, 2, ..., 31}`
- The bit representation of the set `{1, 3, 4, 8}` is `00000000000000000000000100011010`, which corresponds to the number `2^8 + 2^4 + 2^3 + 2^1 = 282`

### Set Implementation
- The following code declares an `int` variable `x` that can contain a subset of `{0, 1, 2, ..., 31}`
- After this, the code adds elements 1, 3, 4, and 8 to the set and prints the size of the set
  ```c++ 
  int x = 0;
  x |= (1<<1); // OR assignment operator (x = x | y)
  x |= (1<<3);
  x |= (1<<4);
  x |= (1<<8);
  cout << __builtin_popcount(x) << "\n" // 4
  ```
  - Then the following code prints all elements that belong to the set
  ```c++
  for(int i = 0; i < 32; i++) {
    if(x&(1<<i)) cout << i << " "; // output: 1, 3, 4, 8
  }
  ```
  
### Set Operations
- Set operations can be implemented as follows as bit operations:
  - intersection: `a & b`
  - union: `a | b`
  - complement `a~`
  - difference a & (~b) (what does a have that b does not have)
  ```c++
  int x = (1<<1)|(1<<3)|(1<<4)|(1<<8);
  int y = (1<<1)|(1<<6)|(1<<8)|(1<<9);
  int z = x | y;
  cout << __builtin_popcount(z) << "\n"; // 6
  ```
  - This constructs two sets `x = {1, 3, 4, 8}` and `y = {3, 6, 8, 9}`, then constructs the set `z = x (union) y = {1, 3, 4, 6, 8, 9`

### Iterating Through Subsets
- The following code goes through variations of iterating through a subset
  ```c++
  // code goes through the subsets of `{0, 1, ..., n-1}`:
  for(int b = 0; b < (1 << n); b++) { // b < (1 << n) compares two bits
    // process subset b
  }
  
  // code goes through the subset with exactly k elements
  for(int b =  0; b < (1<<n); b++) { 
    if(__builtin_popcount(b) == k) {
        // process subset b
    }
  }
  
  // code goes through the subsets of a set x
  int b = 0
  do { 
    // process subset b
  } while(b=(b-x)&x);
  ```

## Bit Optimizations
- Many algorithms can be optimized using bit operations
- Such optimizations do not change the time complexity of the algorithm, but they may have a large impact on the actual running time of the code
- In this section we discuss examples of such situations

### Hamming Distances
- The **Hamming distance** `hamming(a, b` between two strings `a` and `b` of equal length is the number of positions where the strings differ, for example `hamming(01101, 11001) = 2`
- Consider the following problem: Given a list of `n` bit strings, each of length `k`, calculate the minimum Hamming distance between two strings in the list
- A straightforward way to solve the problem is to go through all pairs of strings and calculate their Hamming distances, which yields an `O(n^2 * k)` time algorithm
- The following function can be used to calculate distances
  ```c++
  int hamming(string a, string b) {
    int d = 0;
    for(int i = 0; i < k; i++) {
        if(a[i] != b[i]) d++;
    }
  
    return d;
  }
  ```
  - However, if `k` is small, we can optimize the code by storing the bit strings as integers and calculating the Hamming distance using bit operations, in particular, if `k <= 32` we can just store the strings as `int` values and use the following function to calculate distances
  ```c++
  int hamming(int a, int b) {
    return __builtin_popcount(a^b);
  } 
  ```
  - In the above function, the `xor` operation constructs a bit string that has one bits in positions where `a` and `b` differ, then the number of bits is calculated using the `__builtin_popcount` function
  - A list of 10000 random bit strings of length 30 were used on each approach, the first method took 13.5 seconds while the second only took 0.5 seconds, the optimized code is almost 30x faster than the original code