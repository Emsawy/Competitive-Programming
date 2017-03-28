
/*
- I get the sum of all number and the answer of the problem is the minimum divisor for the sum which is a valid.
- valid mean that the cycle with length (divisor) has points
*/

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
const int MAXP = 10000007;
int Pr[MAXP];
bool g[MAXP];
void sieve(){
	Pr[0] = Pr[1] = 1;
	for (ll i = 2; i < MAXP; i++){
		if (Pr[i]) continue;
		Pr[i] = i;
		for (ll j = i * i; j < MAXP; j += i){
			Pr[j] = i;
		}
	}
}

V<int> primeFactor(int x){
	V<int>ret;
	while (x > 1){
		ret.push_back(Pr[x]);
		x = x / Pr[x];
	}
	return ret;
}
int main()
{
	Emsawy();
	sieve();

	while (cin >> n){
		if (n == 0) break;
		V<int>v(n);
		int sum = 0;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			if (i) v[i] += v[i - 1];
			g[v[i] - 1] = 1;
		}
		sum = v[n - 1];
		V<int> p = primeFactor(sum);
		int ans = 0 , lop = 1 << p.size();
		for (int q = 0;q<lop;q++){
			int it = 1;
			for (int e = 0; e < p.size(); e++){
				if (((q >> e) & 1))
					it *= p[e];
			}
			for (int i = 0; i < it ; i++){
				int f = i, loop = sum / it , now = 1;
				while (loop--){
					f = f % sum;
					if (!g[f]){
						now = 0;
						break;
					}
					f += it;
				}
				if (now) ans = max(ans, sum / it);
			}
		}
		if (ans <= 2) cout << -1 << endl;
		else cout << n - ans << endl;
		clr(g, 0);
	}
	return 0;
}
