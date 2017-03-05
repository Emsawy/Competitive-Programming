/*
- I get the Longest path, for each neighbors nodes, i assume that i will cut this edge, then will apears two trees.
- I will get from each tree it's diameter and combine a new tree with (X) diameter and get the samllest one and it's center node
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define sz(v) ((int)((v).size()))
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<int > > adj;
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9 , si = 3501;
int n, m, k, t, u, v;
int prv[si];
pair<int,int> TreeD(int node , int prevent){  // get tree diameter (last node of the tree , it's lenght)
	clr(prv, -1);
	pair<int,int> p;
	queue<pair<pair<int,int>, int > > q;
	q.push(MP(MP(node, 0), -1));
	while (!q.empty()){
		p = q.front().first;
		int par = q.front().second;
		prv[p.first] = par;
		q.pop();
		for (int i = 0; i < adj[p.first].size(); i++){
			int ch = adj[p.first][i];
			if (ch == par || ch == prevent) continue;
			q.push(MP(MP(ch, p.second + 1), p.first));
		}
	}
	return p;
}
int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> n;
		adj.clear();
		adj.resize(n);
		V<pair<int, int> > edges;
		for (int i = 0; i < n - 1; i++){
			sf2(u, v);
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int mn = oo , ed = -1 , hlf;
		pair<int, int> p = TreeD(TreeD(0, -1).first, -1); // get the diameter of the original tree
		while (prv[p.first] != -1){ // get the path of this diameter
			edges.push_back(MP(p.first, prv[p.first]));
			p.first = prv[p.first];
		}
		for (int i = 0; i < edges.size(); i++){ // cut this edge and get the new tree 
			pair<int, int>a = TreeD(TreeD(edges[i].first, edges[i].second).first, edges[i].second);
			pair<int, int>b = TreeD(TreeD(edges[i].second, edges[i].first).first, edges[i].first);
			int now = (a.second + 1) / 2 + (b.second + 1) / 2 + 1;  // new diameter 
			now = max(now, max(a.second, b.second)); // handel some unvalid cases
			if (mn > now){
				mn = now;
				ed = i;
			}
		}	
		pair<int, int>a = TreeD(TreeD(edges[ed].first, edges[ed].second).first, edges[ed].second); // get the last node in the first tree 
		hlf = a.second / 2;
		while (hlf--) a.first = prv[a.first]; // get the node center 
		pair<int, int>b = TreeD(TreeD(edges[ed].second, edges[ed].first).first, edges[ed].first); // get the last node in the second tree
		hlf = b.second / 2; 
		while (hlf--) b.first = prv[b.first]; // get the node center 
		printf("%d\n", mn); // print the answer :)
		printf("%d %d\n", edges[ed].first + 1, edges[ed].second + 1); 
		printf("%d %d\n", a.first+1, b.first+1);
	}
	return 0;
}
