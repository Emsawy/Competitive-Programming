#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define sz(v)			((int)((v).size()))
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define clr(v,d)		memset(v, d, sizeof(v))
#define sf(x)			scanf("%d", &x)
#define sf2(x,y)		scanf("%d %d", &x, &y)
#define sf3(x,y,z)		scanf("%d %d %d", &x, &y, &z)
#define sfll(x)			scanf("%I64d", &x)
#define sfll2(x,y)		scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)		scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) <= EPS)
#define rotate0(p,ang)		((p)*exp(Point(0,ang)))
#define rotateA(p,ang,about)	(rotate0(vec(about,p),ang)+about)
#define reflect0(v,m)		(conj((v)/(m))*(m))
#define normalize(a)		(a)/length(a)
#define lengthSqr(p)		dp(p,p)
#define pii			pair<int,int>
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()

typedef complex<double> 	point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k, t, c;
struct edge {
	int from, to, w;
	edge(int from, int to, int w) : from(from), to(to), w(w) {}
	bool operator < (const edge & e) const {
		w > e.w;
	}
};
// O(NM)
const int si = 1005;
bool reachCycle[si];
int prv[si], pos[si], dist[si][2], cost[si][si], cap[si][si], minCost, maxFlow;
bool BMF(int n, bool po , V<edge> & edges){
	if (sz(edges) == 0) return 0;
	for (int i = 0, r = 0; i < n + 1; i++, r = 0){
		for (int j = 0; j < sz(edges); j++){
			edge ne = edges[j];
			if (dist[ne.from][po] >= oo || ne.w == oo) continue;
			if (dist[ne.to][po] > dist[ne.from][po] + ne.w){
				dist[ne.to][po] = dist[ne.from][po] + ne.w;
				prv[ne.to] = ne.from, pos[ne.to] = j, r++;
				if (i == n) return 1;
			}
		}
		if (!r) break;
	}
	return 0;
}
pair<int, bool> build(int n, int src, int dest , V<edge> & edges){
	for (int i = 0; i < si; i++)
		dist[i][0] = dist[i][1] = oo, prv[i] = -1, pos[i] = 0;
	
	dist[src][0] = 0;
	bool cycle = BMF(n, 0, edges);
	if (cycle) {
		BMF(n, 1, edges);
		for (int i = 1; i <= n; ++i)	// find all nodes that AFFECTED by negative cycle
			reachCycle[i] = (dist[i][0] != dist[i][1]);
	}
	return MP(dist[dest][0], cycle);
}
void mcmf(int src, int dest ){
	clr(prv, -1); minCost = 0;
	clr(dist, 0); maxFlow = 0;
	while (true){
		V<edge>edges;
		for (int i = 1; i <= (n+m+1)*2; i++)
			for (int j = 1; j <= (m+n+1)*2; j++)
				if (cap[i][j] > 0)
					edges.push_back(edge(i, j, cost[i][j]));

		pair<int, bool> ret = build(edges.size(), src, dest, edges);
		if (dist[dest][0] >= oo) break;
		int bottleNeck = oo;
		for (int i = dest; prv[i] > -1; i = prv[i]){
			int l = prv[i], r = i;
			bottleNeck = min(bottleNeck, cap[l][r]);
		}
		for (int i = dest; prv[i] > -1; i = prv[i]){
			int l = prv[i], r = i;
			minCost += bottleNeck * cost[l][r];
			cap[l][r] -= bottleNeck, cap[r][l] += bottleNeck;
		}
		maxFlow += bottleNeck;
	}
	clr(cost, 0);
	clr(cap, 0);
}
void repeat(V<V<double> >&inp,V<int>&pie , V<int>&ice , bool pr = 1){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (inp[i][j] < 0) continue;
			cap[i * 2 + 1][(j + n) * 2] = oo;
			cost[i * 2 + 1][(j + n) * 2] = (pr ? 1 : -1) * inp[i][j];
			cost[(j + n) * 2][i * 2 + 1] = (!pr ? 1 : -1) * inp[i][j];
		}
	}
	for (int i = 1; i <= n; i++){
		cap[i * 2][i * 2 + 1] = pie[i];
		cost[i * 2][i * 2 + 1] = 0;
		cap[1][i * 2] = oo;
		cost[1][i * 2] = 0;
	}

	for (int i = 1; i <= m; i++){
		cap[(i + n) * 2][(i + n) * 2 + 1] = ice[i];
		cost[(i + n) * 2][(i + n) * 2 + 1] = 0;
		cap[(i + n) * 2 + 1][(n + m + 1) * 2] = ice[i];
		cost[(i + n) * 2 + 1][(n + m + 1) * 2] = 0;
	}
}
int main()
{
	Emsawy();
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		V<int>pie(n+1) , ice(m+1);
		for (int i = 1; i <= n; i++) cin >> pie[i];
		for (int i = 1; i <= m; i++) cin >> ice[i];

		V<edge>ed;
		V<V<double> > inp(n + 1, V<double>(m + 1));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> inp[i][j];
				inp[i][j] *= 100;
			}
		}
		repeat(inp, pie, ice,1);
		mcmf(1, (n + m + 1) * 2);
		int a = abs(minCost);
		repeat(inp, pie, ice,0);
		mcmf(1, (n + m + 1) * 2);
		int b = abs(minCost);
		printf("Problem %d: %.2f to %.2f\n", ++c, a / 100.0, b / 100.0);
	}
	return 0;
}
