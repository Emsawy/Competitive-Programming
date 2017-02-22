#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>

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
V<V<pair<int, int> > > adj;
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
int n, m, k , src , dest;

struct edge {
	int from, to, w;
	edge(){};
	edge(int from, int to, int w) : from(from), to(to), w(w) {}
	bool operator < (const edge & e) const {
		return w < e.w;
	}
};
struct UnionFind{
	vector<int> rank, F;
	int comp;
	UnionFind(int n){
		rank = vector<int>(n);
		F = vector<int>(n);
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
V<edge>g;
int main()
{
	Emsawy();
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		g.clear();
		g.resize(m);
		for (int i = 0; i < m; i++)
			sf3(g[i].from, g[i].to, g[i].w) , g[i].from -- , g[i].to --;
		sf2(src, dest);
		src--, dest--;
		sort(all(g));
		int mn = oo;
		for (int i = 0; i < m; i++){
			UnionFind f(n);
			for (int j = i; j < m; j++){
				f.union_set(g[j].from, g[j].to);
				if (f.find_set(src) == f.find_set(dest)){
					mn = min(mn, g[j].w - g[i].w);
					break; 
				}
			}
		}
		if (mn == oo) mn = -1;
		cout << mn << endl;
	}
	return 0;
}
