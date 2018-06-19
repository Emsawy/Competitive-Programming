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
const ll N = 18;
int n, m, k, w;

double g[N][N], dp[1<<N];
int _cnt(int mask) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i)) {
			cnt++;
		}
	}
	return cnt;
}
int main() {

	Emsawy(); 
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n;j++){
				cin >> g[i][j];
			}
		}
		clr(dp, 0);
		dp[(1 << n) - 1] = 1;

		for (int mask = (1 << n) - 2; mask > 0; mask--) {
			int cnt = _cnt(mask) + 1;
			for (int i = 0; i < n; i++) {
				if ((mask & (1 << i)) != 0) {
					for (int j = 0; j < n; j++) {
						if ((mask & (1 << j)) == 0) {
							dp[mask] += dp[mask | (1 << j)] * g[i][j] * 2. / (cnt * (cnt - 1) );
						}
					}
				}
			}

		}
		for (int i = 0; i < n; i++)
			cout << dp[1 << i] << " ";
		cout << endl;
	}
	return 0;
}
