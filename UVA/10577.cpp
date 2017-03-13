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
#define rotate0(p,ang)		((p)*exp(point(0,ang)))
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

bool intersectionSegments(point a, point b, point c, point d, point &intersect){
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS) return 0;
	double t1 = d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a) * t1;
	if (t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
		return 0;
	return 1; // segment with segment
}
pair<double, point> findCircle(point a, point b, point c){
	point m1 = (b + a) * 0.5, v1 = b - a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b + c) * 0.5, v2 = b - c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1 + pv1, end2 = m2 + pv2, center;
	intersectionSegments(m1, end1, m2, end2, center);
	return make_pair(length(a - center), center);
}
int main()
{
	Emsawy();
	point p0, p1, p2; 
	double x[3], y[3];
	while (cin>>n){
		if (n == 0)break;
		cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
		p0 = point(x[0], y[0]), p1 = point(x[1], y[1]), p2 = point(x[2], y[2]);
		pair<double, point> ret = findCircle(p0, p1, p2);
		double minx = p0.X, maxx = p0.X;
		double miny = p0.Y, maxy = p0.Y;
		for (int i = 1; i <= n ; i++){
			point p = rotateA(p0, ((2 * PI) / n) * i, ret.second);
			minx = min(minx, p.X);
			maxx = max(maxx, p.X);
			miny = min(miny, p.Y);
			maxy = max(maxy, p.Y);
		}
		printf("Polygon %d: %0.3f\n",++c, (maxx - minx)*(maxy - miny));
	}
	return 0;
}
