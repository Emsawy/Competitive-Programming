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

#define sz(v)			((int)((v).size()))
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define clr(v,d)		memset(v, d, sizeof(v))
#define sf(x)			scanf("%d", &x)
#define sf2(x,y)		scanf("%d %d", &x, &y)
#define sf3(x,y,z)		scanf("%d %d %d", &x, &y, &z)
#define sfll(x)			scanf("%I64d", &x)
#define sfll2(x,y)		scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)		scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) <= EPS)
#define rotate0(p,ang)		((p)*exp(Point(0,ang)))
#define rotateA(p,ang,about)	(rotate0(vec(about,p),ang)+about)
#define reflect0(v,m)		(conj((v)/(m))*(m))
#define normalize(a)		(a)/length(a)
#define lengthSqr(p)		dp(p,p)
#define pii			pair<int,int>
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()

typedef complex<double> 	point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k, t, c, g[20][20];
int dps[(1 << 18)][20];
int dpe[(1 << 18)][20];

int countbits(int mask){
	int cnt = 0;
	while (mask > 0){
		if ((mask & 1)) cnt++;
		mask >>= 1;
	}
	return cnt;
}
bool is(int msk, int i){
	return ((msk >> i) & 1);
}
// get the shortes path from 0 (start) -> masks -> i-th element marked in mask 
void dps_f(int start){

	int N = n - 2;
	int bits = (N + 1) / 2, size = (1 << N);
	for (int i = 0; i < size ; i++)
		for (int j = 0; j < N; j++)
			dps[i][j] = oo;

	for (int i = 0; i < N; i++)
		dps[(1 << i)][i] = g[start][i + 1];

	for (int i = 0; i < size; i++){
		if (countbits(i) > bits) continue;
		for (int to = 0; to < N; to++){
			if (!is(i, to)) continue;
			int mask = i - (1 << to);
			for (int from = 0; from < N; from++){
				dps[i][to] = min(dps[i][to], dps[mask][from] + g[from + 1][to + 1]);
			}
		}
	}
}

// get the shortes path from n-1 (end) -> masks -> i-th element marked in mask
void dpe_f(int end){

	int N = n - 2;
	int bits = (N + 1) / 2, size = (1 << N);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < N; j++)
			dpe[i][j] = oo;

	for (int i = 0; i < N; i++)
		dpe[(1 << i)][i] = g[end][i + 1];

	for (int i = 0; i < size; i++){
		if (countbits(i) > bits) continue;
		for (int to = 0; to < N; to++){
			if (!is(i, to)) continue;
			int mask = i - (1 << to);
			for (int from = 0; from < N; from++){
				dpe[i][to] = min(dpe[i][to], dpe[mask][from] + g[from + 1][to + 1]);
			}
		}
	}
}

// floyd shortest path
void shortestpath(){
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
int main()
{
	Emsawy();
	while (cin >> n >> m){
		cout << "Case " << ++c << ": ";
		int u, v, w;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)g[i][j] = oo;
		for (int i = 0; i < n; i++) g[i][i] = 0;
		for (int i = 0; i < m; i++){
			sf3(u, v, w);
			g[u][v] = min(g[u][v], w);
			g[v][u] = min(g[u][v], w);
		}
		shortestpath();
		if (n == 3){
			cout << (g[0][1] + g[1][2]) * 2 << endl;
			continue;
		}
		dpe_f(n - 1);
		dps_f(0);

		int N = (n - 2), me = N / 2, size = (1 << N), ans = oo;

		for (int msk = 0; msk < size; msk++){
			if (countbits(msk) != me) continue;
			
			int Not = (size - 1) - msk;
			int resL = oo, resR = oo;

			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++){
					resL = min(resL , dps[msk][i] + dpe[Not][j] + g[i + 1][j + 1]);
				}
			}
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++){
					resR = min(resR, dpe[msk][i] + dps[Not][j] + g[i + 1][j + 1]);
				}
			}
			ans = min(resL + resR, ans);
		}
		cout << ans << endl;
	}
	return 0;
}
