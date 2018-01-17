#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
struct state
{
	int w, i, j;
}st[100005];
const ll N = 1010;
int n, m, k, w, q;
bool g[N][N], fl[N];
int sum[N];
int go(int w, int i, int j, int &cur){
	if (w == 1){
		if (fl[i] == 0 && g[i][j] == 0) {
			g[i][j] = 1, sum[i]++, cur++;
			return 0;
		}
		else if (fl[i] == 1 && g[i][j] == 1){
			g[i][j] = 0, sum[i]++, cur++;
			return 1;
		}
	}
	else if (w == 2){
		if (fl[i] == 0 && g[i][j] == 1){
			g[i][j] = 0, sum[i]--, cur--;
			return 2;
		}
		else if (fl[i] == 1 && g[i][j] == 0){
			g[i][j] = 1, sum[i]--, cur--;
			return 3;
		}
	}
	else if (w == 3){
		fl[i] = !fl[i], cur -= sum[i], sum[i] = m - sum[i], cur += sum[i];
		return 4;
	}
	return 5;
}

void un_go(int w, int i, int j, int &cur){
	if (w == 0) g[i][j] = 0, sum[i]--, cur--;
	else if (w == 1) g[i][j] = 1, sum[i]--, cur--;
	else if (w == 2) g[i][j] = 1, sum[i]++, cur++;
	else if (w == 3) g[i][j] = 0, sum[i]++, cur++;
	else if (w == 4) fl[i] = !fl[i], cur -= sum[i], sum[i] = m - sum[i], cur += sum[i];
}
int ans[100005];
void solve(int start, int cur, bool ok){
	if (start > q) return;
	if (ok && st[start].w == 4) return;
	int ret = go(st[start].w, st[start].i, st[start].j, cur);
	ans[start] = cur;
	for (int j = 0; j < adj[start].size(); j++)
		solve(adj[start][j], cur, 0);
	solve(start + 1, cur, 1);
	un_go(ret, st[start].i, st[start].j, cur);
}
int main() {

	Emsawy();
	while (cin >> n >> m >> q){
		adj.resize(q + 1);
		for (int k = 1; k <= q; k++){
			cin >> st[k].w;
			if (st[k].w == 1 || st[k].w == 2){
				cin >> st[k].i >> st[k].j;
			}
			else if (st[k].w == 3){
				cin >> st[k].i;
			}
			else {
				cin >> st[k].i;
				adj[st[k].i].push_back(k);
			}
		}
		solve(0, 0, 0);
		for (int i = 1; i <= q; i++)
			cout << ans[i] << endl;
	}
	return 0;
}
