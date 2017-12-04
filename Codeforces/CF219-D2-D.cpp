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
	ios::sync_with_stdio(false);   // don't use scanf & printf
	cin.tie(0);
	cout.tie(0);
}

#define p00          point(0,0)
#define O            const point & 
#define CD           const double &  
#define EQ(a, b)     (fabs((a) - (b)) <= eps) /* equal to */
#define LT(a, b)     ((a) < (b)-eps) /* less than */
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define clr(v,d)     memset(v, d, sizeof(v))
#define length(a)    (hypot((a).imag(), (a).real()))
#define dp(a,b)	     ((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)	     ((conj(a)*(b)).imag()) // if zero parl
#define pii	         pair<int,int>
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;

typedef long long ll;

const double PI = acos(-1.0);
const double eps = 1e-10;
const ll mod = 1e9 + 7, oo = 1e9;

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

int n, m, k, t, c;
const int N = 2 * 100000 + 5;
struct Node
{
	int nd;
	int from;
	Node(){ nd = from = 0;}
	Node(int nd) : nd(nd), from(0){}
};
V<Node> adj[N];
int par[N], vs[N];

set<pair<int, int> >st;
Node go(Node x){
	for (int i = 0; i < adj[x.nd].size(); i++){
		if (vs[adj[x.nd][i].nd]) continue;
		vs[adj[x.nd][i].nd] = 1;
		Node ret = go(adj[x.nd][i]);
		x.from += ret.from + (st.find(MP(adj[x.nd][i].nd, x.nd)) != st.end());
	}
	return x;
}
V<pair<int, int> >ans;
void solve(Node x, int cnt){
	ans.push_back(MP(cnt, x.nd));
	for (int i = 0; i < adj[x.nd].size(); i++){
		if (vs[adj[x.nd][i].nd]) continue;
		vs[adj[x.nd][i].nd] = 1;
		solve(adj[x.nd][i], cnt + ((st.find(MP(adj[x.nd][i].nd, x.nd)) == st.end())? 1: -1));
	}
}
int main()
{
	Emsawy();
	while (cin >> n){
		int u, v;
		for (int i = 0; i < n - 1; i++){
			cin >> u >> v;
			adj[u].push_back(Node(v));
			adj[v].push_back(Node(u));
			st.insert(MP(u, v));
		}
		vs[1] = 1;
		Node ret = go(Node(1));
		clr(vs, 0);
		vs[1] = 1;
		solve(Node(1), ret.from);
		sort(all(ans));
		cout << ans[0].first << endl;
		for (int i = 0; i < ans.size(); i++){
			if (ans[i].first == ans[0].first) cout << ans[i].second << " ";
			else break;
		}
		cout << endl;
	}
	return 0;
}
