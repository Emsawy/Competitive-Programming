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

#define sz(v)		((int)((v).size()))
#define all(v)		((v).begin()), ((v).end())
#define allr(v)		((v).rbegin()), ((v).rend())
#define clr(v,d)	memset(v, d, sizeof(v))
#define sf(x)		scanf("%d", &x)
#define sf2(x,y)	scanf("%d %d", &x, &y)
#define sf3(x,y,z)	scanf("%d %d %d", &x, &y, &z)
#define sfll(x)		scanf("%I64d", &x)
#define sfll2(x,y)	scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)	scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)	(atan2((a).imag(), (a).real()))
#define vec(a,b)	((b)-(a))
#define length(a)	(hypot((a).imag(), (a).real()))
#define dp(a,b)		((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)		((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)	(dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define rotate0(p,ang)	((p)*exp(Point(0,ang)))
#define rotateA(p,ang,A)(rotate0(vec(A,p),ang)+A)
#define reflect0(v,m)	(conj((v)/(m))*(m))
#define pii		pair<int,int>
#define V		vector
#define MP		make_pair
#define X		real()
#define Y		imag()
typedef complex<double> Point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = acos(1e-10);
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k, src, dst, dist, vs[200], cur = 0;
V<pair<int, V<int> > > routs;
V<int>put;
void dfs(int nd, int sum){
	if (sum < 0 || vs[nd] == cur) return;
	if (nd == dst){
		routs.push_back(MP(dist - sum, put));
		routs.back().second.push_back(dst);
		return;
	}
	vs[nd] = cur;
	put.push_back(nd);
	for (int i = 0; i < adj[nd].size(); i++){
		pair<int, int> ch = adj[nd][i];
		dfs(ch.first, sum - ch.second);
	}
	vs[nd] = 0;
	put.pop_back();
}
int main()
{
	Emsawy();
	int cs = 1;
	while (sf(n)){
		if (n == -1) break;
		if (cs > 1)puts("");
		sf(m);
		put.clear();
		routs.clear();
		adj.clear();
		adj.resize(n + 1);
		int u, v, w;
		for (int i = 0; i < m; i++){
			sf3(u, v, w);
			adj[u].push_back(MP(v, w));
			adj[v].push_back(MP(u, w));
		}
		sf2(src, dst);
		sf(dist);
		cur++;
		dfs(src, dist);
		sort(all(routs));
		if (routs.size() == 0){
			printf("Case %d: NO ACCEPTABLE TOURS\n", cs++);
			continue;
		}
		printf("Case %d:\n", cs++);
		for (int i = 0; i < routs.size(); i++){
			printf("%d:", routs[i].first);
			for (int j = 0; j < routs[i].second.size(); j++){
				printf(" %d", routs[i].second[j]);
			}
			puts("");
		}
	}
	return 0;
}
