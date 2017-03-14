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
int const si = 10000;
inline int gInd(int x){
	return x % 2 ? x - 1 : x + 1;
}
struct  Edge
{
	int fr, to, cost, flow;
	Edge(){ fr = to = cost = flow = -1; };
	Edge(int a, int b, int c, int d): fr(a), to(b), cost(c), flow(d){}
};
struct MinCostMaxFlow{
	V<Edge>ed;
	int cost[si];
	int flow[si];
	int prv[si];
	MinCostMaxFlow(){
		clear();
	}
	void AddEdge(int fr, int to, int co, int fl){
		ed.push_back(Edge(fr, to, co, fl));
		ed.push_back(Edge(to, fr, -co, 0));
	}
	int getPath(int src,int sink){
		fill(cost, cost + (n+m+1)*2 + 10, oo); // (n+m+2) changable
		memset(prv, -1, sizeof(prv));
		memset(flow, 0, sizeof(flow));
		cost[src] = 0;
		flow[src] = oo;
		for (int i = 0; i < int(ed.size()); i++){
			bool ok = 0;
			for (int j = 0; j < ed.size(); j++){
				if (cost[ed[j].to] > cost[ed[j].fr] + ed[j].cost && ed[j].flow > 0){
					cost[ed[j].to] = cost[ed[j].fr] + ed[j].cost;
					flow[ed[j].to] = min(flow[ed[j].fr], ed[j].flow);
					prv[ed[j].to] = j;
					ok = 1;
				}
			}
			if (ok == 0) break;
		}
		return flow[sink];
	}
	pair<int, int> MCMF(int src ,int sink){
		if (src == sink) return MP(oo, 0);
		int totc = 0, totf = 0;
		while (true){
			int fl = getPath(src, sink);
			if (prv[sink] == -1) break;
			int cur = sink;
			while (prv[cur] != -1){
				ed[prv[cur]].flow -= fl;
				ed[gInd(prv[cur])].flow += fl;
				totc += fl * ed[prv[cur]].cost;
				cur = ed[prv[cur]].fr;
			}
			totf += fl;
		}
		return MP(totf, totc);
	}
	void clear(){
		ed.clear();
		memset(flow, 0, sizeof(flow));
		memset(cost, 0, sizeof(cost));
		memset(prv, -1, sizeof(prv));
	}
};
int pie[si], ice[si], inp[si][si];
MinCostMaxFlow g;
void process(int po){
	g.clear();
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (inp[i][j] < 0) continue;
			g.AddEdge(i * 2 + 1, (j + n) * 2 , inp[i][j] * po, oo);
		}
	}
	for (int i = 1; i <= n; i++){
		g.AddEdge(i * 2, i * 2 + 1, 0, pie[i]);
		g.AddEdge(1, i * 2 , 0, oo);
	}
	for (int i = 1; i <= m; i++){
		g.AddEdge((i + n) * 2, (i + n) * 2 + 1, 0, ice[i]);
		g.AddEdge((i + n) * 2 + 1, (n + m + 1) * 2, 0, oo);
	}
	pair<int, int> ret = g.MCMF(1, (n + m + 1) * 2);
	printf("%.2f",abs(ret.second) / 100.0);
}

int main()
{
	Emsawy();
	double in;
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) cin >> pie[i];
		for (int i = 1; i <= m; i++) cin >> ice[i];
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> in;
				inp[i][j] = in * 100;
			}
		}
		printf("Problem %d: ", ++c);
		process(1);
		printf(" to ");
		process(-1);
		puts("");
	}
	return 0;
}
