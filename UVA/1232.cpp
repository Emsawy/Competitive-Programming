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
int n, m, k, t, c;
int seg[1 << 22][2], lz[1 << 22], g[1 << 20];
void shift(int p, int s, int  e){
	if (lz[p]){
		if (s != e){
			seg[p << 1][0] = seg[p << 1][1] = lz[p << 1] = lz[p];
			seg[p << 1 | 1][0] = seg[p << 1 | 1][1] = lz[p << 1 | 1] = lz[p];
		}
	}
	lz[p] = 0;
}

ll  res = 0;
void upd(int p, int s, int e, int x, int y, int b){
	shift(p, s, e);
	if (s > e||s > e || x > e || s > y) return;
	
	if (seg[p][0] > b)
		return ;

	if (x <= s && e <= y){
			if (seg[p][1] <= b){
				res += (e - s + 1);
				seg[p][1] = seg[p][0] = lz[p] = b;
				return ;
			}
		
	}
	int mid = (s + e) / 2;
	upd(p << 1, s, mid, x, y, b);
	upd(p << 1 | 1, mid+1, e, x, y, b);
	seg[p][0] = min(seg[p << 1 | 1][0], seg[p << 1][0]);
	seg[p][1] = max(seg[p << 1 | 1][1], seg[p << 1][1]);
}

int main()
{
	Emsawy();
	int T;
	cin >> t;
	while (t--){
		cin >> n;
		int l, r, h;
		for (int i = 0; i < n; i++){
			sf3(l, r, h);
			upd(1, 1, 100000, l, r-1, h);	
		}
		cout << res << endl;
		res = 0;
		clr(lz, 0);
		clr(seg, 0);
	}
	return 0;
}
