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

const int ND = 100000, ED = 100000;
int to[ED], cost[ED], cap[ED], last[ND], nxt[ED], prv[ND], pot[ED], dist[ND], E = 0, N = 0, minCost = 0, maxFlow = 0;
void init(int Nodes){
	for (int i = 0; i < ND; i++)
		last[i] = -1, pot[i] = cost[i] = nxt[i] = cap[i] = cost[i] = to[i] = pot[i] = to[i] =0;  // clr
	maxFlow = minCost = E = 0;
	N = Nodes;
}
void addEdge(int u, int v, int cp, int w){
	to[E] = v, cap[E] = cp, cost[E] = w, nxt[E] = last[u], last[u] = E++;
	to[E] = u, cap[E] = 0, cost[E] = -w, nxt[E] = last[v], last[v] = E++;
}

int MCMF0(int src, int dest){
	while (true){
		for (int i = 0; i < ND; i++) prv[i] = -1; // clr
		for (int i = 0; i <= N; i++) dist[i] = -oo;
		dist[src] = prv[src] = 0;
		priority_queue<pair<int, int> > pq;
		pq.push(MP(0, src));
		while (!pq.empty()){
			pair<int, int> p = pq.top();
			pq.pop();
			for (int e = last[p.second]; e != -1; e = nxt[e]){
				int now = dist[p.second] + cost[e] + pot[p.second] - pot[to[e]];
				if (dist[to[e]] >= now || cap[e] <= 0) continue;
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
		for (int i = 1; i <= N; ++i) if (prv[i] != -1) pot[i] += dist[i];
	}
	return minCost;
}

int MCMF1(int src, int dest){
	while (true){
		for (int i = 0; i < ND; i++) prv[i] = -1; // clr
		for (int i = 0; i <= N; i++) dist[i] = oo;
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
		for (int i = 1; i <= N; ++i) if (prv[i] != -1) pot[i] += dist[i];
	}
	return minCost;
}
void inputs(V<int>&pie, V<int>&ice, V<V<int> >&inp){
	init((n + m + 1) * 2);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (inp[i][j] < 0) continue;
			addEdge(i * 2 + 1, (j + n) * 2, oo, inp[i][j]);
		}
	}
	for (int i = 1; i <= n; i++){
		addEdge(i * 2, i * 2 + 1, pie[i], 0);
		addEdge(1, i * 2, oo, 0);
	}
	for (int i = 1; i <= m; i++){
		addEdge((i + n) * 2, (i + n) * 2 + 1, ice[i], 0);
		addEdge((i + n) * 2 + 1, (n + m + 1) * 2, oo, 0);
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
		double in;
		V<V<int> > inp(n + 1, V<int>(m + 1));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin>> in;
				inp[i][j] = in * 100;
			}
		}

		inputs(pie, ice, inp);
		int mn = MCMF1(1, (n + m + 1) * 2);

		inputs(pie, ice, inp);
		int mx = MCMF0(1, (n + m + 1) * 2); 

		printf("Problem %d: %.2f to %.2f\n", ++c, mn / 100.0, mx / 100.0);

	}
	return 0;
}
