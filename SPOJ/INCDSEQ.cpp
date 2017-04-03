/*
- I used dp tech. to solve.
- state of dp is (i,j), dp[i][j] is the number of sequence with length i which end with number j.
- but i dorp one dimesion to optimze the memory and used segment tree to optimze the time to get the answer for each state dp[--][j].
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
const ll mod = ll(5e6), oo = ll(1e9), si = 1000000;

V<V<pii> > adj;
int n, m, k, t, c;
long long dp[55][11000*8];
void update(int p, int l, int r, int x, int y, int q, long long vl){
	if (l > y || r < x)
		return;
	if (x <= l && r <= y){
		dp[q][p] = vl % mod ;
		return;
	}
	update(p * 2, l, (l + r) / 2, x, y,q,vl);
	update(p * 2 + 1, (l + r) / 2 + 1, r, x, y,q,vl);
	dp[q][p] = (dp[q][p * 2] + dp[q][p * 2 + 1]) % mod ;
}
long long get(int p, int l, int r, int x, int y, int q){
	if (l > y || r < x)
		return 0;
	if (x <= l && r <= y)
		return dp[q][p] % mod;

	return (get(p * 2, l, (l + r) / 2, x, y,q) + get(p * 2 + 1, (l + r) / 2 + 1, r, x, y,q) ) % mod ;
}

int main()
{
	Emsawy();
	while (cin >> n >> m){
		V<int>v(n) , b(n);
		for (int i = 0; i < n; i++){
			sf(v[i]);
			b[i] = v[i];
		}
		sort(all(b));
		int B = unique(all(b)) - b.begin();
		for (int j = 0; j < n; j++){
			int cp = lower_bound(b.begin(), b.begin() + B, v[j]) - b.begin();
			update(1, 0, B - 1, cp, cp, 0, 1);
			for (int i = 1; i <= m; i++){
				update(1, 0, B - 1, cp, cp, i, get(1, 0, B - 1, 0, cp - 1, i - 1));
			}
		}
		cout << dp[m - 1][1] << endl;

	}
	return 0;
}
