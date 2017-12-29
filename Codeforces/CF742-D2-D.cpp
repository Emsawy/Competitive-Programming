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
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

V<V<int> > adj;
const ll N = 1000 + 5;
int n, m, k, w;
int a[N], b[N],vs[N],cur;
int dp[N][N];

struct Node{
	int sumA, sumB;
	V<int> ve;
}comp[N];
int go(int id, int wi){
	if (wi > w) return -oo;
	if (id >= cur) return 0;
	int &ret = dp[id][wi];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(id + 1, wi));
	ret = max(ret, go(id + 1, wi + comp[id].sumA) + comp[id].sumB); 
	for (auto i : comp[id].ve){
		ret = max(ret, go(id + 1, wi + a[i]) + b[i]);
	}
	return ret;
}

void dfs(int nd){
	comp[cur].sumA += a[nd];
	comp[cur].sumB += b[nd];
	comp[cur].ve.push_back(nd);
	vs[nd] = cur;
	for (int i = 0; i < adj[nd].size(); i++){
		if (vs[adj[nd][i]] != -1) continue;
		dfs(adj[nd][i]);
	}
}
int main() {

	Emsawy();
	while (cin >> n >> m >> w){
		adj.clear();
		adj.resize(n); 
		clr(vs, -1);
		cur = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		int u, v;
		for (int i = 0; i < m; i++){
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 0; i < n; i++){
			if (vs[i] != -1) continue;
			dfs(i);
			cur++;
		}
		clr(dp, -1);
		cout << go(0, 0) << endl;
	}
	return 0;
}
