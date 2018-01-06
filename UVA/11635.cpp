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
const ll N = 10010 + 5;
int n, m, k, w, h;
bool hotle[N];
int g[N][110];
struct Node{
	int w;
	int city, hot;
	Node(){}
	Node(int city, int hot, int w) : city(city), hot(hot), w(w){}
	bool operator < (const Node & l) const{
		if (w > l.w) return 1;
		return 0;
	}
};
int main() {

	Emsawy();
	int t=0;
	while (cin >> n){
		if (n == 0) break;
		adj.resize(n + 1);
		cin >> h;
		for (int i = 0; i < h; i++){
			cin >> w;
			hotle[w] = 1;
		}
		cin >> m;
		int u, v;
		for (int i = 0; i < m; i++){
			cin >> u >> v >> w;
			adj[u].push_back(MP(v, w));
			adj[v].push_back(MP(u, w));
		}
		fill(g[0], g[0] + N * 110, oo);
		priority_queue<Node >pq;
		pq.push(Node(1, 0, 0));
		g[1][0] = 0;
		while (!pq.empty()){
			Node p = pq.top();
			pq.pop();
			for (int i = 0; i < adj[p.city].size(); i++){
				int ch = adj[p.city][i].first, wi = adj[p.city][i].second;
				if (p.w + wi > 600) continue;
				if (g[ch][p.hot] > p.w + wi && p.hot <= h){
					g[ch][p.hot] = p.w + wi;
					pq.push(Node(ch, p.hot, wi + p.w));
				}
				if (hotle[ch]){
					if (g[ch][p.hot + 1] > 0 && p.hot <= h){
						g[ch][p.hot + 1] = 0;
						pq.push(Node(ch, p.hot + 1, 0));
					}
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < 110; i++){
			if (g[n][i] != oo){
				ans = i;
				break;
			}
		}
		cout << ans << endl;
		adj.clear();
		clr(hotle, 0);
	}
	return 0;
}
