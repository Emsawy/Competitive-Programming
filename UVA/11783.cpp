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
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<pair<int, int> > > adj;
const ll mod = ll(1e9) + 7, oo = (ll) 1e9;
int n, m;
struct point{
	ll x, y;
};
ll side(point a ,point b, point c) {
	return ((a.y - b.y)*(c.x - b.x) - (a.x - b.x)*(c.y - b.y));
}

int main()
{
	Emsawy();
	while (cin >> n){
		if (n == 0) break;
		V<point>a(n), b(n);
		for (int i = 0; i < n; i++){
			cin>> a[i].x >> a[i].y;
			cin>> b[i].x >> b[i].y;
		}
		V<bool>vs(n);
		ll ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				ll a1 = side( a[j], a[i], b[i]);
				ll a2 = side( b[j], a[i], b[i]);
				ll a3 = side( a[i], a[j], b[j]);
				ll a4 = side( b[i], a[j], b[j]);
				if (a1 * a2 <= 0 && a3 * a4 <= 0) {
					ans++;
					vs[i] = vs[j] = 1;
				}
			}
			if (vs[i] == 0) ans+= 2;
		}
		cout << ans << endl;
	}
	return 0;
}
