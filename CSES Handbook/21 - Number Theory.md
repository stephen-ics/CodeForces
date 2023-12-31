# Number Theory
- Number theory is a branch of mathematics that studies integers
- Number theory is a fascinating field because many questions involving integers are very difficult to solve, even if they seem simple at first glance
- As an example consider the following question: `x^3 + y^3 + z^3 = 33`
  - It is easy to find three real numbers x, y, z that satisfy the equation, however it is an open problem in number theory if there are any three integers, `x`, `y`, and `z` that would satisfy the equation
  - In this chapter we will focus on the basic concepts and algorithms in number theory, we will assume all numbers are integers if not otherwise stated

## Primes and Factors
- A number `a` is called a **factor** or a **divisor** of a number b if a divides b
- If `a` is a factor of `b`, we write `a | b`, else we write `a ∤ b`
- For example, the factors of 24 are 1, 2, 3, 4, 6, 8, 12, and 24
- A number `n > 1` is a **prime** if its only positive factors `1` and `n`
- For every number `n > 1`, there is a unique **prime factorization** `n = p1^a1 * p2^a2 * ... * pk ^ ak`
  - Here `p1, p2, ..., pk` are distinct primes and `a1, a2, ..., ak` are positive numbers
  - For example the prime factorization for 84 is `2^2 * 3^1 * 7^1`
- The **number of factors** of a number `n` is the total product of the exponents of each prime factor
  - For example, the number `84` = `2^2 * 3^1 * 7^1` therefore the number of divisors in 84 will be `3 * 2 * 2 = 12`
  - This is because there are `ai + 1` ways to choose how many times a prime factor will appear in a factor (the +1 being if the prime factor is excluded in the factor)
- The **sum of factors** of `n` is equal to `(1 + pi + ... + pi^ai)`, equivalent to the product of `pi^(ai + 1) - 1 / pi - 1`, where the latter formula is based on the geometric progression formula
  - For example, the sum of factors of 84 is `(2^3 - 1 / 2 - 1) * (3^2 - 1 / 3 - 1) * (7^2 - 1 / 7 - 1) = 7 * 4 * 8 = 224`
- The **product of factors** of `n` is `n^(number of factors / 2)`, because we can form `number of products / 2` pairs from the factors, each with product `n`
  - For example, the factors of `84` produce the pairs `1 * 84, 2 * 42, 3 * 28, etc`, therefore the product of the factors will be `84^6 = 351298031616`
- A number `n` is called a **perfect number** if `n = sum of factors(n) - n`, or in other words `n` equals the sum of its factors between `1` and `n-1`
  - For example, 28 is a perfect number because `28 = 1 + 2 + 4 + 7 + 14`

### Number of Primes
- It is easy to show that there is an infinite number of primes, if the number of primes would be finite, we could construct a set P where `P = {p1, p2, ..., pn}` that would contain all the primes
- However, using P, we could form a new prime `(p1 * p2 * ... * pn) + 1`, that number will be larger than all elements in `P` and a prime, this is a contradiction and the number of primes has to be infinite

### Density of Primes
- The density of primes means how often there are primes among the numbers
- Let `π(n)` denote the number of primes between `1` and `n`, for example `π(10) = 4`, because there are 4 primes between 1 and 10: 2, 3, 5, and 7
- It is possible to show that `π(n) ≈ n / ln(n)`, which means that primes are quite frequent
  - For example, the number of primes between 1 and 10^6 is pi(10^6) = 78498, and 10^6 / ln(10^6) = 72382

### Conjectures
- There are many conjectures involving primes, most people think that these conjectures are true, however nobody has been able to prove them
- For example, the following conjectures are famous
  - **Goldbach's Conjecture**: Each even integer `n > 2` can be represented as a sum `n = a + b` where `a` and `b` are primes
  - **Twin Prime Conjecture**: There is an infinite number of pairs of the form `{p, p + 2}`, where both `p` and `p + 2` are primes
  - **Legendre's Conjecture**: There is always a prime between numbers `n^2` and `(n + 1)^2`, where `n` is any positive integer

### Basic Algorithms
- If a number `n` is not prime, it can be represented as a product `a * b`, where `a <= sqrt(n)` or `b <= sqrt(n)`, so it certainly has a factor between `2` and `floor(sqrt(n))`
- Using this observation we can both test if a number is a prime and find the prime factorizations of a number in `O(sqrt(n))` time
- The following function `prime` checks if the given number `n` is prime, the function attempts to divide `n` by all numbers between `2` and `floor(sqrt(n))`, and if none of them divides `n`, then `n` is a prime
    ```c++
    bool prime(int n) {
        if(n < 2) return false;
        for(int x = 2; x*x; <= n; x++) {
            if(n % x == 0) return false
        } 
        
        return true;
    }
    ```
- The following function `factors` constructs a vector that contains the prime factorizations of `n`, the function divides by `n` by its prime factors, and adds them to the vector
- The process ends when the remaining number `n` has no factors between `2` and `floor(sqrt(n))`, if `n > 1`, it is prime and the last factor
    ```c++
    vector<int> factors(int n) {
        vector<int> f;
        for(int x = 2; x * x <= n; x++) {
            while(n % x == 0) {
                f.push_back(x);
                n /= x;
            } 
        } 
  
        if(n > 1) f.push_back(n);
        return f;
    }
    ```
    - Note that each prime factor appears in the vector as many times as it divides the number, for example `24 = 2^3 * 3^1`, so the result of the function is `[2, 2, 2, 3]`, this function works because a prime divisor will always be found first before a composite divisor as the composite divisor will be divisible by some prime

### Sieve of Eratosthenes
- The **Sieve of Eratosthenes** is a preprocessing algorithm that builds an array using which we can check if a given number `n` is prime, and if it is not, find one prime factor of the number
- The algorithm builds an array `sieve` whose positions `2, 3, ..., n` are used
- The value `sieve[k] = 0` means that `k` is prime, and the value `sieve[k] != 0` means that `k` is not a prime and one of its prime factors is `sieve[k]`
- The algorithm iterates through the numbers `2` to `n` one by one, and when a new prime `x` is found, the algorithm records that the multiples of `x` are not primes, because the number `x` divides them
- The following code implements the Sieve of Eratosthenes, the code assumes that each element is initially 0
    ```c++
    for(int x = 2; x <= n; x++) {
        if(sieve[x]) continue;
        for(int u = 2*x; u M= n; u += x) {
            sieve[u] = x;
        }
    }
    ```
    - The inner loop of the algorithm is executed `n/x` times for each value `x`, thus an upper bound for the running time of the algorithm is the harmonic sum `n/2 + n/3 + n/4 + ... + n/n = O(n * log(n))`
    - In fact, the algorithm is more efficient because the inner loop will be executed only if the number `x` is prime, (here, 0 is interpreted as false and all other numbers are interpreted as true)
    - It can be shown that the running time of the algorithm is only  O(n * log(log(n))), a complexity very close to O(n)

