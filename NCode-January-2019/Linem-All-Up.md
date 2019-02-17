# Line'm All Up

##### Problem Statement

[Link](https://www.hackerrank.com/contests/uvce-ncode-january-2019/challenges/linem-all-up-) to problem statement.

##### Editorial

*sum[i] =* Number of ways to arrange till length *i* with last element of any type.

*dp[i][j] =* Number of ways to arrange the rack till length *i* with last cigarette of type *j*.

This implies number of ways to fill i<sup>th</sup> index as type j *= number of ways to arrange till (i - 1) - (number of ways in which the elements i - L[j] to i - 1 are of type j)*, because in this case placing *i<sup>th</sup>* element as type *j* will exceed *j*'s threshold *L[j]*. i.e,

*dp[i][j] = sum[i - 1] - **&Sigma;** dp[k][j], where k = i - L[i] - 1 to i - 1*


Now, number of ways in which the elements *i - L[j]* to *i - 1* are of type *j = no of ways to arrange till i - L[j] - 1 - (number of ways to arrange till i - L[j] - 1 with last cigarette of type j)*, because in this case it will not be possible to place *L[j]* number of *j* type elements from *i - L[j]* to *i - 1* due to threshold. i.e, 

*dp[i][j] = sum[i - 1] - (sum[i - L[j] - 1] - dp[i - L[j] - 1][j]);*


##### Solution (C++)

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 2e3 + 3;

ll dp[N][N];
ll sum[N];

int main() {
    int n, k;
    cin >> n >> k;

    int l[k];
    for (int i = 0; i < k; ++i) {
        cin >> l[i];
    }

    sum[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i][j] = sum[i - 1];
            if (i > l[j]) {
                dp[i][j] = (sum[i - 1] - (sum[i - l[j] - 1] - dp[i - l[j] - 1][j]) + MOD) % MOD;
            }

            sum[i] = (sum[i] + dp[i][j]) % MOD;
        }
    }

    cout << sum[n] << '\n';
}

```
##### Time complexity: O(N * K) 
##### Space complexity: O(N + N * K)
