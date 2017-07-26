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
	int op, cl, sm;
	Node(){}
	Node(int op, int cl, int sm) :op(op), cl(cl), sm(sm){}
};

const int size = 1000006;
Node seg[size * 4];
int g[size];

Node combine(Node l, Node r){
	Node ret;
	int mn = min(l.op, r.cl);
	ret.sm = l.sm + r.sm + mn * 2;
	l.op -= mn;
	r.cl -= mn;
	ret.cl = l.cl + r.cl;
	ret.op = l.op + r.op;
	return ret;
}
string st;
void build(int p, int s, int e){
	if (s == e){
		if (st[s] == '(')
			seg[p] = Node(1, 0, 0);
		else
			seg[p] = Node(0, 1, 0);
		return;
	}
	int mid = (s + e) / 2;
	build(p * 2, s, mid);
	build(p * 2 + 1, mid + 1, e);
	seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
}
void upd(int p, int s, int e, int x){

	if (s == e){
		if (st[s] == '(')
			seg[p] = Node(1, 0, 0);
		else
			seg[p] = Node(0, 1, 0);
		return;
	}
	int mid = (s + e) / 2;
	if (x <= mid)
		upd(p * 2, s, mid, x);
	else
		upd(p * 2 + 1, mid + 1, e, x);

	seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
}

int main()
{
	Emsawy();
	while (cin >> n){
		cin >> st;
		build(1, 0, n - 1);
		cin >> m;
		cout << "Test " << ++c << ":\n";
		while (m--){
			sf(k);
			if (k == 0){
				if (seg[1].cl == 0 && seg[1].op == 0) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else{
				st[k - 1] = (st[k - 1] == '(' ? st[k - 1] == ')' : st[k - 1] = '(');
				upd(1, 0, n - 1, k - 1);
			}
		}
	}
	return 0;
}
