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

V<V<int> > adj;
int n, m, k, t, c, g[100000][5],ans[5];
const int size = 100005;
int sp[size][5][20], in[size][5];
void build(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m;j++)
			sp[i][j][0] = in[i][j];
	for (int col = 0; col < m; col++){
		for (int j = 1; (1 << j) - 1 < n; j++){
			for (int i = 0; i + (1 << (j - 1)) < n; i++){
				sp[i][col][j] = max(sp[i + (1 << (j - 1))][col][j - 1], sp[i][col][j - 1]);
			}
		}
	}
}

int query(int l, int r, int col){
	int j = floor(log2((r - l + 1)));
	return max(sp[l][col][j], sp[r - (1 << j) + 1][col][j]);
}
int valid(int rng,bool ok){

	int ret = oo;
	for (int i = rng - 1; i < n; i++){
		int sm = 0;
		for (int j = 0; j < m; j++){
			ans[j] = query(i - rng + 1, i, j);
			sm += ans[j];
		}
		ret = min(ret, sm);
		if (!ok) continue;
		if (ret <= k) break;
	}
	return ret;
}

int main()
{
	Emsawy();
	while (cin >> n >> m >> k){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				sf(in[i][j]);
			}
		}
		build();
		int s = 1, e = n, res = 0;
		while (s <= e){
			int mid = (s + e) / 2;
			if (valid(mid,0) <= k) s = mid + 1, res = mid;
			else e = mid - 1;
		}
		clr(ans, 0);
		if (res) valid(res, 1);	
		for (int i = 0; i < m; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
