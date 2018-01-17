#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
ll mod = 1000000007, oo = 1e18;

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

int n, m, k, w;
const int N = 100000 + 5;
struct Node
{
	int nd, typ;
	ll w;
	Node(){}
	Node(ll w, int nd, int typ) :w(w), nd(nd), typ(typ){}
	bool operator<(const Node & l) const{
		if (w > l.w) return 1;
		else if (w == l.w && typ == 0) return 1;
		return 0;
	}
};
V<V<Node > > adj;
ll g[N];
bool typ[N];

int main() {

	Emsawy();
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		adj.clear();
		adj.resize(n);
		int u, v;
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &w);
			u--, v--;
			adj[u].push_back(Node(w, v, 0));
			adj[v].push_back(Node(w, u, 0));
		}
		for (int i = 0; i < k; i++){
			scanf("%d%d", &u, &w);
			u--;
			adj[0].push_back(Node(w, u, 1));
			adj[u].push_back(Node(w, 0, 1));
		}
		fill(g, g + N, oo);
		priority_queue<Node> pq;
		pq.push(Node(0, 0, 0));
		while (!pq.empty()){
			Node p = pq.top();
			pq.pop();
			if (g[p.nd] < p.w) continue;
			for (int i = 0; i < adj[p.nd].size(); i++){
				ll ch = adj[p.nd][i].nd, cost = p.w + adj[p.nd][i].w;
				if (g[ch] > cost){
					g[ch] = cost;
					typ[ch] = adj[p.nd][i].typ;
					pq.push(Node(cost, ch, typ[ch]));
				}
				else if (g[ch] == cost && typ[ch] > adj[p.nd][i].typ){
					typ[ch] = adj[p.nd][i].typ;
					pq.push(Node(cost, ch, typ[ch]));
				}
			}
		}
		for (int i = 1; i < n; i++){
			k-= typ[i];
		}
		printf("%d\n", k);
	}
	return 0;
}
