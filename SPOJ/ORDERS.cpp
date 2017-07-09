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
int tr[200005 * 8];
int g[200005],t;
void update(int p, int l, int r, int x){

	if (l == r){
		tr[p] = 0;
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid)
		update(p * 2, l, mid, x);
	else
		update(p * 2 + 1, mid + 1, r, x);

	tr[p] = tr[p * 2] + tr[p * 2 + 1];
}
int get(int p, int l, int r, int kth){
	if (l == r)
		return l;

	if (kth <= tr[p * 2])
		return get(p * 2, l, (l + r) / 2, kth);
	else
		return get(p * 2 + 1, (l + r) / 2 + 1, r, kth - tr[p * 2]);
}
void build(int p, int l, int r){
	if (l == r){
		tr[p] = 1;
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, (l + r) / 2 + 1, r);
	tr[p] = tr[p * 2] + tr[p * 2 + 1];
}
int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> g[i];
		}
		build(1, 0, n - 1);
		int *pos = new int [n];
		for (int i = n - 1; i >= 0; i--){
			int p = get(1, 0, n - 1, i - g[i] + 1);
			pos[i] = p;
			update(1, 0, n - 1, p);
		}
		for (int i = 0; i < n; i++){
			cout << pos[i] + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}
