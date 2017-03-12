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
#define DEBUG	system("Puase")
#define pii		pair<int,int>
#define V		vector
#define MP		make_pair
#define X		real()
#define Y		imag()
typedef complex<double> Point;
typedef long long ll;
typedef pair<pair<int, int>, pair<int, int> > tile;

const double PI = acos(-1.0);
const double EPS = acos(1e-10);
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k;

int main()
{
	Emsawy();
	int c = 1;
	int t;
	cin >> t;
	while (t--){
		if (c > 1)puts("");
		V<tile>v(9);
		for (int i = 0; i < 9; i++){
			cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
		}
		sort(all(v));
		tile g[3][3];
		bool ok = 0;
		do{
			int i = 0;
			while (i < 3) g[0][i] = v[i], i++;
			while (i < 6) g[1][i % 3] = v[i], i++;
			while (i < 9) g[2][i % 3] = v[i], i++;
			int ret = 1;
			if (g[0][0].first.second != g[0][1].second.second) ret = 0;
			if (g[0][1].first.second != g[0][2].second.second) ret = 0;

			if (g[1][0].first.second != g[1][1].second.second) ret = 0;
			if (g[1][1].first.second != g[1][2].second.second) ret = 0;

			if (g[2][0].first.second != g[2][1].second.second) ret = 0;
			if (g[2][1].first.second != g[2][2].second.second) ret = 0;

			if (g[1][0].first.first != g[0][0].second.first) ret = 0;
			if (g[1][1].first.first != g[0][1].second.first) ret = 0;
			if (g[1][2].first.first != g[0][2].second.first) ret = 0;

			if (g[1][0].second.first != g[2][0].first.first) ret = 0;
			if (g[1][1].second.first != g[2][1].first.first) ret = 0;
			if (g[1][2].second.first != g[2][2].first.first) ret = 0;

			if (ret == 1){
				ok = 1;
				break;
			}
		} while (next_permutation(all(v)));
		if (ok)printf("Case %d: YES\n", c++);
		else printf("Case %d: NO\n", c++);
	}
	return 0;
}
