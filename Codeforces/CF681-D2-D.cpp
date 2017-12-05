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
V<V<int> > adj, tree;
const int N = 100000 + 5;
int deg[N], to[N], vs[N], cur, par[N];
bool go(int nd, int stp){
	if (nd == stp) return 0;
	if (vs[nd]) return 1;
	vs[nd] = 2;
	if (go(par[nd], stp)) return 1;
	return 0;
}
bool mark(int nd, int stp){
	if (nd == stp) return 0; 
	if (vs[nd] == 1) return 1;
	vs[nd] = 2;
	if (mark(par[nd], stp))return 1;
	return 0;
}
V<int>ans;
void get(int nd){
	for (int i = 0; i < adj[nd].size(); i++)
		get(adj[nd][i]);
	if (vs[nd] == 1)
		ans.push_back(nd);
}
int main()
{
	Emsawy();
	while (cin >> n >> m){
		int u, v;
		adj.resize(n);
		for (int i = 0; i < m; i++){
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			deg[v]++;
			par[v] = u;
		}
		bool ok = 0;
		for (int i = 0; i < n; i++){
			cin >> to[i];
			to[i]--;
			if (vs[to[i]] == 2){
				ok = 1;
			}
			if (vs[to[i]] == 1){
				ok |= mark(i, to[i]);
				continue;
			}
			vs[to[i]] = 1;
			ok |= go(i, to[i]);
		}
		for (int i = 0; i < n; i++){
			if (deg[i]) continue;
			get(i);
		}
		if (ok){
			cout << -1 << endl;
			continue;
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] + 1 << "\n";
		}
	}
	return 0;
}
