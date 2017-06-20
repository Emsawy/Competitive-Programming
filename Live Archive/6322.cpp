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

V<V<int> > alph(26);
V<V<pii> > adj;
int n, m, k, t, c;
struct bipartite_graph{
	int V1, V2,cur, matchL[100] , matchR[100];
	int visited[100];
	bool bol[100];
	V<vector<char> > L;


	bipartite_graph(int MAX_V1, int MAX_V2){
		L.resize(MAX_V1);
		V1 = MAX_V1, V2 = MAX_V2;
		clr(visited, 0);
		clr(bol, 0);
		cur = 0;
	}

	void clear(int _V1, int _V2){
		V1 = _V1; V2 = _V2;
		for (int i = 0; i < V1; ++i) L[i].clear();
	}

	void add_edge(int v1, char v2){
		L[v1].push_back(v2);
	}

	bool dfs(int u){
		for (int i = 0; i < L[u].size();i++){
			char v = L[u][i];
			for (int j = 0; j < alph[v - 'a'].size(); j++){
				int ch = alph[v - 'a'][j];
				if (bol[ch]) continue;
				if (visited[ch] != cur){
					visited[ch] = cur;
					if (matchR[ch] == -1 || dfs(matchR[ch])){
						matchR[ch] = u;
						matchL[u] = ch;
						bol[u] = 1;
						return true;
					}
				}
			}
		}
		for (int i = 0; i < L[u].size(); i++){
			char v = L[u][i];
			for (int j = 0; j < alph[v - 'a'].size(); j++){
				int ch = alph[v - 'a'][j];
				if (!bol[ch]) continue;
				if (visited[ch] != cur){
					visited[ch] = cur;
					if (matchR[ch] == -1 || dfs(matchR[ch])){
						matchR[ch] = u;
						matchL[u] = ch;
						bol[u] = 1;
						return true;
					}
				}
			}
		}
		return false;
	}

	int maximum_matching(){
		int ans = 0;
		fill(matchR, matchR + V2, -1);
		fill(matchL, matchL + V1, -1);
		for (int i = 0; i < V1; ++i){
			cur++;
			ans += dfs(i);
		}
		
		return ans;
	}
	// Wrong
	V<V<char> > min_path_coverage(){
		V<V<char> > ret;
		for (int i = 0; i < V1; i++){
			if (matchL[i] != -1) continue;
			V<char> path;
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
	bipartite_graph g(100, 100);
	while (t--){
		alph.resize(26);
		string s , po[100];
		cin >> s;
		g.clear(s.size(), s.size());
		for (int i = 0; i < s.size(); i++){
			alph[s[i] - 'a'].push_back(i);
		}
		for (int i = 0; i < s.size(); i++){
			cin >> po[i];
			sort(all(po[i]));
			for (int j = 0; j < po[i].size(); j++){
				g.add_edge(i, po[i][j]);
			}
		}
		int ret = g.maximum_matching();
		if (ret != s.size()) cout << "NO SOLUTION";
		else for (int i = 0; i < s.size(); i++)
			cout << s[g.matchR[i]];
		puts("");
		alph.clear();
	}
	return 0;
}

/*

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
	int V1, V2, cur, matchL[100], matchR[100];
	int visited[100], L[100][100];

	bipartite_graph(int MAX_V1, int MAX_V2){
		V1 = MAX_V1, V2 = MAX_V2;
		clr(visited, 0);
		cur = 0;
	}

	void clear(int _V1, int _V2){
		V1 = _V1; V2 = _V2;
		for (int i = 0; i < V1; ++i)
			for (int j = 0; j < V2; j++)
				L[i][j] = 0;
	}

	void add_edge(int v1, int v2){
		L[v1][v2] = 1;
	}
	void remove_edge(int v1, int v2){
		L[v1][v2] = 0;
	}

	bool dfs(int u){
		for (int i = 0; i < V1; i++){
			int v = i;
			if (!L[u][v] || visited[v] == cur) continue;
			visited[v] = cur;
			if (matchR[v] == -1 || dfs(matchR[v])){
				matchR[v] = u;
				matchL[u] = v;
				return true;
			}
		}
		return false;
	}

	int maximum_matching(){
		int ans = 0;
		fill(matchR, matchR + V2, -1);
		fill(matchL, matchL + V1, -1);
		for (int i = 0; i < V1; ++i){
			cur++;
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

void Add(V<set<int> > &alp, bipartite_graph &g , string po, int fr){
	for (int j = 0; j < po.size(); j++){
		for (auto it : alp[po[j] - 'a']){
			g.add_edge(fr, it);
		}
	}
}


void Remove(V<set<int> > &alp, bipartite_graph &g, string po, int fr){
	for (int j = 0; j < po.size(); j++){
		for (auto it : alp[po[j] - 'a']){
			g.remove_edge(fr, it);
		}
	}
}

void RemoveNode(V<set<int> > &alp, bipartite_graph &g , char ch , int po){
	alp[ch - 'a'].erase(po);
	for (int i = 0; i < g.V1; i++){
		g.remove_edge(i , po);
	}
}
int main()
{
	Emsawy();
	int t;
	cin >> t;
	bipartite_graph g(100, 100);
	while (t--){
		string s, po[100];
		cin >> s;
		V<set<int> >alp(26);
		g.clear(s.size(), s.size());
		for (int i = 0; i < s.size(); i++) alp[s[i] - 'a'].insert(i);
		for (int i = 0; i < s.size(); i++){
			cin >> po[i];
			Add(alp, g, po[i], i);
		}
		string ans = "";
		for (int i = 0; i < s.size(); i++){
			Remove(alp, g, po[i], i);
			string me = po[i];
			for (int j = 0; j < me.size(); j++){
				string now = "";
				now += me[j];
				po[i] = now;
				Add(alp, g, po[i], i);
				int ret = g.maximum_matching();
				if (ret == s.size() - i){
					RemoveNode(alp, g, s[g.matchL[i]], g.matchL[i]);
					ans += me[j];
					break;
				}
				Remove(alp, g, po[i], i);
			}
		}
		if (ans.size() != s.size()) cout << "NO SOLUTION" << endl;
		else cout << ans << endl;

	}
	return 0;
}
*/
