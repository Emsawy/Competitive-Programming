#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

typedef long long ll;
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
const ll N = ( 1 << 7 ) + 10;
ll n, m, k, w;
double g[N][N];
double dp[N * 5][N];

void build(int p, int s, int e) {

	if (s == e) {
		dp[p][s] = 1;
		return;
	}
	
	int m = (s + e) / 2;
	build(p << 1, s, m);
	build(p << 1 | 1, m + 1, e);

	for (int i = s; i <= m; i++) {
		for (int j = m + 1; j <= e; j++) {
			dp[p][i] += dp[p << 1][i] * dp[p << 1 | 1][j] * g[i][j];
			dp[p][j] += dp[p << 1][i] * dp[p << 1 | 1][j] * g[j][i];
		}
	}
}

int main() {

	Emsawy();
	while (cin >> n) {
		if (n < 0) break;
		n = (1 << n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> g[i][j];
			}
		}
		clr(dp, 0);
		build(1, 0, n - 1);
		double mx = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (mx < dp[1][i]) {
				mx = dp[1][i];
				ans = i;
			}
		}
		cout << ans + 1 << endl;
	}
	return 0;
}
