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

V<V<pair<int,int> > > adj;
const ll N = 5000 + 5;
long double eps = 1e-15;
ll n, m, k, w, q;
int dp[N][N];
int path[N][N];

int main() {

	Emsawy();
	ll T;
	while (cin >> n >> m >> T){
		int u, v;
		adj.clear(); adj.resize(n + 1);
		for (int i = 0; i < m; i++){
			cin >> u >> v >> w;
			adj[v].push_back(MP(u, w));
		}
		fill(dp[0], dp[0] + N * N, oo);
		dp[1][1] = 0;
		for (int j = 1; j <= n; j++){
			for (int i = 1; i <= n; i++){
				for (int nd = 0; nd < adj[i].size(); nd++){
					if (dp[i][j] > dp[adj[i][nd].first][j - 1] + adj[i][nd].second){
						dp[i][j] = dp[adj[i][nd].first][j - 1] + adj[i][nd].second;
						path[i][j] = adj[i][nd].first;
					}
				}
			}
		}
		int idx = 0;
		for (int i = 1; i <= n; i++){
			if (dp[n][i] <= T){
				idx = i;
			}
		}
		V<int>ans;
		while (n != 0){
			ans.push_back(n);
			n = path[n][idx--];
		}
		cout << ans.size() << endl;
		for (int i = ans.size() - 1; i >= 0; i--){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
// recursive
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

V<V<pair<int,int> > > adj;
const ll N = 100000 + 5;
long double eps = 1e-15;
ll n, m, k, w, q;
int dp[5010][5010];
int path[5010][5010];

int go(int nd, int j){
	if (nd == n) 
		return (j == 1 ? 0 : oo);
	if (j <= 1) return oo;
	int &ret = dp[nd][j];
	if (ret != -1) return ret;
	ret = oo;
	for (int i = 0; i < adj[nd].size(); i++){
		if (ret > go(adj[nd][i].first, j - 1) + adj[nd][i].second){
			ret = go(adj[nd][i].first, j - 1) + adj[nd][i].second;
			path[nd][j] = adj[nd][i].first;
		}
	}
	return ret;
}

int main() {

	Emsawy();
	ll T;
	while (cin >> n >> m >> T){
		int u, v;
		adj.clear(); adj.resize(n + 1);
		for (int i = 0; i < m; i++){
			cin >> u >> v >> w;
			adj[u].push_back(MP(v, w));
		}
		clr(dp, -1);
		int idx = -1;
		for (int i = 1; i <= n; i++){
			if (go(1, i) <= T){
				idx = i;
			}
		}
		int N = 1;
		V<int>ans;
		while (N != 0){
			ans.push_back(N);
			N = path[N][idx--];
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

*/
