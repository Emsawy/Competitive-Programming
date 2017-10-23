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

int g[151*2][151*2];
int main()
{
	Emsawy();
	bool ln = 0;
	while (cin >> n){
		if (ln) puts("");
		ln = 1;
		point center(n, n);
		double di = 2 * n - 1;
		n *= 2;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++){
				point p(i, j);
				double len = lengthSqr(vec(p, center));
				if (len * 2 * 2 > di * di) g[i][j] = 0;
				else g[i][j] = 1;
			}
		}
		int inside = 0, outside = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (g[i][j] && g[i][j + 1] && g[i + 1][j] && g[i + 1][j + 1]) inside++;
				else if (g[i][j] || g[i][j + 1] || g[i + 1][j] || g[i + 1][j + 1]) outside++;
			}
		}
		printf("In the case n = %d, %d cells contain segments of the circle.\nThere are %d cells completely contained in the circle.\n", n / 2, outside, inside);
	}
	return 0;
}
