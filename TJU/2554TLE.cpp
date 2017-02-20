#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include <numeric>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define sz(v)				((int)((v).size()))
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
int n, m;
struct edge {
	int from, to, w;
	edge(int from, int to, int w) : from(from), to(to), w(w) {}
	bool operator < (const edge & e) const {
			w > e.w;
	}
};
const int MX = 70;
int prv[MX], dist[MX];
bool BMF(V<edge> edges , int src){
	for (int i = 0; i < MX; i++)
		dist[i] = oo, prv[i] = -1;
	int N = sz(edges);
	if (sz(edges) == 0) return 0;
	dist[src] = 0;
	for (int i = 0, r = 0; i < N + 1; i++, r = 0){
		for (int j = 0; j < sz(edges); j++){
			edge ne = edges[j];
			if (dist[ne.to] > dist[ne.from] + ne.w){
				dist[ne.to] = dist[ne.from] + ne.w;
				prv[ne.to] = ne.from, r++;
			}
		}
		if (!r) break;
	}
	return 0;
}
int const I = 70, J = 70;
int costMax[I][J], capMax[I][J] , ok = 0 , vs[I][J] , cpy[I][J];
priority_queue<int> cp[I][J];
V<edge>edgeList;
pair<ll,ll> MCMF(int src , int dest){
	ll maxFlow = 0, minCost = 0;
	BMF(edgeList, src);
	if (dist[dest] >= +oo) return MP(-oo, -oo);
	int bottleNeck = oo, bk = dest;
	while (prv[bk] != -1)
		bottleNeck = min(bottleNeck, capMax[prv[bk]][bk]), bk = prv[bk];
	bk = dest;
	while (prv[bk] != -1){
		int from = prv[bk], to = bk;
		capMax[from][to] -= bottleNeck , cp[from][to].pop();
		capMax[to][from] += bottleNeck, cp[to][from].push(-costMax[from][to]);
		minCost += bottleNeck * costMax[from][to];
		bk = prv[bk];
	}
	maxFlow += bottleNeck;
	return MP(maxFlow, minCost);
}
void build(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (capMax[i][j] != cpy[i][j])
				vs[i][j] += (cpy[i][j] == 0 ? 1 : -1);
		}
	}
	edgeList.clear();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (vs[i][j] > 0){
				costMax[i][j] = cp[i][j].top();
				capMax[i][j] = cpy[i][j] = 1;
				edgeList.push_back(edge(i, j, costMax[i][j]));
			}
			else capMax[i][j] = 0;
		}
	}
}
int main()
{
	Emsawy();
	int c = 0;
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		int u, v, w;
		for (int i = 0; i < m; i++){
			sf3(u, v, w);
			vs[u][v]++;
			cp[u][v].push(w);
		}
		build(); pair<ll, ll> a = MCMF(0, n - 1);
		build(); pair<ll, ll> b = MCMF(0, n - 1);
		if(a.first + b.first == 2) printf("Instance #%d:  %lld\n", ++c , a.second + b.second);
		else  printf("Instance #%d:  Not possible\n", ++c);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				while (!cp[i][j].empty()) cp[i][j].pop();
				vs[i][j] = cpy[i][j] = costMax[i][j] = capMax[i][j] = 0;
			}
		}
		ok = 0;
	}
	return 0;
}
