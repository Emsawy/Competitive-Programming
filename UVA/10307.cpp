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
const ll mod = 1e9 + 7, oo = 1e9;
int n, m , dis[55][55] , idx[55][55];
char g[55][55];
void ShortP(int I, int J){
	clr(dis, -1);
	queue<pair<int, pair<int, int> > > q;
	q.push(MP(0, MP(I, J)));
	dis[I][J] = 0;
	while (!q.empty()){
		pair<int, int> p = q.front().second;
		int vl = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++){
			int x = dx[i] + p.first, y = dy[i] + p.second;
			if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#' || dis[x][y] != -1)
				continue;
			dis[x][y] = vl + 1;
			q.push(MP(vl + 1, MP(x, y)));
		}
	}
}
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
int main()
{
	Emsawy();
	int T;
	cin >> T;
	while (T--){
		cin >> m >> n;
		V<pair<int, int> > nodes;
		cin.ignore();
		string s;
		for (int i = 0; i < n; i++){
			getline(cin, s);
			for (int j = 0; j < s.size(); j++){
				g[i][j] = s[j];
				if (g[i][j] == 'A' || g[i][j] == 'S')
					nodes.push_back(MP(i, j));
			}
		}
		int node = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				idx[i][j] = node++;

		priority_queue<pair<int, pair<int, int > >, V<pair<int, pair<int, int > > >, greater<pair<int, pair<int, int > > >  >pq;
		for (int i = 0; i < nodes.size(); i++){
			ShortP(nodes[i].first, nodes[i].second);
			for (int q = 0; q < n; q++){
				for (int q1 = 0; q1 < m; q1++){
					if (g[q][q1] != 'A' && g[q][q1] != 'S') continue;
					pq.push(MP(dis[q][q1], MP(idx[nodes[i].first][nodes[i].second], idx[q][q1])));
				}
			}
		}
		int ans = 0;
		UnionFind tr(n * m);
		while (!pq.empty()){
			pair<int, int> p = pq.top().second;
			int vl = pq.top().first;
			pq.pop();
			if (tr.union_set(p.first, p.second))
				ans += vl;
		}
		printf("%d\n", ans);
	}
	return 0;
}
