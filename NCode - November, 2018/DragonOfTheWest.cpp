#include <bits/stdc++.h>
using namespace std;
int dfs(vector<int> *graph, int s, vector<bool> &seen) 
{ 
	seen[s] = true; 
	int count = 1;
	for (int i = 0; i < graph[s].size(); ++i) 
	{ 
		int v = graph[s][i]; 
		if (!seen[v]) 
		{ 
			count += dfs(graph, v, seen); 
		} 
	}
	return count;
}
int main() 
{ 
	int n, m; 
	cin >> n >> m;
	vector<int> graph[n + 1]; 
	for (int i = 0; i < m; ++i) 
	{ 
		int a, b; 
		cin >> a >> b;
		graph[a].push_back(b); 
		graph[b].push_back(a);
	}
	vector<bool> seen(n + 1, false); 
	vector<int> conn_sz; 
	for (int i = 1; i <= n; ++i) 
	{ 
		if (!seen[i]) 
		{ 
			int length = dfs(graph, i, seen); 
			conn_sz.push_back(length); 
		} 
	}
	sort(conn_sz.begin(), conn_sz.end());
	int max_1 = conn_sz.back(); 
	int max_2 = (conn_sz.size() > 1 ? conn_sz[conn_sz.size() - 2] : 0);
	cout << max_1 + max_2 << '\n';
}
