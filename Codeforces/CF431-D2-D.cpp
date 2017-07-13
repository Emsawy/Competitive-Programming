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
typedef unsigned long long ull;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int k, t, c;
ll n , m;

ll dp[70][70];

ll go(int nd, int cnt){
	if (cnt < 0) return 0;
	if (nd == 0) return cnt == 0;
	ll &ret = dp[nd][cnt];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(nd - 1, cnt - 1);
	ret += go(nd - 1, cnt);
	return ret;
}
ll valid(ll mid){
	int K = k;
	ll res = 0;
	for (int i = 63; i >= 0; i--){
		if (((mid >> i) & 1) == 0) continue;
		res += go(i,K);
		K--;
	}
	if (K == 0) res++;
	return res;
}
int main()
{
	Emsawy();
	while (cin >> m >> k){
		clr(dp, -1);

		ll lo = 1, hi = 1e18, res;
		while (lo <= hi){
			ll mid = (lo + hi) / 2;
			if (valid(mid * 2) >= m + valid(mid))
				hi = mid - 1, res = mid;
			else 
				lo = mid + 1;
		}
		cout << res << endl;
	}
	return 0;
}
