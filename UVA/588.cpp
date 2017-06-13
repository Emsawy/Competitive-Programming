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

pair< V <point>, V < point> > polygonCut(V<point> & p, point A, point B){
	V<point> left, right;
	for (int i = 0; i < p.size(); i++){
		point cur = p[i], nxt = p[(i + 1) % sz(p)];
		if (cp(B - A, cur - A) >= 0) 
			right.push_back(cur);

		point p;
		if (intersectSegments(A, B, cur, nxt, p)){
			right.push_back(p);
			left.push_back(p);
		}

		if (cp(B - A, cur - A) <= 0)
			left.push_back(cur);
	}
	return MP(left, right);
}

int main()
{
	Emsawy();
	while (cin >> n){
		if (!n) break;
		V<point>p;
		int x, y;
		for (int i = 0; i < n; i++){
			cin >> x >> y;
			p.push_back(point(x, y));
		}
		V<point> pt = p;
		for (int i = 0; i < n; i++){
			p = polygonCut(p, pt[i], pt[(i + 1) % n]).first;
		}
		cout << "Floor #" << ++t << "\n";
		if (p.size() == 0)
			cout << "Surveillance is impossible.\n";
		else
			cout << "Surveillance is possible.\n";

		cout << "\n";
	}
	return 0;
}
