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
const int N = 100 + 2;
int n, m, k, t, c, e, src, sink, u[N*N], v[N*N];
double a[N*N], b[N*N];
int T[N][N], D[N][N];
int path[N][N];

void Path(int sr,int sin, int p){
	if (!path[sr][sin]){
		if (!p) cout << sr << " ";
		cout << sin;
		if (sin != sink)
			cout << " ";
		return;
	}
	Path(sr, path[sr][sin], p);
	Path(path[sr][sin], sin, 1);
}
int main()
{
	Emsawy();
	while (cin >> n >> e){
		fill(T[0], T[0] + N*N, oo);
		fill(D[0], D[0] + N*N, oo);
		clr(path, 0);
		cin >> src >> sink;
		for (int i = 0; i < e; i++){
			cin >> u[i] >> v[i] >> a[i] >> b[i];
			a[i] *= 10;
			b[i] *= 10;
			T[u[i]][v[i]] = min(T[u[i]][v[i]], int(a[i]));
			T[v[i]][u[i]] = min(T[v[i]][u[i]], int(a[i]));
		}
		for (int k = 0; k <= n; k++){
			for (int i = 0; i <= n; i++){
				for (int j = 0; j <= n; j++){
					T[i][j] = min(T[i][j], max(T[i][k], T[k][j]));
				}
			}
		}
		for (int i = 0; i < e; i++){
			if (a[i] > T[src][sink]) continue;
			D[v[i]][u[i]] = min(D[v[i]][u[i]], int(b[i]));
			D[u[i]][v[i]] = min(D[u[i]][v[i]], int(b[i]));
		}
		for (int k = 0; k <= n; k++){
			for (int i = 0; i <= n; i++){
				for (int j = 0; j <= n; j++){
					if (D[i][j] > D[i][k] + D[k][j]){
						D[i][j] = D[i][k] + D[k][j];
						path[i][j] = k;
					}
				}
			}
		}
		V<int>ans;
		pair<int, int> p ;
		p.first = T[src][sink];
		p.second = D[src][sink];
		Path(src, sink,0);
		cout << fixed << setprecision(1);
		cout << endl;
		cout << p.second/10.0 << " " << p.first/10.0 << endl;
	}
	return 0;
}
