# Aang's Attack

##### Problem Statement

[Link](https://www.hackerrank.com/contests/uvce-ncode-november-2018/challenges/aangs-attack) to problem statement.

##### Editorial
```
Number of people of island i is f(i), given f (i) = f(i - 1) + f(i - 2) clearly this function if famous fibonacci function.
Given an island number x problem is to find number of island y such that fib (y) | fib (x) , where y < x.
Key is to note that fib (a) | fib (b) if and only if a | b , therefore problem breks down to findig number of divisors x (excluding itself).

Brute for counting numeber of divisors
	Iterate from [1, x), then check if it divides x. This is O(n)
	So we can answer each query linear time (that is operation performed is realted linearly to x), worst case we has x = 10^5  for each query and maximum number of queries are 10^4 which makes overall operations 10^9.
	10^9 is too much for 2 sec time limit.
Pre calcultion
	Idea is to calculate and store no of divisors of every x &le; 10^5, and then answering any query would be instant.
	We can do precomputation as following
		for (int i = st; i &lt; en; i++) { 		  	// First loop
			for (int j = i * 2; j &lt; en; j += i) {   // Second loop
				div[j]++; 							// An array which stores then number of divisors
			}
		}
	Loop 2 runs (en - i) / j times for each i, i goes from 2 to 10^5 in our case, therfore
	total operation = (10^5 - 1) / 1 + (10^5 - 2) / 2 + (10^5 - 3) / 3 .... (10^5 - 10^3) / 10^3 .. 3 / (10^5 - 3) + 2 / (10^5 - 2) + 1 / (10^5 - 1) + 0, in this summation staring terms decrease at fine rate and complexity
	turns out to be O (n * log (n)).
	For for insight on how O(n * log (n)) refer https://en.wikipedia.org/wiki/Harmonic_number .
```

##### Proof 
```
fib (a) | fib (b) if and only if a | b, can be proved using basic property of fibonacci
fib (x) * fib (y - 1) + fib (x + 1) * fib (y) = fib (x + y) - eq (1)
if we put y = x here we get, 
fib (x) * (fib (y - 1) + fib (x + 1)) = fib (2x), therefore fib (x) | fib (2x) now again we can get fib (2x) | fib (3x) and rest is Mathematical Induction.
We know that if a divides b then fib (a) divides fib (b), gcd (fib (a), fib (a + 1)) = 1, 
```
refer [link](https://math.stackexchange.com/questions/24378/prove-that-any-two-consecutive-terms-of-the-fibonacci-sequence-are-relatively-pr)
```	
In eq (1) 
gcd (fib (x), fib(x + 1)) = 1
gcd (fib (y - 1) , fib (y)) = 1
Let us assum there is a k such that fib (k) | fib (k *q + r) , where r E [1, k - 1]
fib (k * q) * fib (r -1) + fib (r) * fib(k * q + 1) = fib (k * q + r)  (using eq (1))
as fib (k) | fib (k * q) , for fib (k) to divide fib (k * q + r) it must divide fib (r) * fib (k * q + 1)
but gcd (fib (k * q + 1), fib (k)) = 1
we have fib (k) must divide fib (r) which is not possible as r < k 
therefore by contradiction we now we know it is not possible and r must be equal to 0.
```	

##### Solution (C++)

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
constexpr int N = 1e5 + 1;

int res[N];

void precal() {
    // fill res with 2, as f(1) and f(2) will divide every number.
    fill(res, res + N, 2);

    // exceptions.
    res[0] = res[1] = 0;
    res[2] = 1; 

    // sieve.
    for (int i = 3; i < N; ++i) {
        for (int j = 2 * i; j < N; j += i) {
            ++res[j];
        }
    }
}

int main() {
    int q;
    cin >> q;

    precal();

    while (q--) {
        int x;
        cin >> x;

        cout << res[x] << '\n';
    }
}

```
##### Time complexity: O(t + NlogN) 
##### Space complexity: O(N)
