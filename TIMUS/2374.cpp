#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>

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
const ll mod = ll(1e9 + 7), oo = 1e15;

V<V<pii> > adj;
int n, m, k, t, c;
ll a[50005],b[50005],dir[50005][2];
const int size = 200000;
ll seg[size * 4 * 10];

void shift(int p, int s, int  e){
	if (seg[p]){
		if (s != e){
			seg[p * 2] = seg[p];
			seg[p * 2 + 1] = seg[p];
			seg[p] = 0;
		}
	}
}
void upd(int p, int s, int e, int x, int y, int add){
	shift(p, s, e);
	if (s > e || x > e || s > y) return;
	if (x <= s && e <= y){
		seg[p] = add;
		shift(p, s, e);
		return;
	}
	int mid = (s + e) / 2;
	upd(p * 2, s, mid, x, y, add);
	upd(p * 2 + 1, mid + 1, e, x, y, add);
}
ll query(int p, int s, int e, int me){
	shift(p, s, e);
	if (s == e)
		return seg[p];
	int mid = (s + e) / 2;
	if (me <= mid)
		return query(p * 2, s, mid, me);
	return query(p * 2 + 1, mid + 1, e, me);
}
ll Abs(ll x){
	if (x < 0) x *= -1;
	return x;
}
int main()
{
	Emsawy();
	while (cin >> n >> k){
		int con = 100000;
		k += con;
		a[0] = b[0] = con;
		for (int i = 1; i <= n; i++){
			cin >> a[i] >> b[i];
			a[i] += con;
			b[i] += con;
		}

		for (int i = 1; i <= n ; i++){
			int f;
			
			f = query(1, 0, con * 2, a[i]);
			
			if (f == 0) dir[i][0] = Abs(a[i] - con);
			else dir[i][0] = min(Abs(a[i] - a[f]) + dir[f][0], Abs(a[i] - b[f]) + dir[f][1]);

			f = query(1, 0, con * 2, b[i]);

			if (f == 0) dir[i][1] = Abs(b[i] - con);
			else dir[i][1] = min(Abs(b[i] - a[f]) + dir[f][0], Abs(b[i] - b[f]) + dir[f][1]);

			upd(1, 0, con*2, a[i], b[i], i);
		}
		ll ans = min(dir[n][1] + Abs(k - b[n]), dir[n][0] + Abs(k - a[n]));
		cout << ans << endl;
	}
	return 0;
}
