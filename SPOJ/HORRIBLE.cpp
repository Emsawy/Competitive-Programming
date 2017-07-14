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

const int size = 100000;
ll seg[size * 8];
ll lz[size * 8];
void shift(int p, int s, int  e){
	if (lz[p]){
		seg[p] += lz[p] * (e - s + 1);
		if (s != e){
			lz[p * 2] += lz[p];
			lz[p * 2 + 1] += lz[p];
		}
	}
	lz[p] = 0;
}
void upd(int p, int s, int e, int x, int y, ll add){
	shift(p, s, e);
	if (s > e || x > e || s > y) return;
	if (x <= s && e <= y){
		lz[p] = add;
		shift(p, s, e);
		return;
	}
	int mid = (s + e) / 2;
	upd(p * 2, s, mid, x, y, add);
	upd(p * 2 + 1, mid + 1, e, x, y, add);
	seg[p] = seg[p * 2 + 1] + seg[p * 2];
}
ll get(int p, int s, int e, int x, int y){

	shift(p, s, e);
	if (s > e || x > e || s > y)
		return 0;
	if (x <= s && e <= y)
		return seg[p];
	return get(p * 2, s, (s + e) / 2, x, y) + get(p * 2 + 1, (s + e) / 2 + 1, e, x, y);
}

int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> n >> m;
		int p, q, v;
		for (int i = 0; i < m; i++){
			sf(c);
			if (!c){
				cin >> p >> q >> v;
				upd (1, 0, n - 1, p - 1, q - 1, v);
			}
			else{
				cin >> p >> q;
				cout << get(1, 0, n - 1, p - 1, q - 1) << endl;
			}
		}

		clr(seg, 0);
		clr(lz, 0);
	}
	return 0;
}
