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
  