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
const double EPS = 1e-9;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<int> > adj;
int n, m , k , t;
int vs[300], cur = 0;

struct Node{
	int nd, cnt;
	Node(){
		nd = cnt = 0;
	}
	Node(int a, int c) : nd(a), cnt(c){}
};

Node lastnode(int nd,int lst){
	cur++;
	Node p;
	queue<Node> q;
	q.push(Node(nd,0));
	vs[nd] = vs[lst] = cur;
	while (!q.empty()){
		p = q.front();
		q.pop();
		for (auto it : adj[p.nd]){
			if (vs[it] == cur) continue;
			vs[it] = cur;
			q.push(Node(it, p.cnt + 1));
		}
	}
	return p;
}

int longspath(int nd , int lst){
	Node go = lastnode(nd,lst);
	Node back = lastnode(go.nd, lst);
	return back.cnt;
}

int main()
{
	Emsawy();
	while (cin >> n){
		adj.clear();
		adj.resize(n);
		int u, v;
		for (int i = 1; i < n; i++){
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int mx = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < adj[i].size(); j++){
				int l = longspath(i , adj[i][j]), r = longspath(adj[i][j] , i);
				mx = max(mx, l* r);
			}
		}
		cout << mx << endl;
	}
	return 0;
}
