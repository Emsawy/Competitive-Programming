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
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
typedef unsigned long long          ull;
typedef long long                   ll;
typedef long double                 LD;
ll suf(ll x) { return (x * (x + 1)) / 2; }
V<V<pair<int, int> > > adj;
const ll mod = 1e9 + 7, oo = 1e8;
int n, m, x, y, z, k, T[100005][2], P[100005][20][3], L[100005];
void calT(int nd, int lv ,int wi, int lst ){
	T[nd][0] = lst;
	T[nd][1] = wi;
	L[nd] = lv;
	for (int i = 0; i < adj[nd].size(); i++){
		int child = adj[nd][i].first;
		if (child == lst) continue;
		calT(child, lv + 1, adj[nd][i].second, nd);
	}
}

void buildLCA(){
	for (int i = 0; i < 100005; i++){
		for (int j = 0; j < 20; j++){
			P[i][j][0] = -1;
			P[i][j][1] = 0;
			P[i][j][2] = oo;
		}
	}
	for (int i = 1; i <= n; i++){
		P[i][0][0] = T[i][0];
		P[i][0][1] = T[i][1];
		P[i][0][2] = T[i][1];
	}

	for (int j = 1; (1 << j) <= n; j++){
		for (int i = 1; i <= n; i++){
			if (P[i][j - 1][0] != -1){
				P[i][j][0] = P[P[i][j - 1][0]][j - 1][0];
				P[i][j][1] = max(P[i][j - 1][1], P[P[i][j - 1][0]][j - 1][1]);
				P[i][j][2] = min(P[i][j - 1][2], P[P[i][j - 1][0]][j - 1][2]);
			}
		}
	}
}
int getLCA(int p, int q){
	if (L[p] < L[q]) swap(q, p);
	int HI = log2(L[p]);
	for (int i = HI; i >= 0; i--){
		if (L[p] - (1 << i) >= L[q])
			p = P[p][i][0];
	}
	if (p == q) return p;
	for (int i = HI; i >= 0; i--){
		if (P[p][i][0] != -1 && P[p][i][0] != P[q][i][0])
			p = P[p][i][0], q = P[q][i][0];
	}
	return T[p][0];
}
int getmx(int lca, int x){
	int mx = 0;
	int H = log2(abs(L[x] - L[lca]));
	for (int j = H; j >= 0; j--)
		if (L[x] - (1 << j) >= L[lca]){
			mx = max(mx , P[x][j][1]);
			x = P[x][j][0];
		}
	return mx;
}
int getmn(int lca, int x){
	int mn = oo;
	int H = log2(abs(L[x] - L[lca]));
	for (int j = H; j >= 0; j--)
		if (L[x] - (1 << j) >= L[lca]){
			mn = min(mn, P[x][j][2]);
			x = P[x][j][0];
		}
	return mn;
}
int main()
{
	Emsawy();
	while (cin >> n){
		adj.resize(n + 1);
		for (int i = 0; i < n - 1; i++){
			cin >> x >> y >> k;
			adj[x].push_back(MP(y,k));
			adj[y].push_back(MP(x,k));
		}
		calT(1, 0 , -1, -1);
		buildLCA();
		int m , l ,r;
		cin >> m;
		while (m--){
			cin >> l >> r;
			int lca = getLCA(l, r);
			cout << min(getmn(lca, l), getmn(lca, r)) << " ";
			cout << max(getmx(lca, l), getmx(lca, r)) << endl;
		}

	}
	return 0;
}
