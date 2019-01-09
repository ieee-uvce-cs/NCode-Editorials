#include <bits/stdc++.h>
using namespace std; 
using ll = long long int; 
constexpr int N = 1e5 + 1;
int res[N];
void precal() 
{ 
	// fill res with 2, as f(1) and f(2) will divide every number. 
	fill(res, res + N, 2);
	// exceptions. 
	res[0] = res[1] = 0; 
	res[2] = 1;
	// sieve. 
	for (int i = 3; i < N; ++i) 
	{ 
		for (int j = 2 * i; j < N; j += i) 
		{ 
			++res[j]; 
		} 
	}
}
int main() 
{ 
	int q; 
	cin >> q;
	precal();
	while (q--) 
	{ 
		int x; 
		cin >> x;
		cout << res[x] << '\n';
	}
}