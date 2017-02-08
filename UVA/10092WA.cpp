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
const ll mod = 1e9 + 7, oo = 1e9;
int n, m, ct[100];

const int si = 3010;
int g[si][si], vs[si], cur = 1;
int getpath(int str, int dis, int mx){
	if (str == dis) 
		return mx;
	vs[str] = cur;
	for (int i = 0; i < si; i++){
		if (vs[i] == cur || g[str][i] <= 0) continue;
		if (int ret = getpath(i, dis, min(mx, g[str][i]))){
			g[str][i] -= ret;
			g[i][str] += ret;
			return ret;
		}
	}
	return 0;
}
int MaxFlow(int str, int dis){
	int ans = 0 , ret = 0;
	while (ret = getpath(str, dis, oo))
		cur++, ans += ret;
	return ans;
}
int get(int x){
	if (x < n) 
		return x;
	int ret = -1;
	for (int i = 0; i < si; i++){
		if (g[x][i] == 0) continue;
		if ((ret = get(i)) != -1){
			return ret;
		}
	}
	return ret;
}
int main()
{
	Emsawy();
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		int tot = 0;
		for (int i = 0; i < n; i++)
			sf(ct[i]) , tot += ct[i];
		for (int i = 0; i < m; i++){
			int k; sf(k);
			for (int j = 0; j < k; j++){
				int t; sf(t);
				g[t - 1][i + n] = 1;
			}
		}
		int mx = n + m;
		for (int i = 0; i < n; i++)
			g[mx][i] = ct[i];
		for (int i = 0; i < m; i++)
			g[i + n][mx + 1] = 1;

		int back = MaxFlow(mx, mx + 1);
		V<V<int> > ans(n);
		int ret = -1;
		for (int j = n; j < si; j++){
			if (g[n + m + 1][j] == 0) continue;
			if ((ret = get(j)) != -1){
				ans[ret].push_back(j);
			}
		}
		if (back != tot) cout << 0 << endl;
		else{
			cout << 1 << endl;
			for (int i = 0; i < ans.size(); i++){
				for (int j = 0; j < ct[i]; j++)
					cout << ans[i][j] << " \n"[j == ct[i] - 1];
			}
		}
		clr(g, 0);
		clr(vs, 0);
		cur = 1;
	}
	return 0;
}
