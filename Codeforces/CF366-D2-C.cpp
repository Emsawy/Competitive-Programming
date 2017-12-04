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

int n, m, k;
const int N = 100 + 5, ext = N*N * 10 * 2 + 1000;
int a[N], b[N], dp[2][(N*N * 10) * 2 + 2002];

int main()
{
	Emsawy();
	while (cin >> n >> k){
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < (N*N * 10) * 2 + 2002; j++){
				dp[i][j] = -oo;
			}
		}
		dp[0][ext] = 0;
		for (int i = 1; i <= n; i++){
			for (int j = -N * N * 10; j <= N * N * 10; j++){
				dp[i&1][j + ext] = max(dp[i&1][j + ext], dp[(i - 1)&1][j - (a[i] - b[i] * k) + ext] + a[i]);
				dp[i&1][j + ext] = max(dp[i&1][j + ext], dp[(i - 1)&1][j + ext]);
			}
			for (int j = 0; j < (N*N * 10) * 2 + 2002; j++)
				dp[(i & 1) ^ 1][j] = -oo;
		}
		if (dp[n&1][ext] <= 0) dp[n&1][ext] = -1;
		cout << dp[n&1][ext] << endl;
	}
	return 0;
}
