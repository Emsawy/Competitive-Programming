/*
- every point is a node in graph you can construct.
- then with splitting the node to two nodes and add a capacity between them
with the max in the problem for every node (i -> (i + n))
- and run on the graph maxflow algo and get the answer for every node if that node is the destination node
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1e18 + 1, oo = 1e15;

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
int n, m, k, w, p;
ll shp[N][N];
ll dp[14][(1 << 14) + 1];

struct Node{
	ll nd, w;
	Node(){}
	Node(ll nd, ll w) :nd(nd), w(w){}

};

V<Node> stores;

int main() {

	cout << fixed << setprecision(2);
	Emsawy();
	int T;
	cin >> T;
	while (T--){
		fill(shp[0], shp[0] + N * N, oo);
		cin >> n >> m;
		ll u, v, dol, cent;
		char dot;
		for (int i = 0; i < m; i++){
			cin >> u >> v >> dol >> dot >> cent;
			shp[u][v] = min(shp[u][v], (dol * 100 + cent));
			shp[v][u] = min(shp[v][u], (dol * 100 + cent));
		}
		for (int i = 0; i <= n; i++)
			shp[i][i] = 0;
		for (int k = 0; k <= n; k++){
			for (int i = 0; i <= n; i++){
				for (int j = 0; j <= n; j++){
					shp[i][j] = min(shp[i][j], shp[i][k] + shp[k][j]);
				}
			}
		}
		cin >> p;
		stores.clear();
		stores.push_back(Node(0, 0));
		for (int i = 0; i < p; i++){
			cin >> u >> dol >> dot >> cent;
			stores.push_back(Node(u, dol * 100 + cent));
		}
		p = stores.size();
		fill(dp[0], dp[0] + 14 * (1 << 14) + 1, -oo);
		ll ans = -oo;
		dp[0][1] = 0;
		for (int msk = 0; msk < (1 << p); msk++){
			for (int i = 0; i < p; i++){
				for (int j = 0; j < p; j++){
					if (i == j) continue;
					if (j == 0) continue;
					if (((msk >> i) & 1) == 0 || ((msk >> j) & 1) == 0)continue;
					dp[j][msk] = max(dp[j][msk], dp[i][msk ^ (1 << j)] + stores[j].w - shp[stores[i].nd][stores[j].nd]);
					ans = max(ans, dp[j][msk] - shp[stores[j].nd][0]);
				}
			}
		}
		
		if (ans > 0) cout << "Daniel can save $" << ans / 100.0 << endl;
		else cout << "Don't leave the house" << endl;
	}
	return 0;
}
