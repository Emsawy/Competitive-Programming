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
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
int n, m, x[1003], y[1003], z[1003], ds[1003];

pair<int,int> intersection(pair<int,int> a, pair<int,int>b){
	if (a.first >= b.first) swap(a, b);
	if (a.second >= b.second) return b;
	return MP(b.first, a.second);
}
ll dis(pair<int, int>b){
	return b.second - b.first;
}
int main()
{
	Emsawy();
	while (cin >> n){
		if (n == 0) break;
		ll ans = 0;
		for (int i = 0; i < n; i++){
			sf2(x[i], y[i]);
			sf2(z[i], ds[i]);
		}
		pair<int, int>X(-oo,oo);
		for (int i = 0; i < n; i++){
			X = intersection(X, MP(x[i], x[i] + ds[i]));
			if (X.first > X.second) break;
		}
		pair<int, int>Y(-oo, oo);
		for (int i = 0; i < n; i++){
			Y = intersection(Y, MP(y[i], y[i] + ds[i]));
			if (Y.first > Y.second) break;
		}
		pair<int, int>Z(-oo, oo);
		for (int i = 0; i < n; i++){
			Z = intersection(Z, MP(z[i], z[i] + ds[i]));
			if (Z.first > Z.second) break;
		}
		if (X.first >= X.second || Y.first >= Y.second || Z.first >= Z.second) puts("0");
		else printf("%lld\n", dis(X)*dis(Y)*dis(Z));
	}
	return 0;
}
