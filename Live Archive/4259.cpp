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
int n, m, k;
const int ND = 500, ED = 5 * 10010;
int prv[ND], last[ND], dist[ND];
int to[ED], cost[ED], cap[ED], nxt[ED], pot[ED];
int E = 0, N = 0, minCost = oo, maxFlow = 0;

void init(int Nodes){
	for (int i = 0; i < ND; i++) last[i] = -1 , pot[i] = 0;  // clr
	maxFlow = E = 0;
	N = Nodes;
	minCost = oo;
}
void addEdge(int u, int v, int cp, int w){
	to[E] = v, cap[E] = cp, cost[E] = w, nxt[E] = last[u], last[u] = E++;
	to[E] = u, cap[E] = 0, cost[E] = w, nxt[E] = last[v], last[v] = E++;
}

int MCMF(int src, int dest , int max_m){
	for (int i = 0; i < E; i+= 2){
		cap[i] = 1;
		cap[i + 1] = 0;
	}
	maxFlow = 0;
	int lp = k;
	while (lp--){
		for (int i = 0; i < ND; i++) prv[i] = -1; 
		prv[src] = 0;
		queue<int>pq;
		pq.push(src);
		while (!pq.empty()){
			int p = pq.front();
			pq.pop();
			for (int e = last[p]; e != -1; e = nxt[e]){
				if (cost[e] > max_m || cap[e] <= 0|| prv[to[e]] != -1) continue;
				prv[to[e]] = e;
				pq.push(to[e]);
			}
		}
		if (prv[dest] == -1)
			return 0;
		int f = cap[prv[dest]];
		for (int i = dest; i != src; i = to[prv[i] ^ 1]) f = min(f, cap[prv[i]]);
		for (int i = dest; i != src; i = to[prv[i] ^ 1]){
			cap[prv[i]] -= f;
			cap[prv[i] ^ 1] += f;
		}
		maxFlow += f;
	}
	return  1;
}
int main()
{
	Emsawy();
	int c = 0;
	while (cin>>n){
		if (n == 0) break;
		cin >> m;
		init((n+1) * 2 + 2);
		for (int i = 1; i <= n;i++)
			addEdge(i * 2, i * 2 + 1, oo, 0);
		addEdge(0 * 2, 0 * 2 + 1, 0, 0);
		addEdge((n + 1) * 2, (n + 1) * 2 + 1, 0, 0);

		int u, v, w;
		for (int i = 0; i < m; i++){
			sf3(u, v, w);
			if (u > v) swap(u, v);
			addEdge(u * 2 + 1 , v * 2, 1, w);
		}
		cin >> k;
		int s = 0, e = 1e7, res = 0;
		while (s <= e){
			int mid = (s + e) / 2;
			if (MCMF(1, (n+1) * 2, mid)) e = mid - 1, res = mid;
			else s = mid + 1;
		}
		if (MCMF(1, (n+1) * 2, res)) printf("Case %d: %d\n", ++c, res);
		else printf("Case %d: no solution\n", ++c);
	}
	return 0;
}
