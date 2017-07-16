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

int sta[1 << 20][20], stb[1 << 20][20];
int lg2[1 << 20];

void build() {
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			sta[i][j] = max(sta[i][j - 1], sta[i + (1 << (j - 1))][j - 1]);
			stb[i][j] = min(stb[i][j - 1], stb[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 2; i <= n; i++)
		lg2[i] = lg2[i >> 1] + 1;
}

int Max(int l, int r) {
	int lg = lg2[r - l + 1];
	return max(sta[l][lg], sta[r - (1 << lg) + 1][lg]);
}

int Min(int l, int r) {
	int lg = lg2[r - l + 1];
	return min(stb[l][lg], stb[r - (1 << lg) + 1][lg]);
}
int Lower_bound(int st, int end){
	int s = st, e = end - 1;
	while (s <= e){
		int mid = (s + e) / 2;
		if (Min(st, mid) > Max(st, mid)) s = mid + 1;
		else e = mid - 1;
	}
	return s;
}

int Upper_bound(int st, int end){
	int s = st, e = end - 1;
	while (s <= e){
		int mid = (s + e) / 2;
		if (Min(st, mid) >= Max(st, mid)) s = mid + 1;
		else e = mid - 1;
	}
	return s;
}
int main()
{
	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++) cin >> sta[i][0];
		for (int i = 0; i < n; i++) cin >> stb[i][0];
		build();

		ll ans = 0;
		for (int i = 0; i < n; i++){
			ll low = Lower_bound(i, n);
			ll up = Upper_bound(i, n);
			ans += (up - low);
		}
		cout << ans << endl;
	}
	return 0;
}
