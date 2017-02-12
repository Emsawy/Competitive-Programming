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
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9, bits = 22;
int n, m , t;
int g[(1 << 18)][bits];
bool lazy[(1 << 18)][bits];
bitset<bits> v[100005];
void build(int p, int l, int r, int k){
	if (l == r){
		g[p][k] = v[r][k];
		return;
	}
	build(p * 2, l, (l + r) / 2, k);
	build(p * 2 + 1, (l + r) / 2 + 1, r, k);
	g[p][k] = g[p * 2][k] + g[p * 2 + 1][k];
}
void spreed(int p, int k , int l , int r){
	if (lazy[p][k]){
		if (l != r){
			lazy[p * 2][k] ^= 1;
			lazy[p * 2 + 1][k] ^= 1;
		}
		lazy[p][k] = 0;
		g[p][k] = (r - l + 1) - g[p][k];
	}
}
void update(int p, int l, int r, int x, int y, int k){
	spreed(p, k , l , r);
	if (l > y || r < x)
		return;
	if (x <= l && r <= y){
		lazy[p][k] ^= 1;
		spreed(p, k, l, r);
		return;
	}
	update(p * 2, l, (l + r) / 2, x, y, k);
	update(p * 2 + 1, (l + r) / 2 + 1, r, x, y, k);
	g[p][k] = g[p * 2][k] + g[p * 2 + 1][k];
}
int get(int p, int l, int r, int x, int y, int k){
	spreed(p, k , l , r);
	if (l > y || r < x)
		return 0;
	if (x <= l && r <= y){
		return g[p][k];
	}
	int ret = 0;
	ret += get(p * 2, l, (l + r) / 2, x, y, k);
	ret += get(p * 2 + 1, (l + r) / 2 + 1, r, x, y, k);
	g[p][k] = g[p * 2][k] + g[p * 2 + 1][k];
	return ret;
}
int main()
{
	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++){
			sf(t);
			v[i] = t;
		}
		for (int i = 0; i < bits; i++)
			build(1, 0, n - 1, i);

		int x, y, me;
		cin >> m;
		while (m--){
			sf3(t, x, y);
			x--, y--;
			if (t == 1){
				ll ans = 0 , f = 1;
				for (int i = 0; i < bits; i++)
					ans += get(1, 0, n - 1, x, y, i) * f , f *= 2;
				printf("%I64d\n", ans);
			}
			else {
				sf(me);
				bitset<bits>bt(me);
				for (int i = 0; i < bits; i++)
					if (bt[i])
						update(1, 0, n - 1, x, y, i);
			}
		}
	}
	return 0;
}
