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
ll n, m, k, t, c;
ll v[100005];
ll valid(ll mid){
	ll ret = 0;
	for (int i = 0; i < n; i++){
		ll ser = (i? v[i - 1]:0) + mid;
		ll len = lower_bound((v+i), v + n, ser) - (v + i);
		ret += len;
	}
	return (n*(n+1))/2 - ret;
}
int main()
{
	Emsawy();
	while (cin >> n >> k){
		for (int i = 0; i < n; i++)
			cin >> v[i];
	
		for (int i = 0; i < n; i++)
			if (i) v[i] += v[i - 1];
		//cout << valid(6) << endl;
		//k = (n * (n + 1)) / 2 - k + 1;
		ll s = 0, e = 1e15, res = 0;
		while (s <= e){
			ll mid = (s + e) / 2LL;
			if (valid(mid) >= k) s = mid + 1, res = mid;
			else e = mid - 1;
		}
		V<ll>ans;
		for (int i = 0; i < n; i++){
			ll ser = (i ? v[i - 1] : 0) + res;
			ll len = upper_bound((v + i), v + n, ser) - v;
			for (int j = len; j < n; j++)
				ans.push_back(v[j] - (i ? v[i - 1] : 0));
		}
		while (ans.size() < k)
			ans.push_back(res);
		sort(allr(ans));
		for (auto it : ans)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}
