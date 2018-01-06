#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<pair<int,int> > > adj;
int n, m, k, w, h;

const int N = 400 * 2 + 10, E = 4000;
int to[E], cost[E], cap[E], last[N], nxt[E], prv[N], pot[E], dist[N], e, Nodes, minCost, maxFlow;
void init(int nodes){
	clr(last, -1);
	clr(pot, 0);
	maxFlow = minCost = e = 0;
	Nodes = nodes;
}

void addEdge(int u, int v, int cp, int w){
	to[e] = v, cap[e] = cp, cost[e] = w, nxt[e] = last[u], last[u] = e++;
	to[e] = u, cap[e] = 0, cost[e] = -w, nxt[e] = last[v], last[v] = e++;
}
void MCMF(int src, int dest){
	while (true){
		clr(prv, -1);
		for (int i = 0; i < Nodes; i++) dist[i] = oo;
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
		for (int i = 0; i < Nodes; ++i) if (prv[i] != -1) pot[i] += dist[i];
	}
}
char g[50][50];

int main() {

	Emsawy();
	int T;
	cin >> T;
	while (T--){
		scanf("%d %d\n", &n, &m);
		for (int i = 0; i < n; i++){
			gets(g[i]);
		}
		int src = n * m, sink = n * m + 1, cnt = 0;
		init(n * m + 2);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (g[i][j] == '*'){
					cnt++;
					if ((i + j) % 2 == 1){
						for (int k = 0; k < 4; k++){
							int x = dx[k] + i, y = dy[k] + j;
							if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != '*') continue;
							addEdge(i * m + j, x * m + y, 1, 0);
						}
						addEdge(src, i * m + j, 1, 0);
					}
					else{
						addEdge(i * m + j, sink, 1, 0);
					}
				}
			}
		}
		MCMF(src, sink);
		printf("%d\n", (cnt - maxFlow * 2) + maxFlow);
	}
	return 0;
}
