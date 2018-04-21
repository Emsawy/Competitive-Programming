#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
const ll N = 50000 + 5;
int n, m, k, w, q;
const double eps = 1e-12, PI = acos(-1);
#define O            const point &
#define CD           const double &
#define EQ(a, b)     (fabs((a) - (b)) <= eps) /* equal to */
#define LT(a, b)     ((a) < (b)-eps) /* less than */
#define sz(v)	     ((int)((v).size()))

double INF = 1e100;
double EPS = 1e-12;

struct point {
	ll x, y;
};
point pt[N];
ll tot[N];
ll ems_abs(ll x) {
	if (x < 0) return -x;
	return x;
}
int main() {

	Emsawy();
	bool ok = 0;
	while (scanf("%d%d", &n, &q)) {
		if (n == 0 && q == 0) break;
		if (ok)puts("");
		ok = 1;
		for (int i = 0; i < n; i++) {
			scanf("%lld%lld", &pt[i].x, &pt[i].y);
		}
		pt[n] = pt[0];
		tot[0] = 0;
		for (int i = 0; i < n; i++) {
			tot[i + 1] = pt[i].x * pt[i + 1].y - pt[i].y * pt[i + 1].x;
			tot[i + 1] += tot[i];
		}
		ll a, b;
		for (int i = 0; i < q; i++) {
			scanf("%lld%lld", &a, &b);
			ll ans = ems_abs((tot[b] - tot[a]) + pt[b].x * pt[a].y - pt[b].y * pt[a].x);
			ans = min(ans, ems_abs(tot[n]) - ans);
			printf("%lld.%c\n", ans / 2, ans % 2 == 0 ? '0' : '5');
		}

	}
	return 0;
}
