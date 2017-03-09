
/*
- The answer of the problem is the Aritulation point of the graph.
- you can see this vedio to be aware with it.
- https://www.youtube.com/watch?v=MNTcgXTPoVQ&index=15&list=PLPt2dINI2MIb4OXlJ_EEwIDV9WVUpRQ5K
*/

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
#define sfll3(x,y,z)	scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define rotate0(p,ang)	((p)*exp(Point(0,ang)))
#define rotateA(p,ang,A)(rotate0(vec(A,p),ang)+A)
#define reflect0(v,m)	(conj((v)/(m))*(m))
#define pii				pair<int,int>
#define V				vector
#define MP				make_pair
#define X				real()
#define Y				imag()
typedef complex<double> Point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = acos(1e-10);
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<int> > adj;
int n, m, k;
const int si = 10005;
set<int>nodes;
bool root = 0;
int dfn[si], low[si], depth = 0;
void SCCF(int nd, int par = -1){
	dfn[nd] = low[nd] = depth++;
	for (int i = 0; i < adj[nd].size(); i++){
		int ch = adj[nd][i];
		if (dfn[ch] == -1){
			SCCF(ch, nd);
			low[nd] = min(low[nd], low[ch]);
			if (low[ch] >= dfn[nd]){
				if (dfn[nd] == 0 && root == 0) root = 1;         // root is (0)
				else nodes.insert(nd);
			}
		}
		else if (ch != par){
			low[nd] = min(low[nd], dfn[ch]);
		}
	}
}
void ArticulationPoint(){
	nodes.clear();
	depth = root = 0;
	clr(dfn, -1);
	SCCF(0, -1); // for connected graph
}
int main()
{
	Emsawy();
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		adj.clear();
		adj.resize(n);
		for (int i = 0; i < m; i++){
			int u, v;
			sf2(u, v);
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ArticulationPoint();
		cout << nodes.size() << endl;

	}
	return 0;
}
