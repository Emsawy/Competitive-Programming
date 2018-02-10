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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
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
const ll N = 4e2 + 5;
int n, m, k, w, h;

int rt[N][N], dn[N][N], dnLeft[N][N],dnRight[N][N];
char g[N][N];

bool good(int x, int y){
	if (x <= 0 || x > n || y <= 0 || y > m || g[x][y] == '1') return 0;
	return 1;
}
bool L(int x0, int y0, int x1, int y1){
	if (dnLeft[x1][y1] - dnLeft[x0 - 1][y0 + 1] <= 0) return 1;
	return 0;
}
bool R(int x0, int y0, int x1, int y1){
	if (dnRight[x1][y1] - dnRight[x0 - 1][y0 - 1] <= 0) return 1;
	return 0;
}
ll solve(int x,int y){
	if (g[x][y] == '1') return 0;
	ll ans = 0;
	for (int i = 1; good(x, y - i) && good(x + i, y); i++){
		if (R(x, y - i, x + i, y)) ans++;
	}
	for (int i = 1; good(x, y + i) && good(x + i, y); i++){
		if (L(x, y + i, x + i, y)) ans++;
	}
	for (int i = 1; good(x, y - i) && good(x - i, y); i++){
		if (L(x - i, y, x, y - i)) ans++;
	}
	for (int i = 1; good(x, y + i) && good(x - i, y); i++){
		if (R(x - i, y, x, y + i)) ans++;
	}

	for (int i = 1; good(x - i, y - i) && good(x + i, y - i) ; i++){
		if (dn[x + i][y - i] - dn[x - i - 1][y - i] <= 0) ans++;
	}
	for (int i = 1; good(x - i, y + i) && good(x + i, y + i); i++){
		if (dn[x + i][y + i] - dn[x - i - 1][y + i] <= 0) ans++;
	}

	for (int i = 1; good(x - i, y - i) && good(x - i, y + i); i++){
		if (rt[x - i][y + i] - rt[x - i][y - i - 1] <= 0) ans++;
	}
	for (int i = 1; good(x + i, y - i) && good(x + i, y + i); i++){
		if (rt[x + i][y + i] - rt[x + i][y - i - 1] <= 0) ans++;
	}


	return ans;
}
int main() {

	Emsawy();
	while (cin >> n >> m){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin>> g[i][j];
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				rt[i][j] = rt[i][j - 1] + (g[i][j] == '1');
				dn[i][j] = dn[i - 1][j] + (g[i][j] == '1');
				dnRight[i][j] = dnRight[i - 1][j - 1] + (g[i][j] == '1');
				dnLeft[i][j] += dnLeft[i - 1][j + 1] + (g[i][j] == '1');
			}
		}
		ll ans = 0;
		for (int i = 1; i <=  n; i++){
			for (int j = 1; j <= m; j++){
				ans += solve(i, j);
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
