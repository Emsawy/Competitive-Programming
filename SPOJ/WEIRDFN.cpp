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
ll n, m, k, t, c,a,b,g[200100];

int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> a >> b >> c >> n;
		
		priority_queue<ll> mx;
		priority_queue<ll , V<ll> , greater<ll> > mn;
		if (n == 1){
			cout << 1 << endl;
			continue;
		}
		mx.push(1);
		ll x = ((a * mx.top()) % mod + (b * 2LL) % mod + c) % mod;
		if (x == 0){
			mn.push(1);
			mx.pop();
			mx.push(0);
		}
		else
			mn.push(x);

		ll ans = 1 + x;
		for (int i = 3; i <= n; i++){
			ll x = ((a * mx.top()) % mod + (b * i) % mod + c) % mod;
			ans += x;
			if (x < mn.top())
				mx.push(x);
			else
				mn.push(x);

			if (mx.size() < mn.size())
				mx.push(mn.top()), mn.pop();

			if (mx.size() > mn.size() + 1)
				mn.push(mx.top()), mx.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
