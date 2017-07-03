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
#define pi			int
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()

typedef complex<double> 	point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pi> > adj;
int n, m, k, t, c;
set<int> g[1024 * 4 + 1];
string v[1025];

int go(int nd, int l, int r, int bit){
	g[nd].clear();
	if (l == r){
		g[nd].insert(v[l][bit]);
		return 0;
	}
	int x = go(nd * 2, l, (l + r) / 2, bit);
	int y = go(nd * 2 + 1, (l + r) / 2 + 1, r, bit);


	for (auto it : g[nd * 2 + 1]){
		if (g[nd * 2].find(it) != g[nd * 2].end()){
			g[nd].insert(it);
		}
	}
	if (g[nd].size() > 0)
		return x + y;

	g[nd].insert(all(g[nd * 2]));
	g[nd].insert(all(g[nd * 2 + 1]));
	
	return x + y + 1;
}

int main()
{
	Emsawy();
	while (cin >> n >> m){
		if (n + m == 0) break;
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		string res = "";
		ll ans = 0;
		for (int i = 0; i < m; i++){
			ans += go(1, 0, n - 1, i);
			res += *g[1].begin();
		}
		cout <<res <<" "<< ans << endl;
	}
	return 0;
}
