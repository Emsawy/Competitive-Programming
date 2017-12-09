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
	ios::sync_with_stdio(false);   // don't use scanf & printf
	cin.tie(0);
	cout.tie(0);
}

#define p00          point(0,0)
#define O            const point & 
#define CD           const double &  
#define EQ(a, b)     (fabs((a) - (b)) <= eps) /* equal to */
#define LT(a, b)     ((a) < (b)-eps) /* less than */
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define clr(v,d)     memset(v, d, sizeof(v))
#define length(a)    (hypot((a).imag(), (a).real()))
#define dp(a,b)	     ((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)	     ((conj(a)*(b)).imag()) // if zero parl
#define pii	         pair<int,int>
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;

typedef long long ll;

const double PI = acos(-1.0);
const double eps = 1e-10;
const ll mod = 1e9 + 7, oo = 1e9;

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

V<V<pii> > adj;
int n, m, k, c;
const int N = 1000 + 2;
ll _00[N][N], _01[N][N], _10[N][N], _11[N][N], g[N][N];

int main()
{
	Emsawy();
	while (cin >> n >> m){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> g[i][j];
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				_00[i][j] = g[i][j];
				_01[i][j] = g[i][m - j + 1];
				_10[i][j] = g[n - i + 1][j];
				_11[i][j] = g[n - i + 1][m - j + 1];
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				_00[i][j] = _00[i][j] + max(_00[i][j - 1], _00[i - 1][j]);
				_01[i][j] = _01[i][j] + max(_01[i][j - 1], _01[i - 1][j]);
				_10[i][j] = _10[i][j] + max(_10[i][j - 1], _10[i - 1][j]);
				_11[i][j] = _11[i][j] + max(_11[i][j - 1], _11[i - 1][j]);
			}
		}

		ll ans = 0;
		for (int i = 2; i < n; i++){
			for (int j = 2; j < m; j++){
				ll __00 = _00[i - 1][j];
				ll __11 = _11[n - (i+1) + 1][m - j + 1];
				ll __01 = _01[i][m - (j+1) + 1];
				ll __10 = _10[n - i + 1][(j-1)];
				ans = max(ans, __00 + __01 + __10 + __11);

				__00 = _00[i][j - 1];
				__11 = _11[n - i + 1][m - (j+1) + 1];
				__01 = _01[i - 1][m - j + 1];
				__10 = _10[n - (i+1) + 1][j];
				ans = max(ans, __00 + __01 + __10 + __11);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
