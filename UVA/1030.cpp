
/*
- first i fill all the empty dimension with '.' .
- canceling all the unvalid positions(conflected postions)
*/


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
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
int n, m, k;
void get(int k, int i, int j, int di , int &x, int &y, int &z){
	if (k == 0) x = n - i - 1, y = j, z = di;
	else if (k == 1) x = n - i - 1, y = di, z = n - j - 1;
	else if (k == 2) x = n - i - 1, y = n - j - 1, z = n - di - 1;
	else if (k == 3) x = n - i - 1, y = n - di - 1, z = j;
	else if (k == 4) x = n - di - 1, y = j, z = n - i - 1;
	else if (k == 5) x = di, y = j, z = i;
}
int main()
{
	Emsawy();
	int is = 0;
	while (cin >> n){
		if (n == 0) break;
		string f[6][11];
		for (int j = 0; j < n; j++)
			for (int i = 0; i < 6; i++)
				cin >> f[i][j];
		char mrk[11][11][11];
		clr(mrk, '?');
		for (int k = 0; k < 6; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (f[k][i][j] != '.') continue;
					int x = 0, y = 0, z = 0;
					for (int di = 0; di < n; di++){
						get(k, i, j, di, x, y, z);
						mrk[x][y][z] = '.';
					}
				}
			}
		}
		bool ok = 1;
		while (ok){
			ok = 0;
			for (int k = 0; k < 6; k++){
				for (int i = 0; i < n; i++){
					for (int j = 0; j < n; j++){
						if (f[k][i][j] == '.') continue;
						int x = 0, y = 0, z = 0;
						for (int di = 0; di < n; di++){
							get(k, i, j, di, x, y, z);
							if (mrk[x][y][z] == '.') continue;
							if (mrk[x][y][z] == '?'){
								mrk[x][y][z] = f[k][i][j];
								ok = 1;
								break;
							}
							if (mrk[x][y][z] == f[k][i][j]){
								break;
							}
							else{
								mrk[x][y][z] = '.';
								ok = 1;
							}
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					ans += mrk[i][j][k] != '.';
				}
			}
		}
		printf("Maximum weight: %d gram(s)\n", ans);
	}
	return 0;
}
