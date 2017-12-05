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
const int mod = 1e9 + 7, oo = 1e9;

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

int n, m, k, t, c;
V<V<int> > adj, tree;
const int N = 1500 + 5;
char g[N][N];
pair<int,int> vs[N][N];
int gx(int x){
	return ((x%n) + n) % n;
}
int gy(int y){
	return ((y%m) + m) % m;
}
bool go(int i, int j){
	if (g[gx(i)][gy(j)] == '#') return 0;
	if (vs[gx(i)][gy(j)] != MP(-oo, -oo))
		return vs[gx(i)][gy(j)] != MP(i, j);
	vs[gx(i)][gy(j)] = MP(i, j);
	for (int k = 0; k < 4; k++){
		int x = i + dx[k], y = dy[k] + j;
		if(go(x, y)) return 1;
	}
	return 0;
}

int main()
{
	Emsawy();
	while (cin >> n >> m){
		pair<int, int> s;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> g[i][j];
				if (g[i][j] == 'S')
					s = { i, j };
			}
		}
		fill(vs[0], vs[0] + N*N, MP(-oo, -oo));
		if (go(s.first,s.second)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
