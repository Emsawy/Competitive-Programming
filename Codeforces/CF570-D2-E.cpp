#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
const ll N = 500 + 5;
int n, m;
char g[N][N];

int II(int i) {
	return n - i + 1;
}
int JJ(int i, int j, int I) {
	return m - ((j + i) - I) + 1;
}
bool ok(int i,int j,int I) {
	int ie = II(I), je = JJ(i, j, I);
	if (g[i][j] == g[ie][je]) return 1;
	return 0;
}
V<V<int> > dp[N];
int go(int i, int j, int I) {
	int ie = II(I), je = JJ(i, j, I);
	if ((ie - i) < 0 || (je - j) < 0) return 0;
	if ((ie - i) + (je - j) <= 1)
		return 1;
	if (dp[i][j][I] != -1) return dp[i][j][I];
	dp[i][j][I] = 0;

	if (ok(i + 1, j, I + 1))
		dp[i][j][I] = (dp[i][j][I] + go(i + 1, j, I + 1)) % mod;
	
	if (ok(i + 1, j, I))
		dp[i][j][I] = (dp[i][j][I] + go(i + 1, j, I)) % mod;

	if (ok(i, j + 1, I + 1))
		dp[i][j][I] = (dp[i][j][I] + go(i, j + 1, I + 1)) % mod;

	if (ok(i, j + 1, I))
		dp[i][j][I] = (dp[i][j][I] + go(i, j + 1, I)) % mod;

	return dp[i][j][I];
}

int main() {

	Emsawy();
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> g[i][j];
			}
		}
		if (g[1][1] != g[n][m]) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < N; i++) {
			dp[i] = V<V<int> >(N - i + 1, V<int>(N - i + 1, -1));
		}
		cout << go(1, 1, 1) << endl;

		/*dp[1][1][1] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int I = 1; I <= n; I++) {
					int ie = II(I), je = JJ(i, j, I);
					if ((ie - i) < 0 || (je - j) < 0) continue;
					if ((ie - i) + (je - j) == 0) {
						dp[i][j][I]++;
						continue;
					}
					if (ok(i - 1, j, I - 1))
						dp[i][j][I] = (dp[i][j][I] + dp[i - 1][j][I - 1]) % mod;

					if (ok(i - 1, j, I))
						dp[i][j][I] = (dp[i][j][I] + dp[i - 1][j][I]) % mod;

					if (ok(i, j - 1, I - 1))
						dp[i][j][I] = (dp[i][j][I] + dp[i][j - 1][I - 1]) % mod;

					if (ok(i, j - 1, I))
						dp[i][j][I] = (dp[i][j][I] + dp[i][j - 1][I]) % mod;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int I = 1; I <= n; I++) {
					int ie = II(I), je = JJ(i, j, I);
					if ((ie - i) < 0 || (je - j) < 0) continue;
					if ((ie - i) + (je - j) <= 1) {
						ans = (ans + dp[i][j][I]) % mod;
					}
				}
			}
		}
		cout << ans << endl;*/
	}
	return 0;
}
