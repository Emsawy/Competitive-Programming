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
int n, m, k, t, c;
bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS) return false; // Parllel || identical
	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a)*t1;
	if (t2 < -EPS || t2 > 1 + EPS)
		return false;
	return true;
}
double polygonArea(V<point> & points){
	double a = 0;
	for (int i = 0; i < points.size(); i++)
		a += cp(points[i], points[(i + 1) % sz(points)]);
	return fabs(a / 2.0);
}
int main()
{
	Emsawy();
	double x, y;
	int t;
	cin >> t;
	while (t--){
		cin >> x >> y; point a(x, y); 
		cin >> x >> y; point b(x, y); 
		cin >> x >> y; point c(x, y);

		point f = b + (a - b) * (2.0 / 3.0);
		point d = b + (c - b) * (1.0 / 3.0);
		point e = c + (a - c) * (1.0 / 3.0);

		point r, q, p;
		intersectSegments(f, c, a, d, r);
		intersectSegments(b, e, d, a, p);
		intersectSegments(c, f, e, b, q);

		V<point> rec;
		rec.push_back(r);
		rec.push_back(p);
		rec.push_back(q);

		cout <<(ll) round(polygonArea(rec)) << endl;


	}
	return 0;
}
