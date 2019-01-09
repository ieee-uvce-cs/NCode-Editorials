#include <bits/stdc++.h>
using namespace std; 
using ll = long long int;
/* * O(n * k) solution. * * O(n) solution is also possible. */
int main() 
{ 
	int n, k; ll x, y; cin >> n >> k >> x >> y;
	ll h[n]; 
	for (int i = 0; i < n; ++i) 
	{ 
		cin >> h[i]; 
	}
	ll z = x * y; 
	int res = -1; 
	for (int i = 0; i <= n - k; ++i) 
	{ 
		int count = 0; 
		for (int j = i; j < i + k; ++j) 
		{ 
			count += (h[j] <= z); 
		}
		res = max(res, count);
	}
	cout << res << '\n';
}
