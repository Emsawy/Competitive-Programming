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
struct Node{
	int zero, one, two;
	Node(){}
	Node(int zero, int one, int two) :zero(zero), one(one), two(two){}
};

const int size = 1000006;
Node seg[size * 4];
int lz[size * 4];
void shift(int p,int s,int e){
	lz[p] %= 3;
	if (lz[p]){

		if (s != e){
			lz[p * 2] += lz[p];
			lz[p * 2 + 1] += lz[p];
		}

		while (lz[p]--){
			int tmp = seg[p].two;
			seg[p].two = seg[p].one;
			seg[p].one = seg[p].zero;
			seg[p].zero = tmp;
		}
	}
	lz[p] = 0;
}

Node combine(Node l, Node r){
	Node ret;
	ret.zero = l.zero + r.zero;
	ret.one = l.one + r.one;
	ret.two = l.two + r.two;
	return ret;
}

Node query(int p, int s, int e, int x, int y){

	shift(p,s,e);
	if (x <= s && e <= y)
		return seg[p];
	int mid = (s + e) / 2;
	if (y <= mid)
		return  query(p * 2, s, mid, x, y);
	else if (x > mid)
		return query(p * 2 + 1, mid + 1, e, x, y);

	Node ln = query(p * 2, s, mid, x, y);
	Node rn = query(p * 2 + 1, mid + 1, e, x, y);
	return combine(ln, rn);
}

void upd(int p, int s, int e, int l , int r){
	
	shift(p, s, e);
	if (r < s || l > e) return;
	if (s >= l && e <= r){
		lz[p] = 1;
		shift(p, s, e);
		return;
	}
	int mid = (s + e) / 2;
	upd(p * 2, s, mid, l, r);
	upd(p * 2 + 1, mid + 1, e, l, r);
	seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
}
void build(int p, int s, int e){
	if (s == e){
		seg[p].zero = 1;
		return;
	}
	build(p * 2, s, (s + e) / 2);
	build(p * 2 + 1, (s + e) / 2 + 1, e);
	seg[p].zero = seg[p * 2].zero + seg[p * 2 + 1].zero;
}
int main()
{
	Emsawy();
	while (cin>>n>>m){
		int l, r;
		build(1,0,n-1);
		while (m--){
			sf3(t, l, r);
			if (t == 0) upd(1, 0, n - 1, l, r);
			else printf("%d\n", query(1, 0, n - 1, l, r).zero);
		}
	}
	return 0;
}
