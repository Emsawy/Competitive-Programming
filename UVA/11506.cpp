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
const ll N = 100 + 5;
int n, m, k, w, h;
int vs[N], cur = 1;
int g[N][N];
void removeEdge(int u, int v, int vl){
	g[u][v] -= vl;
}
void addEdge(int u, int v, int vl){
	g[u][v] += vl; 
}
V<int>path;
int getpath(int str, int dis, int mx){

	path.push_back(str);
	if (str == dis)
		return mx;
	int ret = 0;
	vs[str] = cur;
	for (int i = 1; i <= n * 2; i++){
		if (vs[i] == cur || g[str][i] <= 0) continue;
		ret = getpath(i, dis, min(mx, g[str][i]));
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
int main() {

	Emsawy();
	while (cin >> m >> w){
		if (m + w == 0) break;
		n = m;
		int u, v, wi;
		for (int i = 0; i < m - 2; i++){
			scanf("%d%d", &u, &wi);
			g[u][u + n] = wi;
		}
		for (int j = 0; j < w; j++){
			scanf("%d%d%d", &u, &v, &wi);
			if (u > v) swap(u, v);
			if (u == 1){
				g[u][v] = wi;
				g[v + n][u] = wi;
			}
			else if (v == n){
				g[u + n][v] = wi;
				g[v][u] = wi;
			}
			else {
				g[u + n][v] = wi;
				g[v + n][u] = wi;
			}
		}
		int mx = MaxFlow(1, n);
		cout << mx << endl;
		clr(g, 0);
	}
	return 0;
}
