/*
  Using masks, w can chose all the variace choices sets of nodes and for each set do the following:
  - calculate the sum of wight for all nodes (denominator) by iterating on each wight node; 
  - calculate the sum of wight for all edges (Numerator) with Minimum spanning tree
  order the sets as requsted:
  first : with minimum ratio;
  second : with smallest size of each set has the minimum ratio;
  third : with lexicographical order (smallest) ;
  
  Notes:
   when comparing ratios, avoid the doubles
   Example:
    comparing (a/b, c/d)
    will be:
            a * c < b * d
*/



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
int wi[20], g[20][20];
struct edge{
	int u, v, w;
	edge(){}
	edge(int u, int v, int w) :u(u), v(v), w(w){}
	bool operator <(edge &e){
		if (w < e.w) return 1;
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
struct Node{
	V<int> nd;
	int edges;
	int nodes;
	Node(){
		edges = nodes = 0;
	}
	void Ratio(){
		V<edge> edg;
		for (int i = 0; i < nd.size(); i++){
			nodes += wi[nd[i]];
			for (int j = i + 1; j < nd.size(); j++){
				edg.push_back(edge(nd[i], nd[j], g[nd[i]][nd[j]]));
				edg.push_back(edge(nd[j], nd[i], g[nd[j]][nd[i]]));
			}
		}
		sort(all(edg));
		UnionFind uf(n);
		for (int i = 0; i < edg.size(); i++){
			if (uf.union_set(edg[i].u, edg[i].v))
				edges += edg[i].w;
		}
	}
	bool operator <(Node & l) const {
		if (edges * l.nodes < nodes * l.edges) return 1;
		else if (edges * l.nodes == nodes * l.edges && nd.size() < l.nd.size()) return 1;
		else if (edges * l.nodes == nodes * l.edges && nd.size() == l.nd.size() && nd < l.nd) return 1;
		return 0;
	}

} ord[(1 << 16)];

int main() {

	Emsawy();
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++){
			cin >> wi[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> g[i][j];
			}
		}
		int mask = 1 << n;
		for (int i = 0; i < mask; i++){
			for (int j = 0; j < n; j++){
				if (((i >> j) & 1)){
					ord[i].nd.push_back(j);
				}
			}
			ord[i].Ratio();
		}
		sort(ord, ord + mask);
		for (int i = 0; i < mask; i++){
			if (ord[i].nd.size() == m){
				for (int j = 0; j < ord[i].nd.size(); j++){
					cout << ord[i].nd[j] + 1 << " \n"[j + 1 == ord[i].nd.size()];
				}
				break;
			}
		}
		for (int i = 0; i < mask; i++){
			ord[i].nd.clear();
			ord[i].nodes = ord[i].edges = 0;
		}
	}
	return 0;
}
