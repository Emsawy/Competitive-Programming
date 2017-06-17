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
double get(point a, point b){
	return lengthSqr(b - a);
}
int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> n >> m;
		V < point > p;
		double x, y;
		for (int i = 0; i < n; i++){
			cin >> x >> y;
			p.push_back(point(x, y));
		}
		long double tree = 0;
		for (int i = 1; i < n; i++){
			tree += sqrt(lengthSqr(p[i] - p[i - 1]));
		}
		tree /= double(m - 1);
		V<point>ans;
		double dis = 0;
		for (int i = 1; i < n; i++){

			long double line = sqrt(lengthSqr(p[i] - p[i - 1]));
			while (dis - line < -EPS){
				double e = dis / line;
				point cur = p[i-1] + vec(p[i-1],p[i]) * e;
				ans.push_back(cur);
				dis += tree;
			}
			dis -= line;
		}
		cout << "Road #" << ++c << ":\n";
		ans.push_back(p[n - 1]);
		for (int i = 0; i < ans.size(); i++)
			cout << fixed << setprecision(2) << ans[i].X << " " << ans[i].Y << endl;
		puts("");
	}
	return 0;
}
