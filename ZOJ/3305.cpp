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
const ll N = 100000 + 5;
int n, m, k, w;

int dp[(1 << 17)], A[(1 << 17)];

int main() {

	Emsawy();
	while (cin >> n >> m) {
		clr(A, 0);
		for (int i = 0; i < m; i++) {
			scanf("%d", &k);
			while (k--) {
				scanf("%d", &w);
				A[i] |= (1 << (w - 1));
			}
		}
		fill(dp, dp + (1 << 17), -oo);
		for (int i = 0; i < m; i++)
			dp[A[i]] = 1;

		int to = (1 << n);
		for (int i = 0; i < to; i++) {
			for (int j = i; j > 0; j = (j-1) & i) { 
				dp[i] = max(dp[i], dp[(i ^ j)] + dp[~(i ^ j) & i]);
			}
		}
		int ans = 0;
		for (int i = to; i >= 0; i--) {
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
