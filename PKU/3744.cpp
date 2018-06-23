#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

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
int n, m, k, w;

const int MAX = 3;
struct matrix {
	int N, M;
	double g[MAX][MAX];
	matrix(int N_, int M_) {
		N = N_, M = M_;
	}
	matrix(int N_, int M_, int v) {
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
					c.g[i][j] = c.g[i][j] + (g[i][k] * 1LL * b.g[k][j]);
				}
			}
		}
		return c;
	}

	matrix pw_matrix(const matrix &b, long long p) {
		if (p == 1) return b;
		matrix me = pw_matrix(b, p / 2LL);
		me = me * me;
		if (p % 2 == 1) me = me * b;
		return me;
	}
};


int main() {

	Emsawy();
	double p;
	while (cin >> n >> p) {
		V<double> v(n+1);
		for (int i = 0; i < n; i++) {
			cin >> v[i+1];
		}
		matrix move(3,3, 0);
		move.g[1][0] = move.g[2][1] = 1;
		move.g[1][2] = 1 - p;
		move.g[2][2] = p;

		matrix base(3, 3, 0);
		base.g[0][2] = 1 - p;

		double ans = 1;
		sort(all(v));
		for (int i = 1; i <= n; i++) {
			ll sub = v[i] - v[i - 1] - 1;
			if (sub < 0) continue;
			if (sub == 0) {
				ans = 0;
				break;
			}
			if (sub == 1) {
				ans *= (1 - p);
				continue;
			}
			matrix ret = base * move.pw_matrix(move, sub - 1);
			ans *= ret.g[0][2];
		}
		cout <<fixed<<setprecision(7) << ans << endl;
	}
	return 0;
}
