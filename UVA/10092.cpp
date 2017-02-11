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
int n, m, t, x;

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
	int ans = 0, ret = 0;
	while (ret = getpath(str, dis, oo))
		cur++, ans += ret;
	return ans;
}
V<V<int> > v;
int get(int id ,int lst = -1){
	if (id == 0) return lst;
	int ret = 0;
	for (int i = 0; i < si; i++){
		if (g[id][i] == 0) continue;
		if (ret = get(i, id)){
			g[id][i] = 0;
			return ret;
		}
	}
	return 0;
}
int main()
{
	Emsawy();
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		vector<int>c(n + 1);
		int st = 0, e = n + m + 1 , tot = 0;
		for (int i = 1; i <= n; i++){
			cin >> c[i];
			g[i + m][e] = c[i];
			tot += c[i];
		}
		for (int i = 1; i <= m; i++){
			cin >> t;
			for (int j = 0; j < t; j++){
				cin >> x;
				g[i][x + m] = 1;
			}
		}
		for (int i = 1; i <= m; i++)
			g[st][i] = 1;
		int ret = MaxFlow(st, e);
		if (ret == tot){
			v.clear();
			v.resize(n + 1);
			bool ok = 0;
			for (int i = 1; i <= n; i++){
				int ret = 0;
				while (ret = get(i + m, -1)){
					v[i].push_back(ret);
				}
				if (v[i].size() < c[i]) ok = 1;
			}
			if (ok) cout << "0\n";
			else{
				cout << "1" << endl;
				for (int i = 1; i <= n; i++){
					for (int j = 0; j < c[i]; j++)
						cout << v[i][j] << " \n"[j == c[i] - 1];
				}
			}
		}
		else cout << "0" << endl;
		clr(g, 0);
		clr(vs, 0);
		cur = 1;
	}
	return 0;
}
