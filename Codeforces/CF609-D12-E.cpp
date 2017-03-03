#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

/*
- get the MST
- for each qary if the i-th edges i used before , then the answer i summations of MST edges.
- else if the i-th edges i didn't used befor i get the lca and find the minimum edges in the cycle and substract it from MST summations and add the new one 
*/

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
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9 + 100;
int const si = 200005;
int n, m, x, y, z, k, T[si], P[si][20][2], L[si], W[si];
bool MST[si];
void calT(int nd, int lv = 0, int lst = -1){
	T[nd] = lst;
	L[nd] = lv;
	for (int i = 0; i < adj[nd].size(); i++){
		pair<int, int> child = adj[nd][i];
		if (child.first == lst) continue;
		W[child.first] = child.second;
		calT(child.first, lv + 1, nd);
	}
}
void buildLCA(){
	clr(P, -1);
	for (int i = 0; i < n; i++){
		P[i][0][0] = T[i];
		P[i][0][1] = W[i];
	}
	for (int j = 1; (1 << j) <= n; j++){
		for (int i = 0; i < n; i++){
			if (P[i][j - 1][0] != -1){
				if (P[P[i][j - 1][0]][j - 1][1] > P[i][j - 1][1])
					P[i][j][1] = P[P[i][j - 1][0]][j - 1][1];
				else
					P[i][j][1] = P[i][j - 1][1];
				P[i][j][0] = P[P[i][j - 1][0]][j - 1][0];
			}
		}
	}
}

int get(int p, int q){
	int ret = 0;
	if (L[p] < L[q]) swap(q, p);
	int HI = log2(L[p]);
	for (int i = HI; i >= 0; i--){
		if (L[p] - (1 << i) >= L[q]){
			ret = max(ret, P[p][i][1]);
			p = P[p][i][0];
		}
	}
	if (p == q) return ret;
	for (int i = HI; i >= 0; i--){
		if (P[p][i][0] != -1 && P[p][i][0] != P[q][i][0]){
			ret = max(ret, P[p][i][1]);
			ret = max(ret, P[q][i][1]);
			p = P[p][i][0], q = P[q][i][0];
		}
	}
	ret = max(ret, P[p][0][1]);
	ret = max(ret, P[q][0][1]);
	return ret;
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
	while (cin >> n >> m){
		adj.clear(); adj.resize(n);
		V<int > u(m), v(m), w(m);
		priority_queue<pair<int, int>, V<pair<int, int> >, greater<pair<int, int> > > pq;
		for (int i = 0; i < m; i++){
			sf3(u[i], v[i], w[i]);
			u[i]--, v[i]--;
			pq.push(MP(w[i], i));
		}
		//V<int>MST;
		ll sum = 0, node = 0;
		UnionFind f(n);
		while (!pq.empty()){
			pair<int, int>p = pq.top();
			pq.pop();
			if (f.union_set(u[p.second], v[p.second])){
				//	MST.push_back(p.second);
				node = u[p.second];
				adj[u[p.second]].push_back(MP(v[p.second], w[p.second]));
				adj[v[p.second]].push_back(MP(u[p.second], w[p.second]));
				sum += p.first;
				MST[p.second] = 1;
			}
		}
		calT(node, 0, -1);
		buildLCA();
		for (int i = 0; i < m; i++){
			if (MST[i]){
				printf("%I64d\n", sum);
				continue;
			}
			int remov = get(u[i], v[i]);
			printf("%I64d\n", sum - remov + w[i]);
		}
	}
	return 0;
}
