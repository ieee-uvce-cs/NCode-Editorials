# Rita Hayworth

### Problem Statement

[Link](https://www.hackerrank.com/contests/uvce-ncode-january-2019/challenges/rita-hayworth) to problem statement.

### Editorial
In this problem, we wish to minimize the cost needed to take the package from R (Red) to A (Andy). Since the G(Good) cells transport Rita Hayworth free of cost, we only need the services of Brooks each time we encounter a block of B (Bad) cells.
We scan the string that represents the row of cells and keep track of the cost.
We begin updating the cost once we are inbetween R and A as follows
```
 C->C+2  at index  i if A[i] == 'B'  &  A[i-1] != 'B'
 C->C+1  at index  i if A[i] == 'B'  &  A[i-1] ==' B'
 ```
 This is because the number of exchanges performed across each block of B's is 1 + the number of cells within the block.
 Finally when we reach the other character (R or A), we stop iterating.
 Note: The cost remains the same if we swap the cells with R and A.

##### Solution (C++)

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int i = s.find('A');
    int j = s.find('R');

    if (i > j) {
        swap(i, j);
    }

    int bad_guys = 0, groups = 0;
    for (int k = i + 1; k < j; ++k) {
        if (s[k] == 'B') {
            ++groups;
        }

        while (k < j && s[k] == 'B') {
            ++bad_guys;
            ++k;
        }
    }

    cout << bad_guys + groups << '\n';
}

```
##### Time complexity: O(N)
##### Space complexity: O(N) to store the string where N is the length of the string.

