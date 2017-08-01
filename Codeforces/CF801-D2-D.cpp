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
const double EPS = 1e-9;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m , k , t;
double distToSegment(point p0, point p1, point p2){
	double d1, d2; // (w*cos(0)/vl) == (w*vl*cos(0)/vl*vl) == (w.vl / vl*vl) 
	point v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dp(v1, v2)) < 0) return length(p2 - p0);
	if ((d2 = dp(v1, v1)) <= d1) return length(p2 - p1);
	double t = d1 / d2;
	return length(p2 - (p0 + v1 * t));
}
double dis(point a, point b){
	return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}
int main()
{
	Emsawy();
	while (cin >> n){
		int x, y;
		V<point> v(n);
		for (int i = 0; i < n; i++){
			cin >> x >> y;
			v[i] = point(x, y);
		}
		int lp = 1000;
		double s = 0, e = 1e12, res = 0.0;
		while (lp--){
			double md = (s + e) / 2.0;

			bool ok = 1;
			for (int i = 0; i < n; i++){
				int l = (i - 1 + n) % n, r = (i + 1) % n;
				if (distToSegment(v[l], v[r], v[i]) - md * 2 < EPS) {
					ok = 0;
					break;
				}
				if (dis(v[i], v[l]) - md * 2 < EPS || dis(v[i], v[r]) - md * 2 < EPS){
					ok = 0;
					break;
				}
			}

			if (ok) s = md, res = md;
			else e = md;
			lp--;
		}
		res += EPS;
		printf("%0.9f\n", res);
	}
	return 0;
}
