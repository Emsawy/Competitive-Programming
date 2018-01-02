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


const ll N = 22 + 5;
int n, m, k, w;
const int si = 71000;
int vs[si], cur = 1;
V<pair<int, int> > adj[si];

void removeEdge(int u, int v, int vl){
	for (int i = 0; i < adj[u].size();i++){
		if (adj[u][i].first == v){
			adj[u][i].second -= vl;
			return;
		}
	}
}
void addEdge(int u, int v, int vl){
	for (int i = 0; i < adj[u].size(); i++){
		if (adj[u][i].first == v){
			adj[u][i].second += vl;
			return;
		}
	}
	adj[u].push_back(MP(v, vl));
}
V<int>path;
int getpath(int str, int dis, int mx){

	path.push_back(str);
	if (str == dis)
		return mx;
	int ret = 0;
	vs[str] = cur;
	for (int i = 0; i < adj[str].size();i++){
		if (vs[adj[str][i].first] == cur || adj[str][i].second == 0) continue;
		ret = getpath(adj[str][i].first, dis, min(mx, adj[str][i].second));
		if (ret) break;
	}
	if (!ret) path.pop_back();
	return ret;
}
int MaxFlow(int str, int dis){
	int ans = 0, ret = 0;
	cur++;
	ret = getpath(str, dis, oo);
	while (path.size()){
		for (int i = 1; i < path.size(); i++){
			removeEdge(path[i - 1], path[i], ret);
			addEdge(path[i], path[i - 1], ret);
		}
		cur++;
		ans += ret;
		path.clear();
		ret = getpath(str, dis, oo);
	}
	return ans;
}

int main()
{
	Emsawy();
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		int u, v;
		for (int i = 0; i < si; i++)
			adj[i].clear();
		for (int i = 1; i <= n; i++){
			if (i == 2) continue;
			adj[i].push_back(MP(i + n, 1));
		}
		for (int i = 0; i < m; i++){
			cin >> u >> v;
			if (u > n || v > n) continue;
			if (u == 2)
				adj[2].push_back(MP(v,1));
			else if (v == 2)
				adj[2].push_back(MP(u, 1));
			else{
				adj[u + n].push_back(MP(v, 1));
				adj[v + n].push_back(MP(u, 1));
			}
		}
		adj[1 + n].push_back(MP(n * 2 + 1, 1));
		adj[3 + n].push_back(MP(n * 2 + 1, 1)); 
		if (MaxFlow(2, n * 2 + 1) == 2) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}
