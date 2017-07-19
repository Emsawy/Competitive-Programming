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
int n, m, k, t;
ll side(ll x){
	x = 2 * (x - 1) + 1;
	return (x * (x+1) / 2) - (x / 2)*(x / 2 + 1);
}
ll unit(ll x){
	return x * x + (x - 1) * (x - 1);
}
ll suf(ll x){
	return x*(x + 1) / 2;
}
ll x, y, c;

ll valid(ll mid){
	ll ret = unit(mid);
	int up = x, dw = n - x + 1;
	int lf = y, ri = n - y + 1;
	if (up < mid) ret -= side(mid - up );
	if (dw < mid) ret -= side(mid - dw );
	if (lf < mid) ret -= side(mid - lf );
	if (ri < mid) ret -= side(mid - ri );
	if (lf + up < mid) ret += suf(mid - lf - up);
	if (lf + dw < mid) ret += suf(mid - lf - dw);
	if (ri + up < mid) ret += suf(mid - ri - up);
	if (ri + dw < mid) ret += suf(mid - ri - dw);
	return ret;
}

int main()
{
	Emsawy();
	while (cin >> n >> x >> y >> c){
		valid(3);
		ll s = 1, e = 1e9, res;
		while (s <= e){
			ll mid = (s + e) / 2;
			if (valid(mid) >= c) e = mid - 1, res = mid;
			else s = mid + 1;
		}
		cout << res - 1 << endl;
	}
	return 0;
}
