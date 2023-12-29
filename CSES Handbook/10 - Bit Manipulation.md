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