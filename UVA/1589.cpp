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
int n, m, k , x , y;
char g[12][12] , ch;
bool vd(int x, int y){
	if (x < 1 || x > 10 || y < 1 || y > 9) return 0;
	return 1;
}
bool H(int x, int y , int l , int r){
	int a, b;
	a = x - 1, b = y;
	if (vd(a, b) && g[a][b] == '\0'){
		if (vd(a - 1, b - 1) && a - 1 == l && b - 1 == r) return 1;
		if (vd(a - 1, b + 1) && a - 1 == l && b + 1 == r) return 1;
	}
	a = x + 1, b = y;
	if (vd(a, b) && g[a][b] == '\0'){
		if (vd(a + 1, b - 1) && a + 1 == l && b - 1 == r) return 1;
		if (vd(a + 1, b + 1) && a + 1 == l && b + 1 == r) return 1;
	}
	a = x, b = y + 1;
	if (vd(a, b) && g[a][b] == '\0'){
		if (vd(a - 1, b + 1) && a - 1 == l && b + 1 == r) return 1;
		if (vd(a + 1, b + 1) && a + 1 == l && b + 1 == r) return 1;
	}
	a = x, b = y - 1;
	if (vd(a, b) && g[a][b] == '\0'){
		if (vd(a - 1, b - 1) && a - 1 == l && b - 1 == r) return 1;
		if (vd(a + 1, b - 1) && a + 1 == l && b - 1 == r) return 1;
	}
	return 0;
}
bool R(int x, int y , int l , int r){
	int u, v;
	bool ok = 0;
	for (int i = 0; i < 4; i++){
		u = x + dx[i], v = y + dy[i];
		while (vd(u, v)){
			if ((u == l && v == r))
				return 1;
			if (g[u][v] != '\0') break;
			u = u + dx[i], v = v + dy[i];
		}
	}
	return 0;
}
bool C(int x, int y , int l , int r){
	bool ok = 0;
	int u, v;
	for (int i = 0; i < 4; i++){
		u = x + dx[i], v = y + dy[i];
		while (vd(u, v)){
			if (g[u][v] != '\0'){
				u = u + dx[i], v = v + dy[i];
				while (vd(u, v)){
					if (u == l && v == r) return 1;
					if (g[u][v] != '\0') u = 20 , v = 20;
					u = u + dx[i], v = v + dy[i];
				}
			}
			else u = u + dx[i], v = v + dy[i];
		}
	}
	return 0;
}
void printT(){
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 9; j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	puts("\n");
}

bool go(int  x, int y){
	bool ret = 0;
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 9; j++){
			if (g[i][j] == 'H')
				ret|= H(i, j, x, y);
			if (g[i][j] == 'C')
				ret |= C(i, j, x, y);
			if (g[i][j] == 'R')
				ret |= R(i, j, x, y);
			if (g[i][j] == 'G')
				ret |= R(i, j, x, y);
		}
	}
	return ret;
}
int main()
{
	Emsawy();
	int u, v;
	while (sf3(n,x,y) && (n + x + y)){
		for (int i = 0; i < n; i++){
			cin >> ch >> u >> v;
			g[u][v] = ch;
		}
		bool ok = 1;
		for (int i = 0; i < 4; i++){
			int l = x + dx[i], r = y + dy[i];
			if (l < 1 || l > 3 || r < 4 || r > 6) continue;
			ch = g[l][r];
			g[l][r] = '\0';
			ok &= go(l, r);
			g[l][r] = ch;
		}
		if (ok == 0) cout << "NO" << endl;
		else cout << "YES" << endl;
		clr(g, 0);
	}
	return 0;
}
