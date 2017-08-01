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
int n, m, k, t, c,w,b;

int main()
{
	Emsawy();
	while (cin >> b >> w >> c){
		double unit = (w * b * 1.0) / c;
		V<int>cnt(b);
		V<double> bt(b, w), cu(c,unit);
		V<string > ans(c);
		bool ok = 0;
		for (int i = 0; i < c; i++){
			if (bt.empty()){
				ok = 1;
				break;
			}
			if (bt.back() - cu[i] >= EPS){
				bt.back() -= cu[i];
				char a[1000];
				sprintf(a, "%d %0.6f ", sz(bt), cu[i]);
				ans[i] += a;
				cu[i] = 0;
				if (bt.back() - unit > EPS){
					ok = 1;
					break;
				}
				if (bt.back() <= EPS) bt.pop_back();
			}
			else {
				char a[1000];
				sprintf(a, "%d %0.6f ", sz(bt), bt.back());
				ans[i] += a;
				cu[i] -= bt.back();
				bt.pop_back();
				if (cu[i] > EPS) i--;
			}
		}
		if (ok) puts("NO");
		else{
			puts("YES");
			for (int i = 0; i < c; i++)
				cout << ans[i] << endl;
		}
	}
	return 0;
}
