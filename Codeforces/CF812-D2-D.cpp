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
int n, m, k, w, q;

int lst[N], ans[N], in[N],inp[N],oup[N], st;
int go(int nd){
	ans[nd] = 1;
	inp[nd] = st++;
	for (int i = 0; i < adj[nd].size(); i++){
		ans[nd] += go(adj[nd][i]);
	}
	oup[nd] = st++;
	return ans[nd];
}
int main() {

	Emsawy();
	while (cin >> n >> m >> k >> q){
		int u, v;
		adj.clear();
		adj.resize(n+1);
		for (int i = 0; i < k; i++){
			cin >> u >> v;
			if (lst[v] == 0){
				lst[v] = u;
				continue;
			}
			adj[lst[v]].push_back(u);
			in[u] = 1;
			lst[v] = u;
		}
		for (int i = 1; i <= n; i++){
			if (in[i] == 0){
				go(i);
			}
		}
		for (int i = 0; i < q; i++){
			cin >> u >> v;
			if (lst[v] == 0) cout << 0 << endl;
			else if (inp[u] <= inp[lst[v]] && oup[u] >= oup[lst[v]]) cout << ans[u] << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}
