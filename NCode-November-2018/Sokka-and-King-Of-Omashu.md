# Sokka and King of Omashu

##### Problem Statement

[Link](https://www.hackerrank.com/contests/uvce-ncode-november-2018/challenges/sokka-and-king-of-omashu) to problem statement.

##### Editorial
Either x coordinate or y coordinate of initial and final position are same, therefore it shares a column or a row (lies in a straight line).
As direction doesn't matter, we assume they lie in same column, let us say initial and final positions are (x, ys) and (x, yd) respectively with yd &ge; ys.
Any such query can be done in constant time owing to a pattern.

Pattern: 0, 3, 2, 3, 2, 3, 4, 5, 4, 5, 6, 7, 6, 7 ...
	here Pattern[i] -> minimum number of steps required to reach if yd - ys = i.

Creating this pattern.
<pre>
This pattern can be obtained using 3 columns with x coordinates, x - 1, x, x + 1.
(NOTE : column x - 1 and x + 1 will be same as both are same to knight)
	x - 1 ->	3 2 1
	x     ->	0 3 2
	x + 1 ->	3 2 1
	
These staring 9 cells can easily be confirmed to be minimum number of steps to reach from (x, ys) (till now pattern is done till 0, 3, 2).
(x + 1, ys + 3) can be reached from (x - 1, ys + 2) and (x, ys + 3) can be reached from (x + 1, ys + 1) in 1 step. So now ..

	x - 1 ->	3 2 1 2
	x     ->	0 3 2 3
	x + 1 ->	3 2 1 2
		
	again (x + 1, ys + 4) = (x - 1, ys + 3) + 1,
		  (x, ys + 4) = (x + 1, ys + 2) + 1,
		
	x - 1 ->	3 2 1 2 3
	x     ->	0 3 2 3 2
	x + 1 ->	3 2 1 2 3
		
by repetedly doing it we can get the pattern in x (column).</pre>

##### Proof: 

We can create the pattern, now we prove that it is the minimum possible.

Note:
- Odd number of moves required to traverse to cell with different color and even number of moves required for traversing in same colour cells.
- Max (y2 - y1) which can be achieved in n steps is 2 * n, as +2 is max change in one direction for knights move.
	So we define limit (n) = 2 * n.
		   
Let ans(n) be the function which gives minimum steps to reach from (x, ys) to (x, ys + n).

To prove: Pattern[n] == ans (n) it is sufficient to show that  limit (Pattern[n] -2) &lt; n &le; limit (Pattern[n])

- When n is even
<pre>
	ans (n) will also be even (owing to NOTE(1)).
		n \le limit( ans (n)), when n == limit (Pattern[n]) then Pattern[n] == ans (n).
		Pattern for even indices is 2, 2, 4, 4, 6, 6, 8, 8, 10, 10... more formally Pattern[n] = ceil(n / 4) * 2
		n = k * 4 + r, where r can be 0, 2
		when r == 0,
			n = k * 4
			ceil(n / 4) * 2 = k * 2, therefore, 
			limit (Pattern[n]) = k * 4 = n, ans (n) == Pattern[n].
		when r == 2,
			n = k * 4 + 2
			ceil(n / 4) * 2 = (k + 1) * 2 = k * 2 + 2 therefore, 
			limit (Pattern[n]) = k * 4 + 4 &ge; n
			limit (Pattern[n] - 1) = k * 4 + 2 = n
		    as limit (x - 1) &lt; limit (x),  limit (Pattern[n] - 2)  &lt; n  &le; limit (Pattern[n])
		Hence we have proved that Pattern[n] has to be the answer for even n.
        </pre>
        
- When n is odd
<pre>
	Pattern for odd indices is defined as Pattern[n] = ceil ((n -1) /4) * 2 + 1, for n = (3, 5, 7, 9...)
		when n = 4 * k + 1
			Pattern[n] = k * 2 + 1
			limit (Pattern[n]) = k * 4 + 2 &gt; n
			limit (pattern[n] - 1) = k * 4  &lt; n
			therefore limit (Pattern[n] - 2) &lt; n &le; limit (Pattern[n])
		when n = 4 * k + 3
			Pattern[n] = k * 2 + 3
			limit (Pattern[n]) = k * 4 + 6 &gt; n
			limit (Pattern[n] - 2) = k * 4 + 2 &lt; n
		therefore for odd number also Pattern[n] = ans (n)
	Hence proved for n &gt; 1 that Pattern[n] = ans (n)
</pre>

			

##### Solution (C++)

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll d = max(abs(x1 - x2), abs(y1 - y2));

        if (d == 0) {
            cout << 0 << '\n';
            continue;
        }

        if (d == 1) {
            cout << 3 << '\n';
            continue;
        }
        
        ll res = ((d - 2) / 4 + 1) * 2;
        if (d % 2 != 0) {
            ++res;
        }

        cout << res << '\n';
    }
}

```
##### Time complexity: O(t) 
##### Space complexity: O(1)
