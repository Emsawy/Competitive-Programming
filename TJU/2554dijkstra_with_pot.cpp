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
const int ND = 70, ED = 2 * 10010;
int to[ED], cost[ED], cap[ED], last[ND], nxt[ED], prv[ND], pot[ED], dist[ND], E = 0, N = 0, minCost = 0, maxFlow = 0;
void init(int Nodes){
	for (int i = 0; i < ND; i++) last[i] = -1 , pot[i] = 0;  // clr
	maxFlow = minCost = E = 0;
	N = Nodes;
}
void addEdge(int u, int v, int cp, int w){
	to[E] = v, cap[E] = cp, cost[E] = w, nxt[E] = last[u], last[u] = E++;
	to[E] = u, cap[E] = 0, cost[E] = -w, nxt[E] = last[v], last[v] = E++;
}

void MCMF(int src, int dest){
	while (true){
		for (int i = 0; i < ND; i++) prv[i] = -1; // clr
		for (int i = 0; i < N; i++) dist[i] = oo;
		dist[src] = prv[src] = 0;
		priority_queue<pair<int, int>, V<pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push(MP(0, src));
		while (!pq.empty()){
			pair<int, int> p = pq.top();
			pq.pop();
			for (int e = last[p.second]; e != -1; e = nxt[e]){
				int now = dist[p.second] + cost[e] + pot[p.second] - pot[to[e]];
				if (dist[to[e]] <= now || cap[e] <= 0) continue;
				dist[to[e]] = now;
				prv[to[e]] = e;
				pq.push(MP(now, to[e]));
			}
		}
		if (prv[dest] == -1) break;
		int f = cap[prv[dest]];
		for (int i = dest; i != src; i = to[prv[i] ^ 1]) f = min(f, cap[prv[i]]);
		for (int i = dest; i != src; i = to[prv[i] ^ 1]){
			cap[prv[i]] -= f;
			cap[prv[i] ^ 1] += f;
		}
		maxFlow += f;
		minCost += f*(dist[dest] - pot[src] + pot[dest]);
		for (int i = 0; i < N; ++i) if (prv[i] != -1) pot[i] += dist[i];
	}
}
int main()
{
	Emsawy();
	int c = 0;
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		init(n + 1);
		int u, v, w;
		for (int i = 0; i < m; i++){
			sf3(u, v, w);
			addEdge(u+1, v+1, 1, w);
		}
		addEdge(0, 1, 2, 0);
		MCMF(0, n);
		if (maxFlow == 2) printf("Instance #%d:  %d\n", ++c, minCost);
		else printf("Instance #%d:  Not possible\n", ++c);
	}
	return 0;
}
