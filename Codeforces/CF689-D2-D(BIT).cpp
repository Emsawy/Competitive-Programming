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

int lg2[1 << 20];

int B1[1 << 20];
void upd1(int idx, int vl){
	for (int id = idx; id <= n; id += (id & -id)){
		B1[id] = min(B1[id], vl);
	}
}

int mn(int idx){
	int ret = oo;
	for (int id = idx; id > 0; id -= (id & -id)){
		ret = min(ret, B1[id]);
	}
	return ret;
}
int B0[1 << 20];
void upd0(int idx, int vl){
	for (int id = idx; id <= n; id += (id & -id)){
		B0[id] = max(B0[id], vl);
	}
}

int mx(int idx){
	int ret = -oo;
	for (int id = idx; id > 0; id -= (id & -id)){
		ret = max(ret, B0[id]);
	}
	return ret;
}

int main()
{
	Emsawy();
	while (cin >> n){
		V<int>a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i], B0[i] = -oo;
		for (int i = 1; i <= n; i++) cin >> b[i], B1[i] = oo;
		for (int i = 2; i <= n + 100; i++) lg2[i] += lg2[i >> 1] + 1;
		ll ans = 0;
		for (int i = n; i > 0; i--){
			upd0(i, a[i]);
			upd1(i, b[i]);
			if (mx(i) <= mn(i)){
				int l = i - 1, r = i;
				for (int j = 1 << lg2[n - i + 1]; j > 0; j >>= 1){
					if (l + j <= n && mx(l + j) < mn(l + j)) l += j;
					if (r + j <= n && mx(r + j) <= mn(r + j)) r += j;
				}
				ans += r - l;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
