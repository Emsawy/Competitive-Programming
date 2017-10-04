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

#define sz(v)			((int)((v).size()))
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define clr(v,d)		memset(v, d, sizeof(v))
#define sf(x)			scanf("%d", &x)
#define sf2(x,y)		scanf("%d %d", &x, &y)
#define sf3(x,y,z)		scanf("%d %d %d", &x, &y, &z)
#define sfll(x)			scanf("%I64d", &x)
#define sfll2(x,y)		scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)		scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) <= EPS)
#define rotate0(p,ang)		((p)*exp(Point(0,ang)))
#define rotateA(p,ang,about)	(rotate0(vec(about,p),ang)+about)
#define reflect0(v,m)		(conj((v)/(m))*(m))
#define normalize(a)		(a)/length(a)
#define lengthSqr(p)		dp(p,p)
#define pii			pair<int,int>
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()

typedef complex<double> 	point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<int > > adj;
int n, m, k, t, c, a, x, y, d, b, l, r;

V<int>deg;
queue<int> q;
void dfs(int node, int lst){
	deg[node] = adj[node].size();
	for (int i = 0; i < adj[node].size(); i++){
		if (adj[node][i] == lst) continue;
		dfs(adj[node][i], node);
	}
	if (adj[node].size() == 1)
		q.push(node);
}
pair<int,int> Tree(int node){
	deg.clear();
	deg.resize(n);
	dfs(node, node);
	int N = n;
	while (N > 2){
		int size = q.size();
		for (int i = 0; i < size; i++){
			int p = q.front(); q.pop();
			for (int ch = 0; ch < adj[p].size();ch++){
				if (--deg[adj[p][ch]] == 1)
					q.push(adj[p][ch]);
			}
			N--;
		}
	}
	pair<int, int> ret(-1,-1);
	ret.first = q.front(), q.pop();
	if (q.size()) ret.second = q.front(), q.pop();
	return ret;
}
int hi = 0;
int dfs_hight(int nd, int lst){
	int ret = 0;
	for (auto it : adj[nd]){
		if (it == lst) continue;
		ret = max(ret , dfs_hight(it, nd) + 1);
	}
	return ret;
}

V<int>ans;
void leaf(int nd, int lst,int lvl){
	int ret = 0;
	for (auto it : adj[nd]){
		if (it == lst) continue;
		leaf(it, nd,lvl+1);
	}
	if (lvl == hi)
		ans.push_back(nd);
}

int main()
{
	Emsawy();
	while (cin >> n){
		adj.resize(n);
		for (int i = 0; i < n; i++){
			sf(t);
			while (t--){
				sf(c);
				adj[i].push_back(--c);
			}
		}
		pair<int, int> ret = Tree(0);
		printf( "Best Roots  : " );
		if (ret.second == -1)printf("%d\n", ret.first + 1 );
		else printf("%d %d\n",min(ret.first, ret.second) + 1 , max(ret.first, ret.second) + 1 );

		hi = dfs_hight(ret.first, ret.first);
		leaf(ret.first, ret.first, 0);
		if (ret.second != -1){
			leaf(ret.second, ret.second, 0);
		}
		printf( "Worst Roots : ");
		sort(all(ans));
		for (int i = 0; i < ans.size(); i++)
			printf("%d",ans[i] + 1 ),cout<< " \n"[i == sz(ans) - 1];
		adj.clear();
		ans.clear();
	}
	return 0;
}
