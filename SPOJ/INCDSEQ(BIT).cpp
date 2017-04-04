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
const ll mod = ll(5e6), oo = ll(1e9), si = 10009;

V<V<pii> > adj;
int n, m, k, t, c;
int DP[55][si];
int BIT[55][si];
void update(int q, int idx, int delta){
	for (int x = idx; x <= si; x += (x & -x))
		BIT[q][x] = (BIT[q][x] + delta) % mod;

}

int get(int q, int idx){
	int sum = 0;
	for (int x = idx; x > 0; x -= (x & -x))
		sum = (sum + BIT[q][x]) % mod;

	return sum;
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
			int cp = 1 + lower_bound(b.begin(), b.begin() + B, v[j]) - b.begin();
			if (!DP[1][cp]){
				update(1, cp, 1);
				DP[1][cp] = 1;
			}
			for (int i = 2; i <= m; i++){
				int change = ((get(i - 1, cp - 1) - DP[i][cp]) % mod + mod) % mod;   // take care
				update(i , cp, change);
				DP[i][cp] += change;
				DP[i][cp] %= mod;
			}
		}
		cout << get(m , si) << endl;

	}
	return 0;
}
