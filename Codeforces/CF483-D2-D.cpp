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

const int size = 1000006;
int seg[size * 4];
int ans[size];
int g[size];
ll query(int p, int s, int e, int x, int y){

	if (s > e || x > e || s > y)
		return (1 << 30) - 1;             // take care 
	if (x <= s && e <= y)
		return seg[p];
	return query(p * 2, s, (s + e) / 2, x, y) & query(p * 2 + 1, (s + e) / 2 + 1, e, x, y);
}

void build(int p, int s, int e){

	if (s == e){
		seg[p] = g[s];
		return;
	}
	build(p * 2, s, (s + e) / 2);
	build(p * 2 + 1, (s + e) / 2 + 1, e);
	seg[p] = seg[p * 2] & seg[p * 2 + 1];
}

int main()
{
	Emsawy();
	while (cin >> n >> m){
		V<int>a(m), b(m), q(m);
		for (int i = 0; i < m; i++){
			cin >> a[i] >> b[i] >> q[i];
			a[i]--, b[i]--;
		}
		int cnt[size];
		for (int i = 0; i < 30; i++){
			clr(cnt, 0);
			for (int j = 0; j < m; j++){
				if ((q[j] & (1 << i))){
					cnt[a[j]]++;
					cnt[b[j] + 1]--;
				}
			}
			for (int j = 0; j < n; j++){
				if (j) cnt[j] += cnt[j - 1];
				if (cnt[j] > 0)
					g[j] |= (1 << i);
			}
		}
		build(1, 0, n - 1);
		bool ok = 0;
		for (int i = 0; i < m; i++){
			if (q[i] != query(1, 0, n - 1, a[i], b[i])){
				ok = 1;
				break;
			}
		}
		if (ok) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << g[i] << " ";
			puts("");
		}
	}
	return 0;
}
