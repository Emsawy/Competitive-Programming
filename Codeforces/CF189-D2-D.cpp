#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

const ll N = 70;
int n, m, k, w, r;
int in[N][N][N], path[N][N];
int dp[N][N][N];
int go(int i, int j, int cars){
	if (cars + 1 <= 0) return dp[i][j][cars] = ( i == j ? 0 : oo);
	int &ret = dp[i][j][cars];
	if (ret != oo + 1) return ret;
	ret = oo;
	for (int to = 0; to < n; to++) if (to != i){
		ret = min(ret, go(to, j, cars - 1) + path[i][to]);
	}
	return ret;
}

int main() {

	Emsawy();
	while (cin >> n >> m >> r){
		for (int k = 0; k < m; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					scanf("%d", &in[k][i][j]);
				}
			}
			for (int sp = 0; sp < n; sp++){
				for (int i = 0; i < n; i++){
					for (int j = 0; j < n; j++){
						in[k][i][j] = min(in[k][i][j], in[k][i][sp] + in[k][sp][j]);
					}
				}
			}
		}
		fill(dp[0][0], dp[0][0] + N * N * N, oo + 1);
		fill(path[0], path[0] + N * N, oo);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < m; k++){
					path[i][j] = min(path[i][j], in[k][i][j]);
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) if (i != j){
				for (int k = 0; k < n; k++){
					go(i, j, k);
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)if(i != j){
				for (int k = 1; k < n; k++){
					dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1]);
				}
			}
		}
		int src, sink, dont;
		for (int i = 0; i < r; i++){
			scanf("%d%d%d", &src, &sink, &dont);
			printf("%d\n", dp[src - 1][sink - 1][min(n - 1, dont)]);
		}
	}
	return 0;
}
