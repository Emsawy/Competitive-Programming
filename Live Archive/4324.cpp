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

#define sz(v)		((int)((v).size()))
#define all(v)		((v).begin()), ((v).end())
#define allr(v)		((v).rbegin()), ((v).rend())
#define clr(v,d)	memset(v, d, sizeof(v))
#define sf(x)		scanf("%d", &x)
#define sf2(x,y)	scanf("%d %d", &x, &y)
#define sf3(x,y,z)	scanf("%d %d %d", &x, &y, &z)
#define sfll(x)		scanf("%I64d", &x)
#define sfll2(x,y)	scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)	scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)	(atan2((a).imag(), (a).real()))
#define vec(a,b)	((b)-(a))
#define length(a)	(hypot((a).imag(), (a).real()))
#define dp(a,b)		((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)		((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)	(dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define rotate0(p,ang)	((p)*exp(Point(0,ang)))
#define rotateA(p,ang,A)(rotate0(vec(A,p),ang)+A)
#define reflect0(v,m)	(conj((v)/(m))*(m))
#define pii		pair<int,int>
#define V		vector
#define MP		make_pair
#define X		real()
#define Y		imag()
typedef complex<double> Point;
typedef long long ll;
typedef pair<pair<int, int>, pair<int, int> > typ;

const double PI = acos(-1.0);
const double EPS = acos(1e-10);
const ll mod = ll(1e9 + 7), oo = ll(1e9);
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

V<V<pii> > adj;
int n, m, k, vs[26], cur = 0, vs2[200][200], cur2 = 0;
char g[200][200];

bool get(int x, int y, int lsx, int lsy, char ch){
	if (vs2[x][y] == cur2)
		return 1;
	vs2[x][y] = cur2;
	for (int i = 0; i < 4; i++){
		int x0 = x + dx[i], y0 = y + dy[i];
		if (x0 < 0 || x0 >= n || y0 < 0 || y0 >= m || g[x0][y0] != ch || (x0 == lsx && y0 == lsy)) continue;
		if (get(x0, y0, x, y, ch))
			return 1;
	}
	return 0;
}
bool valid(pair<int, int>x, pair<int, int>y, pair<int, int>x0, pair<int, int>y0){
	int ok = 0;
	if (min(x0.first, y0.first) > min(x.first, y.first) && max(x0.first, y0.first) < max(x.first, y.first)) ok++;
	if (min(x0.second, y0.second) > min(x.second, y.second) && max(x0.second, y0.second) < max(x.second, y.second)) ok++;
	if (ok == 2) return 1;
	return 0;
}
int main()
{
	Emsawy();
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		cur++;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> g[i][j];
			}
		}/*
		 cur2++;
		 cout<<get(3, 12, -1, -1, 'B')<<endl;*/
		V<int>tv;
		for (int q = 0; q < 26; q++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j <m; j++){
					if (g[i][j] != q + 'A') continue;
					if (vs[q] == cur) continue;
					vs[q] = cur;
					cur2++;
					if (get(i, j, -1, -1, q + 'A'))
						tv.push_back(q);
				}
			}
		}
		V<pair<int, typ > > rec;
		V<V<pair<int, int> > >me(26);
		for (int q = 0; q < tv.size(); q++){
			char now = tv[q] + 'A';
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if (g[i][j] == now){
						if (j + 1 < m && i + 1 < n && g[i][j + 1] == now && g[i + 1][j] == now){
							me[tv[q]].push_back(MP(i, j));
							break;
						}
						if (j - 1 >= 0 && i - 1 >= 0 && g[i][j - 1] == now && g[i - 1][j] == now){
							me[tv[q]].push_back(MP(i, j));
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < 26; i++){
			if (me[i].size())
				rec.push_back(MP(i, MP(me[i][0], me[i][1])));
		}
		V<int>ans;
		for (int i = 0; i < rec.size(); i++){
			bool ok = 0;
			for (int j = 0; j < rec.size(); j++){
				if (i == j) continue;
				ok |= valid(rec[i].second.first, rec[i].second.second, rec[j].second.first, rec[j].second.second);
			}
			if (ok == 0)
				ans.push_back(rec[i].first);
		}
		sort(all(ans));
		for (int i = 0; i < ans.size(); i++)
			cout << char(ans[i] + 'A');
		cout << endl;
	}
	return 0;
}
