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

V<V<pair<int,int> > > adj;
const ll N = 1000000 + 5;
ll n, m, k, w;
struct edge{
	int u, v, w;
	edge(){}
	edge(int u, int v, int w) :u(u), v(v), w(w){}
	bool operator <(edge &e){
		if (w > e.w) return 1;
		return 0;
	}
};
struct UnionFind{
	V<int> rank, F;
	int comp;
	UnionFind(int n){
		rank = V<int>(n);
		F = V<int>(n);
		comp = n;
		for (int i = 0; i < n; i++)
			F[i] = i;
	}
	int find_set(int x){
		if (x == F[x]) return x;
		return F[x] = find_set(F[x]);
	}
	void link(int x, int y){
		if (rank[x] > rank[y]) swap(x, y);
		if (rank[x] == rank[y]) rank[y]++;
		F[x] = y;
	}
	bool union_set(int x, int y){
		x = find_set(x), y = find_set(y);
		if (x == y) return 0;
		link(x, y);
		comp--;
		return 1;
	}
};

int main() {

	Emsawy();
	int t;
	cin >> t;
	while (cin >> n){
		if (n == 0) break;
		cin >> m;
		int u, v;
		V<edge > mst(m);
		for (int i = 0; i < m; i++){
			cin >> mst[i].u >> mst[i].v >> mst[i].w;
			mst[i].u--;
			mst[i].v--;
		}
		UnionFind uf(n);
		sort(all(mst));
		int ans = 0;
		for (int i = 0; i < m; i++){
			if (uf.union_set(mst[i].u, mst[i].v) == 0) 
				ans += mst[i].w;
		}
		cout << ans << endl;

	}
	return 0;
}
