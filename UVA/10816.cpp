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


float max(float a, float b){ return (a>b) ? a : b; }
float min(float a, float b){ return (a<b) ? a : b; }

const double PI = acos(-1.0);
const double eps = 1e-10;
const ll mod = 1e9 + 7, oo = 1e9;

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

V<V<pii> > adj;
const int N = 100 + 2;
int n, m, k, t, c, e, src, sink, u[N*N], v[N*N];
float a[N*N], b[N*N];
float T[N][N], D[N][N];
int par[N][N];
int main()
{
	Emsawy();
	while (scanf("%d%d",&n ,&e) == 2){
		fill(T[0], T[0] + N*N, oo);
		fill(D[0], D[0] + N*N, oo);
		scanf("%d%d", &src, &sink);
		for (int i = 0; i < e; i++){
			scanf("%d %d %f %f", u + i, v + i, a + i, b + i);
			T[u[i]][v[i]] = min(T[u[i]][v[i]], a[i]);
			T[v[i]][u[i]] = min(T[v[i]][u[i]], a[i]);
		}
		for (int k = 1; k <= n; k++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					T[i][j] = min(T[i][j], max(T[i][k], T[k][j]));
				}
			}
		}
		for (int i = 0; i < e; i++){
			if (a[i] < T[src][sink] + 1e-6){
				D[v[i]][u[i]] = min(D[v[i]][u[i]], b[i]);
				D[u[i]][v[i]] = min(D[u[i]][v[i]], b[i]);
				par[v[i]][u[i]] = v[i];
				par[u[i]][v[i]] = u[i];
			}
		}
		for (int k = 0; k <= n; k++){
			for (int i = 0; i <= n; i++){
				for (int j = 0; j <= n; j++){
					if (D[i][j] > D[i][k] + D[k][j]){
						D[i][j] = D[i][k] + D[k][j];
						par[i][j] = par[k][j];
					}
				}
			}
		}
		pair<double, double> p ;
		p.first = T[src][sink];
		p.second = D[src][sink];
		V<int>ans;
		while (src != sink){
			ans.push_back(sink);
			sink = par[src][sink];
		}
		ans.push_back(sink);
		reverse(all(ans));
		for (int i = 0; i < ans.size(); i++){
			printf("%d", ans[i]);
			if (i + 1 < ans.size()) printf(" ");
		}
		puts("");
		printf("%.1f %.1f\n", p.second, p.first);
	}
	return 0;
}
