#include <bits/stdc++.h>
using namespace std; 
using ll = long long int;
int main() 
{ 
	int t; cin >> t;
	while (t--) 
	{ 
		ll x1, y1, x2, y2; 
		cin >> x1 >> y1 >> x2 >> y2;
		ll d = max(abs(x1 - x2), abs(y1 - y2));
		if (d == 0) 
		{ 
			cout << 0 << '\n'; continue; 
		}
		if (d == 1) 
		{ 
			cout << 3 << '\n'; continue; 
		}
		ll res = ((d - 2) / 4 + 1) * 2; 
		if (d % 2 != 0) 
		{ 
			++res; 
		}
		cout << res << '\n';
	}
}
