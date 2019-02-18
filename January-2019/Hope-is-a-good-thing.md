# Hope is Good Thing

##### Problem Statement

[Link](https://www.hackerrank.com/contests/uvce-ncode-january-2019/challenges/hope-is-a-good-thing) to problem statement.

##### Editorial
	Problem was about finding hidden number X using a string S of 1's and 0's where, 
		S[i] = 0, when X % 2 ^ i < X mod 2 ^ (i + 1)
		S[i] = 1, when X % 2 ^ i >= X mod 2 ^ (i + 1)
	Main idea is, if we know that y =  X % 2 ^ i, then we can get the value of X % 2 ^ (i + 1) just by knowing if S[i] is 0 or 1, so by building on that,  then in end we can have exact value of  X % 2 ^ 31 and as 2 ^ 31 > 2 * 10 ^ 9 we	would know exact value of X.
	While you register that have a look at this :
		X % 2 ^ (i + 1) can take values : 0, 1, 2 ... 2 ^ i - 1, 2 ^ i, 2 ^ i + 1 ... 2 ^ (i + 1) - 1 X % 2 ^ i cat take values       : 0, 1, 2 ... 2 ^ i - 1, 0, 1 ... 2 ^ i - 1.  Note that X % 2 ^ (i + 1) is either y or y + 2 ^ i therefore, 
			if S[i] = 0 that means X % 2 ^ (i + 1) = y + 2 ^ i
			else X % 2 ^ (i + 1) = y
		So we know how to calculate X % 2 ^ (i + 1) from X % 2 ^ i using S[i], but we need exact value of X % 2 ^ i for some i,
			if s[0] = 0 that means X % 1 < X % 2 hence X % 2 = 1
			else if s[0] = 1 that would mean X % 2 = 0
	Now we know X % 2 we can build upto X % 2 ^ 31 which will be our X.

##### Solution (C++)

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	ios_base :: sync_with_stdio (NULL);
	cin.tie (0);
	int t ;
	cin >> t;
	while (t--) {
		string st;
		cin >> st;
		assert (st.size () == 30);
		ll x = 1, y = 2, rem = 0;
		for (int i = 0; i < 30; i++) {
			if (st[i] == '0') {
				rem += x;
			}
			x = y;
			y *= 2;
		}
		cout << rem << "\n";
	}
}

```
##### Time complexity: O (T)
##### Space complexity: O (1)
