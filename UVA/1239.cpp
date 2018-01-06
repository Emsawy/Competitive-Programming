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

V<V<pair<int,int> > > adj;
const ll N = 1000 + 5;
int n, m, k, w, h;
int dp[N][N];
char s[N];
int main() {

	Emsawy();
	int T;
	cin >> T;
	while (T--){
		scanf("%s %d", s, &k);
		n = strlen(s);
		fill(dp[0], dp[0] + N*N, oo);
		for (int i = 0; i < n; i++)
			dp[i][i] = 0;
		int ans = 1;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j + i < n; j++){
				int l = j, r = i + j;
				if (r - l == 1) dp[l + 1][r - 1] = 0;
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + (s[l] != s[r]));
				if (k - dp[l][r] >= 0){
					ans = i + 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
