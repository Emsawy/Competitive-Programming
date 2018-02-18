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
const ll N = 100000 + 5;
int n, m, k, w;

ll freq = -1, ans = 0;
int cnt[N], sz[N], col[N];
ll querys[N];
void getsz(int v, int p){
	sz[v] = 1;
	for (auto u : adj[v]){
		if (u != p){
			getsz(u, v);
			sz[v] += sz[u];
		}
	}
}
void check_Answer(int u){
	if (cnt[col[u]] > freq){
		freq = cnt[col[u]];
		ans = col[u];
	}
	else if (cnt[col[u]] == freq){
		ans += col[u];
	}
}
void modify(int v, int p, int x, int &bigChild){
	cnt[col[v]] += x;
	if (x == 1) check_Answer(v);
	else ans = 0, freq = -1;
	for (auto u : adj[v]){
		if (u != p && u != bigChild){
			modify(u, v, x, bigChild);
		}
	}
}
void dfs(int v, int p, int keep){
	int mx = -1, bigChild = -1;
	for (auto u : adj[v])
		if (u != p && mx < sz[u])
			mx = sz[u], bigChild = u;

	for (auto u : adj[v])
		if (u != p && u != bigChild)
			dfs(u, v, 0);

	if (bigChild != -1)
		dfs(bigChild, v, 1);
	modify(v, p, 1, bigChild);
	querys[v] = ans;
	if (keep == 0)
		modify(v, p, -1, p);
}

int main() {

	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> col[i];
		}
		adj.clear();
		adj.resize(n);
		for (int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			adj[u - 1].push_back(v - 1);
			adj[v - 1].push_back(u - 1);
		}
		getsz(0, 0);
		dfs(0, 0, 0);
		for (int i = 0; i < n; i++){
			cout << querys[i] << " ";
		}
		puts("");
	}
	return 0;
}
