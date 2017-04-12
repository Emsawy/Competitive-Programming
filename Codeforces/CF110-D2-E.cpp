
/*
- I have the answer (n*(n-1)*(n-2)) if all pathes is lucky.
- substract from the answer unvalid choices.
- unvalid answer ->  for each connected graph with x nodes , unvalid answer (x*(x-1)*(x-2)) + (x*(x-1))*(n-x)*2 

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
const ll mod = ll(1e9 + 7), oo = ll(1e9), si = 1000000;

V<V<pii> > adj;
int n, m, k, t, c, u, v;
bool lucky(int x){
	while (x){
		int dig = x % 10;
		if (dig != 4 && dig != 7)
			return 0;
		x /= 10;
	}
	return 1;
}
bool vs[100005];
int go(int nd){
	int ret = 1;
	for (int i = 0; i < adj[nd].size(); i++){
		if (vs[adj[nd][i].first] || lucky(adj[nd][i].second)) continue;
		vs[adj[nd][i].first] = 1;
		ret += go(adj[nd][i].first);
	}
	return ret;
}
int main()
{
	Emsawy();
	
	while (cin >> n){
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < n - 1; i++){
			sf2(u, v);
			sf(k);
			adj[u].push_back(MP(v,k));
			adj[v].push_back(MP(u,k));
		}
		ll ans = 1LL * n * (n - 1) * (n - 2);
		for (int i = 1; i <= n; i++){
			if (vs[i]) continue;
			vs[i] = 1;
			int ret = go(i);
			ans -= ((1LL * ret * (ret - 1) * (ret - 2)) + (2LL * ret * (ret - 1) * (n - ret)));
		}
		cout << ans << endl;
		clr(vs, 0);
	}
	return 0;
}
