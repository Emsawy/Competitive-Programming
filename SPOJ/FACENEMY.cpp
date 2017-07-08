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


typedef complex<long double> 	point;
typedef long long ll;

const long double PI = acos(-1.0);
const long double EPS = 1e-15;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k, t, c;

long double dis(point a, point b){
	return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

int main()
{
	Emsawy();
	point a, b, c, d;
	long double x, y;
	cin >> t;
	while (t--){
		cin >> x >> y; a = point(x, y);
		cin >> x >> y; b = point(x, y);
		cin >> x >> y; c = point(x, y);
		cin >> x >> y; d = point(x, y);

		long double l = dis(b, a), r = dis(c, a);
		long double A = acos(dp(a - b, a - c) / (l * r));
		while (A >= 2 * PI) A -= 2 * PI;
		while (A < 0) A += 2 * PI;

		l = dis(d, c), r = dis(a, c);
		long double B = acos(dp(c - d, c - a) / (l * r));

		while (B >= 2 * PI) B -= 2 * PI;
		while (B < 0) B += 2 * PI;

		A = fminl(A, 2*PI - A);
		B = fminl(B, 2*PI - B);

		if (fabs(A - B) <= EPS) cout << 0 << endl;
		else if (A < B) cout << "Hero" << endl;
		else cout << "Heroine" << endl;
	}
	return 0;
}
