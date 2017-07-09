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
int n, m, k, t;
pair<int, int> tr[100005 * 4];
int g[100005]; // 1e6
void update(int p, int l, int r, int x){
	
	if (l == r){
		tr[p].first = g[l];
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid)
		update(p * 2, l, mid, x);
	else
		update(p * 2 + 1, mid + 1, r, x);

	tr[p] = max(tr[p * 2], tr[p * 2 + 1]);
}
pair<int,int> get(int p, int l, int r, int x, int y){
	if (l > y || r < x)
		return MP(-1,-1);
	if (x <= l && r <= y)
		return tr[p];

	return max(get(p * 2, l, (l + r) / 2, x, y), get(p * 2 + 1, (l + r) / 2 + 1, r, x, y));
}


void build(int p, int l, int r){
	if (l == r){
		tr[p] = MP(g[l], l);
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, (l + r) / 2 + 1, r);
	tr[p] = max(tr[p * 2], tr[p * 2 + 1]);
}

int main()
{
	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++)
			cin >> g[i];
		build(1, 0, n - 1);

		int q , x , y;
		cin >> q;
		char ch;
		while (q--){
			cin >> ch >> x >> y;
			x--, y--;
			if (ch == 'Q'){
				pair<int, int> f = get(1, 0, n - 1, x, y);
				int tmp = g[f.second];
				g[f.second] = 0;
				update(1, 0, n - 1, f.second);
				pair<int, int> s = get(1, 0, n - 1, x, y);
				g[f.second] = tmp;
				update(1, 0, n - 1, f.second);
				cout << f.first + s.first << endl;
			}
			else g[x] = y + 1, update(1, 0, n - 1, x);
		}
	}

	return 0;
}
