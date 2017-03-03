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

#define sz(v) ((int)((v).size()))
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
const ll mod = (ll) 1e6 + 7, oo = (ll) 1e9;
int n, m, k, N;
ll dp[600][600];
int g[100];
ll go(int id, int k){
	if (k == 0) return 1;
	if (id == 0) return 0;
	ll &ret = dp[id][k];
	if (ret != -1) return ret;
	ret = 0;
	ret = (ret + go(id - 1, k - 1)) % mod;
	ret = (ret + go(id - 1, k)) % mod;
	return ret;
}
bool sm(int mask, int bt){
	if (((mask >> bt) & 1))return 1;
	return 0;
}
int bound;
ll dp2[80][600][(1 << 8) + 10];
ll go2(int id, int k, int mask){
	if (k < 0) return 0;
	if (id == bound){
		set<int>st;
		if (sm(mask, 0)) st.insert(0);
		if (sm(mask, 1)) st.insert(1);
		if (sm(mask, 2)) st.insert(2);
		if (sm(mask, 3)) st.insert(3);
		if (sm(mask, 4)) st.insert(0) , st.insert(3);
		if (sm(mask, 5)) st.insert(0) , st.insert(1);
		if (sm(mask, 6)) st.insert(1) , st.insert(2);
		if (sm(mask, 7)) st.insert(2) , st.insert(3);
		if (st.size() == 4) return go(N, k);
		return 0;
	}
	ll &ret = dp2[id][k][mask];
	if (ret != -1) return ret;
	ret = 0;
	ret = (ret + go2(id + 1, k - 1, (mask | (1 << g[id])))) % mod;
	ret = (ret + go2(id + 1, k, mask)) % mod;
	return ret;
}
int main()
{
	Emsawy();
	int t , c = 0;
	cin >> t;
	while (t--){
		cin >> n >> m >> k;
		N = n * m;
		
		for (int i = 0; i < m; i++)
			g[i] = 0;
		g[0] = 4;
		for (int i = m; i < n + m - 1; i++)
			g[i] = 1;
		g[m - 1] = 5;
		for (int i = n + m - 1; i < n + m * 2 - 2; i++)
			g[i] = 2;
		g[n + m - 2] = 6;
	
		for (int i = n + 2 * m - 2; i < n * 2 + m * 2 - 4; i++)
			g[i] = 3;
		g[n + m * 2 - 3] = 7;
		bound = n * 2 + m * 2 - 4;
		N -= bound;

		clr(dp, -1);
		clr(dp2, -1);

		printf("Case %d: %lld\n", ++c, go2(0, k, 0));

	}
	return 0;
}
