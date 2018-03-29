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
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		double ans = n * 2 - 2 + 2 + ((n - 1) * 2 - 1) - 1;
		for (int i = 1;i < n;i++) {
			ans += sqrt((i - 1) * (i - 1) * 2);
		}
		for (int i = n - 2; i >= 1 ;i--) {
			ans += sqrt((i - 1) * (i - 1) * 2);
		}
		cout << fixed << setprecision(5) << ans << endl;
	}

	return 0;
}
