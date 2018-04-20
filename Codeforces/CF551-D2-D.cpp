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
const ll N = 100000 + 5;
ll n, m, l, k, w;

const int MAX = 3;
struct matrix {
	ll N, M, g[MAX][MAX];
	matrix(int N_, int M_) {
		N = N_, M = M_;
	}
	matrix(int N_, int M_, ll v) {
		N = N_, M = M_;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				g[i][j] = v;

	}
	matrix operator * (const matrix &b) const {
		matrix c(N, b.M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < b.M; j++) {
				c.g[i][j] = 0;
				for (int k = 0; k < N; k++) {
					c.g[i][j] = (c.g[i][j] + (g[i][k] * 1LL * b.g[k][j])) % mod;
				}
			}
		}
		return c;
	}

	matrix pw_matrix(long long p) {
		if (p == 1) return *this;
		matrix me = pw_matrix(p / 2LL);
		me = me * me;
		if (p % 2 == 1) me = me * (*this);
		return me;
	}
};

matrix base(3, 3, 0), po(3, 3, 0);
long long Fibonacci(ll x) {
	if (x <= 0) return 0;
	if (x <= 3) return x;
	
	base.g[0][0] = 1;
	base.g[0][1] = 2;
	base.g[0][2] = 3;

	po.g[1][0] = 1;
	po.g[1][2] = 1;
	po.g[2][1] = 1;
	po.g[2][2] = 1;

	x -= 3;

	matrix ret = base * po.pw_matrix(x);
	return ret.g[0][2];
}
ll pw(ll a, ll p) {
	if (p == 1) return a;
	if (p == 0) return 1;
	ll ret = pw(a, p / 2) % mod;
	ret = (ret * ret) % mod;
	if (p % 2 == 1) ret = (ret * a) % mod;
	return ret;
}

int main() {

	Emsawy();
	while (cin >> n >> k >> l >> mod) {
		int to = min(l, 63LL);
		if ((1ull << to) <= k) {
			cout << 0 << endl;
			continue;
		}

		ll zero = Fibonacci(n + 1) % mod;
		ll one = ((pw(2, n) - zero + mod) % mod);
		ll ans = 1;
		bitset<64> bt(k);
		for (int i = 0; i < l ; i++) {
			if (bt[i]) {
				ans = (ans * one) % mod;
			}
			else {
				ans = (ans * zero) % mod;
			}
		}
		cout << ans % mod << endl;
	}
	return 0;
}
