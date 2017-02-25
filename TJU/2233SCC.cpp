#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>


using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define sz(v) ((int)((v).size()))
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<int > > adj;
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
int n, m, k , u , v;
const int si = 100005;
stack<int>st;
int instack[si], low[si], dfn[si] , wi[si] , SCC[si] , comp = 0;
void SCCF(int nd , int depth = 0){
	dfn[nd] = low[nd] = depth;
	instack[nd] = 1 , st.push(nd);
	for (int i = 0; i < adj[nd].size(); i++){
		int ch = adj[nd][i];
		if (dfn[ch] == -1){
			SCCF(ch, depth + 1);
			low[nd] = min(low[nd], low[ch]);
		}
		else if (instack[ch]){
			low[nd] = min(low[nd], dfn[ch]);
		}
	}
	if (low[nd] == dfn[nd]){
		int node = -1;
		while (node != nd){
			node = st.top();
			instack[node] = 0;
			SCC[node] = comp;
			st.pop();
		}
		comp++;
	}
}
void SCCF2(){
	clr(dfn, -1);
	for (int i = 0; i < n; i++){
		if (dfn[i] != -1) continue;
		SCCF(i, 0);
	}
}
int main()
{
	Emsawy();
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		adj.clear();
		adj.resize(n);
		for (int i = 0; i < n; i++)
			sf(wi[i]);
		for (int i = 0; i < m; i++){
			sf2(u, v);
			u--, v--;
			adj[u].push_back(v);
		}
		SCCF2();
		int mn[si], mark[si] = { 0 };
		for (int i = 0; i < si; i++) mn[i] = -1;
		for (int i = 0; i < n; i++){
			if (mn[SCC[i]] == -1 || mn[SCC[i]] > wi[i]){
				mn[SCC[i]] = wi[i];
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < adj[i].size(); j++){
				int ch = adj[i][j];
				if (SCC[ch] != SCC[i]){
					mark[SCC[ch]] = 1;
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < comp; i++){
			if (mark[i] == 1) continue;
			ans += mn[i];
		}
		cout << ans << endl;
		comp = 0;
	}
	return 0;
}
