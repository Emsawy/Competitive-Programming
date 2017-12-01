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

int n, m, k, t, c;
double x;
const int N = 50 + 5;
int cmpv[N][N], cur = 0, cmpn;
char in[N][N];

void cmp(int i, int j){
	if (cmpv[i][j] == cur) return;
	cmpv[i][j] = cur;
	for (int k = 0; k < 4; k++){
		int x = i + dx[k], y = j + dy[k];
		if (x < 0 || x >= n || y < 0 || y >= m) continue;
		if (in[i][j] == in[x][y])
			cmp(x, y);
	}
	return ;
}

int main()
{
	Emsawy();
	while (cin >> n >> m){
		int ok = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> in[i][j];
				ok += (in[i][j] == '#');
			}
		}
		cur++;
		cmpn = 0;
		for (int a = 0; a < n; a++){
			for (int b = 0; b < m; b++){
				if (cmpv[a][b] == cur) continue;
				if (in[a][b] != '#') continue;
				cmp(a, b);
				cmpn++;
			}
		}
		if (ok < 3 || cmpn > 1){
			cout << -1 << endl;
			continue;
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (in[i][j] != '#')continue;
				in[i][j] = '.';
				cur++;
				cmpn = 0;
				for (int a = 0; a < n; a++){
					for (int b = 0; b < m; b++){
						if (cmpv[a][b] == cur) continue;
						if (in[a][b] != '#') continue;
						cmp(a, b);
						cmpn++;
					}
				}
				if (cmpn >= 2){
					ans = 1;
					break;
				}
				in[i][j] = '#';
			}
		}
		cout << (ans ? 1 : 2) << endl;
	}
	return 0;
}
