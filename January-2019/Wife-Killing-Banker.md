# Wife Killing Banker

##### Problem Statement

[Link](https://www.hackerrank.com/contests/uvce-ncode-january-2019/challenges/wife-killing-banker) to problem statement.

##### Editorial
Explanation:
	Using given operation it is possible to change every element to a single element of array.
	Now we need to find elements in arrays which have minimum diffirence, as we know it has to be some element of array.
	To find the min difference we can do the following :
		Let us say two arrays are A and B. Also we have variable mi = 10<sup>18</sup>.
		1. We sort array B
		2. For every element of A we do a binary search on B to find two closest element to it, then we update mi incase this diff is smaller than mi. 

Proof: 

	Here we proove that whole array can be changed to any element of array.
	Suppose we have an array A and we wanted to change all its elements to A[x].
		1. We can always make a[0] equal to a[1] as it is the only neighbour, can easily be shown :
			if a[1] > a[0] then a[0] in min and a[1] is max hence we can change a[0] to a[1]
			if a[1] < a[0] non a[0] is max ans a[1] is min again we can change a[0] to a[1]
			else they are already equal
		2. Same goes with a[n - 1] and a[n - 2], a[n - 1] can always be made equal to a[n - 2]
		3. When we make a[0] = a[1], then we can make a[1] = a[2] as a[0] is equal to a[1] it doesn't contribute to the comparision, and after we havev changed a[1] we can again change a[0] to a[1].
		4. Now if we keep doing it we can make a[0] = a[1] = a[2] ... = a[x - 1] = a[x] and similarly a[n - 1] = a[n - 2] = a[n - 3] ... = a[x + 1] = a[x], hence making all elements equal to a[x].



##### Solution (C++)

```cpp
#include <bits/stdc++.h>

using namespace std;

int main () { 
	int n;
	cin >> n;
	int ar[n], br[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}	
	for (int i = 0; i < n; i++) {
		cin >> br[i];
	}
	sort (br, br + n);
	int mi = abs (br[0] - ar[0]);
	for (int xx : ar) {
		auto itr = upper_bound (br, br + n, xx);
		if (itr != br + n) {
			mi = min (abs (*itr - xx), mi);
		}
		if (itr != br) {
			mi = min (abs (*(--itr) - xx), mi);
		}
	}
	cout << mi << "\n";
}

```
##### Time complexity: O (N * Log (N))
##### Space complexity:	O (N)
