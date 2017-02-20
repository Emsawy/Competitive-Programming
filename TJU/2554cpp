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
#include <functional>


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
V<V<pair<int, int> > > adj;
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
int n, m, k , path[70]  , g[70] , ok = 0 , put = 0 , vl[70];
void shortestpath(int s, int e){
	for (int i = 0; i < 70; i++)
		g[i] = oo, path[i] = -1 , vl[i] = 0;
	g[0] = 0;
	priority_queue<pair<int, int>, V<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(MP(g[0], 0));
	while (!pq.empty()){
		pair<int, int>p = pq.top();
		pq.pop();
		for (int i = 0; i < adj[p.second].size(); i++){
			pair<int, int>ch = adj[p.second][i];
			int now = p.first + ch.second;
			if (g[ch.first] <= now) continue;
			g[ch.first] = now;
			path[ch.first] = p.second;
			vl[ch.first] = ch.second;
			pq.push(MP(g[ch.first], ch.first));
		}
	}
	if (g[e] == oo){
		ok = -2;
		return;
	}
	ok++;
	put += g[e];
	if (ok == 2)return;
	while (path[e] != -1){
		int a = path[e], b = e;
		adj[a].erase(find(adj[a].begin(), adj[a].end(), MP(e, vl[e])));
		adj[e].push_back(MP(a, -(vl[e])));
		e = path[e];
	}
}
int main()
{
	Emsawy();
	int c = 0;
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		adj.clear();
		adj.resize(n);
		int u, v, w;
		for (int i = 0; i < m; i++){
			sf3(u, v, w);
			adj[u].push_back(MP(v, w));
		}
		shortestpath(0, n - 1);
		shortestpath(0, n - 1);
		if (ok == 2) printf("Instance #%d:  %d\n",++c , put);
		else printf("Instance #%d:  Not possible\n" , ++c);
		put = ok = 0;
	}
	return 0;
}
