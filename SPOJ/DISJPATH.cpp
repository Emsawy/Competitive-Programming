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

const int si = 5010 * 2;
int g[si][si], vs[si], flow[si][si], cur = 1;
int getpath(int str, int dis, int mx){
	if (str == dis)
		return mx;
	vs[str] = cur;
	for (int i = 0; i < si; i++){
		if (vs[i] == cur || flow[str][i] >= g[str][i]) continue;
		if (int ret = getpath(i, dis, min(mx, g[str][i] - flow[str][i]))){
			flow[str][i] += ret;
			flow[i][str] -= ret;
			return ret;
		}
	}
	return 0;
}
int MaxFlow(int str, int dis,int k){
	int ans = 0, ret = 0;
	while (k > 0 && (ret = getpath(str, dis, oo)))
		cur++, k-- , ans += ret;
	return ans;
}
V<int>path;
bool PrintPath(int st,int dest){
	if (st == dest)
		return 1;
	for (int i = 0; i < n * 2; i++){
		if (flow[st][i] <= 0) continue;
		if (PrintPath(i, dest)){
			path.push_back(i);
			flow[st][i] = 0;
			return 1;
		}
	}
	return 0;
}
int main()
{
	Emsawy();
	while (cin >> k >> n){
		
		char ch;
		for (int i = 0; i < n; i++){
			while (true){
				scanf("%d%c", &t, &ch);
				t--;
				g[i * 2 + 1][t * 2]=1;
				if (ch == '\n')break;
			}
			g[i * 2][i * 2 + 1]=1;
		}
		printf("Case %d:\n", ++c);
		int ret = MaxFlow(1, 2,k);
		if (ret < k) cout << "Impossible" << endl;
		else{
			while (k > 0 && PrintPath(1, 2)){
				cout << 1 << " ";
				for (int i = path.size() - 1; i >= 0; i -= 2){
					cout << path[i] / 2 + 1 << " ";
				}
				puts("");
				path.clear();
			}
		}
		puts("");
		clr(g, 0);
		clr(flow, 0);
		cur++;
	}
	return 0;
}
