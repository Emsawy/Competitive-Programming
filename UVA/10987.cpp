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
int g[101][101];

int main()
{
	Emsawy();
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 2; i <= n; i++){
			for (int j = 1; j < i; j++){
				cin >> g[i][j];
				g[j][i] = g[i][j];
			}
		}
		bool ok = 0;
		V<pair<int, int> > ans;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				bool cnt = 0;
				for (int k = 1; k <= n; k++){
					if (k == i || k == j) continue;
					if (g[i][j] > g[i][k] + g[k][j]){
						ok = 1;
						break;
					}
					if (g[i][j] == g[i][k] + g[k][j])
						cnt = 1;
				}
				if (cnt == 0)
					ans.push_back(MP(i, j));
				if (ok) break;
			}
			if (ok) break;
		}
		cout<<"Case #"<<++c<<":\n";
		if (ok) puts("Need better measurements.");
		else{
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i].first << " " << ans[i].second << " " << g[ans[i].first][ans[i].second] << endl;
		}
		puts("");
	}
	return 0;
}
