
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
#define all(v)	     ((v).begin()), ((v).end())
#define clr(v,d)     memset(v, d, sizeof(v))
#define V	         vector

const ll N = (1 << 18);
ll n, m, k, c, a, w;
ll g[N];

int main() {

	Emsawy();
	int t, tst = 0;
	cin >> t;
	while (t--) {
		cout << "Case " << ++tst << ": ";
		cin >> k >> c >> n >> a;
		g[0]= a;
		for (int i = 1;i<n;i++) {
			g[i]= (g[i - 1] * k + c) % mod;
		}
		sort(g, g + n);
		for (int i = 1;i < n;i++)
			g[i] += g[i - 1];

		ll ans = 0;
		for (int i = 0;i < n;i++) {
			ans += abs(g[i] - (i + 1) * (g[i] - (i <= 0 ? 0 : g[i - 1])));
			ans += (g[n - 1] - g[i]) - (n - i - 1) * (g[i] - (i <= 0 ? 0 : g[i - 1]));
		}
		cout << ans / 2 << endl;
	}

	return 0;
}
