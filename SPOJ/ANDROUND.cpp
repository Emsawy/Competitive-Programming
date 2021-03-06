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

const int size = 1000006;
int seg[size * 4];
int g[size];

ll query(int p, int s, int e, int x, int y){
	if (s > y || e < x)
		return -1;         // take care
	if (x <= s && e <= y)
		return seg[p];

	return query(p * 2, s, (s + e) / 2, x, y) & query(p * 2 + 1, (s + e) / 2 + 1, e, x, y);
}


void build(int p, int s, int e){
	if (s == e){
		seg[p] = g[s];
		return;
	}
	build(p * 2, s, (s + e) / 2);
	build(p * 2 + 1, (s + e) / 2 + 1, e);
	seg[p] = seg[p * 2] & seg[p * 2 + 1];
}
int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> g[i];

		build(1, 0, n - 1);
		
		k = min(k, n - 1);
		for (int i = 0; i < n; i++){
			int s = (i - k + n) % n , e = (i + k) % n;
			int res = -1;
			if (s < i) res &= query(1, 0, n - 1, s, i);
			else res &= query(1, 0, n - 1, 0, i) &  query(1, 0, n - 1, s, n - 1);

			if (e <= i) res &= query(1, 0, n - 1, i, n - 1) &query(1, 0, n - 1, 0, e);
			else  res &= query(1, 0, n - 1, i, e);

			printf("%d ", res);
		}
		puts("");

	}
	return 0;
}
