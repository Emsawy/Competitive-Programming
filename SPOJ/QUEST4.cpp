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

V<V<pii> > adj;
int n, m, k, t, c;
struct bipartite_graph{
	int V1, V2, *matchL , *matchR;
	vector<int> *L;
	bool *visited;

	bipartite_graph(int MAX_V1, int MAX_V2){
		L = new vector<int>[MAX_V1];
		visited = new bool[MAX_V2];
		matchR = new int[MAX_V2];
		matchL = new int[MAX_V1];
		V1 = MAX_V1, V2 = MAX_V2;
	}

	void clear(int _V1, int _V2){
		V1 = _V1; V2 = _V2;
		for (int i = 0; i < V1; ++i) L[i].clear();
	}

	void add_edge(int v1, int v2){
		L[v1].push_back(v2);
	}

	bool dfs(int u){
		for (int i = L[u].size() - 1; i >= 0; --i){
			int v = L[u][i];
			if (!visited[v]){
				visited[v] = true;
				if (matchR[v] == -1 || dfs(matchR[v])){
					matchR[v] = u;
					matchL[u] = v;
					return true;
				}
			}
		}
		return false;
	}

	int maximum_matching(){
		int ans = 0;
		fill(matchR, matchR + V2, -1);
		fill(matchL, matchL + V1, -1);
		for (int i = 0; i<V1; ++i){
			fill(visited, visited + V2, false);
			ans += dfs(i);
		}
		return ans;
	}
	// Wrong
	V<V<int> > min_path_coverage(){
		V<V<int> > ret;
		for (int i = 0; i < V1; i++){
			if (matchL[i] != -1) continue;
			V<int> path;
			int re = matchR[i], alt = 0;
			while (re != -1){
				path.push_back(re);
				re = (alt % 2) ? matchL[re] : matchR[re];
				alt++;
			}
			ret.push_back(path);
		}
		return ret;
	}
};
int main()
{
	Emsawy();
	int t;
	cin >> t;
	while (t--){
		bipartite_graph g(120, 120);
		cin >> n;
		int u, v;
		for (int i = 0; i < n; i++){
			cin >> u >> v;
			g.add_edge(u, v);
		}
		cout << g.maximum_matching() << endl;
	}
	return 0;
}
