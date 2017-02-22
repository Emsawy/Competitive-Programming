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
V<V<int> > adj;
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9, si = 10004;
int n, m, k , vs[si] , cur = 1 , unknow[si] , wi[si];
void mark(int nd){
	vs[nd] = cur;
	for (int i = 0; i < sz(adj[nd]); i++){
		int ch = adj[nd][i];
		if (vs[ch] == cur) continue;
		mark(ch);
	}
}
int cycl(int nd , int x = oo){
	if (vs[nd] == cur) return x;
	vs[nd] = cur;
	int mn = oo;
	for (int i = 0; i < sz(adj[nd]); i++){
		int ch = adj[nd][i];
		mn = min(mn, cycl(ch , min(x , wi[nd])));
	}
	return mn;
}
int main()
{
	Emsawy();
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		int u, v;
		adj.clear(); adj.resize(n);
		for (int i = 0; i < n; i++)sf(wi[i]);
		for (int i = 0; i < m; i++){
			sf2(u, v);
			u--, v--;
			adj[u].push_back(v);
			unknow[v] = 1;
		}
		ll ans = 0;
		for (int i = 0; i < n; i++){
			if (unknow[i]) continue;
			mark(i);
			ans += wi[i];
		}
		cur++;
		for (int i = 0; i < n; i++){
			if (vs[i]) continue;
			int mn = cycl(i);
			if (mn == oo) continue;
			ans += mn;
			cur++;
			mark(i);
		}

		cout << ans << endl;
		for (int i = 0; i < si; i++)
			unknow[i] = vs[i] = 0;
		cur = 1;
	}
	return 0;
}
