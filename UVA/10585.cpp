
/*
- First Get the center of points x and points y to get the center of all points, then find for each point if has
a mirror point using the center point.

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

int main()
{
	Emsawy();
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		map<ll, bool> ar;
		V<pair<ll, ll> > v(n);
		ll avx = 0, avy = 0 , ok = 1;
		for (int i = 0; i < n; i++){
			cin >> v[i].first >> v[i].second;
			avx += v[i].first;
			avy += v[i].second;
			ar[v[i].first + v[i].second] = 1;
		}
		if (avx % n || avy % n){
			puts("no");
			continue;
		}
		avx /= n, avy /= n;
		for (int i = 0; i < n; i++){
			ll cx = avx * 2 - v[i].first;
			ll cy = avy * 2 - v[i].second;
			if (ar[cx + cy] == false){
				puts("no");
				ok = 0;
				break;
			}
		}
		if (ok)
			cout << "yes" << endl;
	}
	return 0;
}
