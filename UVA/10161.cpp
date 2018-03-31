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
	while (cin >> n) {
		if (n == 0) break;
		ll s = 0, e = ceil(sqrt(n)) + 100;
		while (s < e) {
			ll mid = e - (e - s + 1) / 2;
			if (mid * mid >= n) e = mid;
			else s = mid + 1;
		}
		ll i, j;
		n -= (e - 1) *(e - 1);
		if (e % 2 == 0) {
			if (n <= e)
				j = e, i = n;
			else
				i = e, j = e * 2 - n;
		}
		else {
			if (n <= e)
				i = e, j = n;
			else
				i = e * 2 - n, j = e;
		}
		cout << i << " " << j << endl;
	}

	return 0;
}
