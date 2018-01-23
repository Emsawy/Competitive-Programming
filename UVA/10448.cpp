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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
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
const ll N = 50 + 5;
int n, m, k, w;
int shp[N][N];
int path[N][N];

V<int> cost;
void Path_F(int src, int sink){
	if (path[src][sink] == -1){
		cost.push_back(shp[src][sink]);
		return;
	}
	Path_F(src, path[src][sink]);
	Path_F(path[src][sink], sink);
}
void Get_Path(int src, int sink){
	cost.clear();
	Path_F(src, sink);
}
int dp[N][100101];
int can(int nd, int w){
	if (w == 0) return 0;
	if (w < 0 || nd >= cost.size()) return oo;
	int &ret = dp[nd][w];
	if (ret != -1) return ret;
	ret = oo;
	ret = min(ret, can(nd, w - cost[nd] * 2) + 2);
	ret = min(ret, can(nd + 1, w));
	return ret;
}
int main() {

	Emsawy();
	int T, ok = 0;
	cin >> T;
	while (T--){
		if (ok) cout << endl;
		ok = 1;
		int u, v, w;
		cin >> n >> m;
		fill(shp[0], shp[0] + N * N, oo);
		for (int i = 0; i < m; i++){
			cin >> u >> v >> w;
			u--, v--;
			shp[u][v] = min(shp[u][v], w);
			shp[v][u] = min(shp[v][u], w);
		}
		clr(path, -1);
		for (int i = 0; i < n; i++) shp[i][i] = 0;
		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (shp[i][j] > shp[i][k] + shp[k][j]){
						shp[i][j] = shp[i][k] + shp[k][j];
						path[i][j] = k;
					}
				}
			}
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; i++){
			cin >> u >> v >> w;
			u--, v--;
			if (u == v){
				if (w == 0) cout << "Yes " << 0 << endl;
				else cout << "No" << endl;
				continue;
			}
			Get_Path(u, v);
			w -= shp[u][v];
			cost.pop_back();
			clr(dp, -1);
			int query = can(0, w) + cost.size() + 1;
			if (query == oo + cost.size() + 1) cout << "No" << endl;
			else cout << "Yes " << query << endl;
		}
	}
	return 0;
}
