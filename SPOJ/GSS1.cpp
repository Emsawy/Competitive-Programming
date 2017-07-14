
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
	int bl, br, b, sm;
	Node(){}
	Node(int b, int bl, int br, int sm) :b(b), bl(bl), br(br), sm(sm){}
};
Node seg[50005 * 4];
int g[50005];

inline Node combine(Node l, Node r){
	int lf = max(l.bl, l.sm + r.bl);
	int ri = max(r.br, r.sm + l.br);
	int b = max(max(l.b, r.b), l.br + r.bl);
	return Node(b, lf, ri, l.sm + r.sm);
}

Node get(int p, int l, int r, int x, int y){

	if (x <= l && r <= y)
		return seg[p];
	int mid = (l + r) / 2;
	if (y <= mid)
		return  get(p * 2, l, mid, x, y);
	else if (x > mid)
		return get(p * 2 + 1, mid + 1, r, x, y);

	Node ln = get(p * 2, l, mid, x, y);
	Node rn = get(p * 2 + 1, mid + 1, r, x, y);
	return combine(ln, rn);
}

void build(int p, int l, int r){
	if (l == r){
		seg[p] = Node(g[l], g[l], g[l], g[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);	
}

int main()
{
	Emsawy();
	while (sf(n)==1){
		for (int i = 0; i < n; i++)
			 sf(g[i]);
		build(1, 0, n - 1);
		sf(m);
		int x, y;
		while (m--){
			sf2(x, y);
			printf("%d\n",get(1, 0, n - 1, x - 1, y - 1).b);
		}
	}
	return 0;
}
