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
const ll mod = ll(1e9 + 7), oo = ll(1e15),si = 200005;

V<V<pii> > adj;
int n, m,a,b,c;
ll tr[200005 * 4];
int g[200005];
ll lazy[200005 * 4];

void shift(int p){
	if (lazy[p]){
		lazy[p * 2] += lazy[p];
		lazy[p * 2 + 1] += lazy[p];
	}
	if (lazy[p]){
		tr[p * 2] += lazy[p];
		tr[p * 2 + 1] += lazy[p];
	}
	lazy[p] = 0;
}
void update(int p, int s, int e, int x, int y, int col){
	if (x > e || s > y) return;
	if (x <= s && e <= y){
		lazy[p] += col;
		tr[p] += col;
		return;
	}
	shift(p);
	int mid = (s + e) / 2;
	update(p * 2, s, mid, x, y, col);
	update(p * 2 + 1, mid + 1, e, x, y, col);
	tr[p] = min(tr[p * 2 + 1], tr[p * 2]);
}
ll get(int p, int l, int r, int x, int y){
	if (l > y || r < x)
		return oo;
	if (x <= l && r <= y)
		return tr[p];
	shift(p);
	return min(get(p * 2, l, (l + r) / 2, x, y), get(p * 2 + 1, (l + r) / 2 + 1, r, x, y));
}

void build(int p, int l, int r){
	if (l == r){
		tr[p] = g[l];
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, (l + r) / 2 + 1, r);
	tr[p] = min(tr[p * 2], tr[p * 2 + 1]);
}
int main()
{
	Emsawy();
	while (cin >> n){

		for (int i = 0; i < n; i++){
			cin >> g[i];
		}
		build(1, 0, n - 1);
		int q;
		cin >> q;
		char ch[100];
		getchar();
		while (q--){
			if ((sscanf(gets(ch), "%d%d%d", &a, &b, &c) == 3)){
				if (a <= b)
					update(1, 0, n - 1, a, b, c);
				else
					update(1, 0, n - 1, 0, b, c), update(1, 0, n - 1, a, n-1, c);
			}
			else{
				if (a <= b)
					printf("%I64d\n", get(1, 0, n - 1, a, b));
				else
					printf("%I64d\n", min(get(1, 0, n - 1, 0, b), get(1, 0, n - 1, a, n - 1)));
			}
		}
	}
	return 0;
}
