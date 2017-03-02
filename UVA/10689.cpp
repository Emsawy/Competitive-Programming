#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define sz(v) ((int)((v).size()))
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<pair<int, int> > > adj;
const ll mod = 10000, oo = (ll) 1e9;
int n, m, k, a, b;
const int MAX = 2;
/*
......
*/
struct matrix{
	int N, M, g[MAX][MAX];
	matrix(int N_, int M_){
		N = N_, M = M_;
	}
	matrix(int N_, int M_, int v){
		N = N_, M = M_;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				g[i][j] = v;

	}
	matrix operator * (const matrix &b) const{
		matrix c(N, b.M);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < b.M; j++){
				c.g[i][j] = 0;
				for (int k = 0; k < N; k++){
					c.g[i][j] = (c.g[i][j] + (g[i][k] * 1LL * b.g[k][j])) % mod;
				}
			}
		}
		return c;
	}

	matrix pw_matrix(const matrix &b, long long p){
		if (p == 1) return b;
		if (p == 0) {
			matrix w7da(2, 2, 0);
			w7da.g[0][0] = w7da.g[1][1] = 1;
			return w7da;
		}
		matrix me = pw_matrix(b, p / 2LL);
		me = me * me;
		if (p % 2 == 1) me = me * b;
		return me;
	}
};


int main()
{
	Emsawy();
	int t;
	cin >> t;
	while (t--){
		sf2(a, b);
		sf2(n, m);
		int ans = 0;
		matrix mat(2, 2, 1);
		mat.g[1][1] = 0;
		if (n == 0) ans = a;
		else if (n > 0){
			mat = mat.pw_matrix(mat, n - 1);
			ans = (mat.g[0][0] * b + mat.g[0][1] * a) % mod;
		}
		if (m == 1) ans %= 10;
		if (m == 2) ans %= 100;
		if (m == 3) ans %= 1000;
		if (m == 4) ans %= 10000;
		printf("%d\n", ans);
	}
	return 0;
} 
