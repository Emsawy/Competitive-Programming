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

const double PI = acos(-1.0);
const double EPS = acos(1e-10);
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k , g[101][101];
void _1(int len){
	int x0 = len, y0 = len;
	int x1 = len, y1 = n - len - 1;
	int x2 = n - len - 1, y2 = n - len - 1;
	int x3 = n - len - 1, y3 = len;
	int lp = n - 2 * len;
	for (int i = 0; i < lp / 2;i++){
		swap(g[x0 + i][y0], g[x3 - i][y3]);
		swap(g[x0 + i][y1], g[x3 - i][y2]);
	}
	for (int i = y0 + 1; i <= y1 - 1; i++){
		swap(g[x0][i], g[x3][i]);
	}
}
void _2(int len){
	int x0 = len, y0 = len;
	int x1 = len, y1 = n - len - 1;
	int x2 = n - len - 1, y2 = n - len - 1;
	int x3 = n - len - 1, y3 = len;
	int lp = n - 2 * len;
	for (int i = 0; i < lp / 2; i++){
		swap(g[x0][y0 + i], g[x1][y1 - i]);
		swap(g[x3][y3 + i], g[x2][y2 - i]);
	}
	for (int i = x0 + 1; i <= x3 - 1; i++){
		swap(g[i][y0], g[i][y1]);
	}
}
void _3(int len){
	int x0 = len, y0 = len;
	int x1 = len, y1 = n - len - 1;
	int x2 = n - len - 1, y2 = n - len - 1;
	int x3 = n - len - 1, y3 = len;
	int lp = n - 2 * len;
	for (int i = 0; i < lp; i++){
		swap(g[x0 + i][y0], g[x0][y0 + i]);
	}
	for (int i = 0; i < lp - 1; i++){
		swap(g[x2 - i][y2], g[x2][y2 - i]);
	}
}

void _4(int len){
	int x0 = len, y0 = len;
	int x1 = len, y1 = n - len - 1;
	int x2 = n - len - 1, y2 = n - len - 1;
	int x3 = n - len - 1, y3 = len;
	int lp = n - 2 * len;
	for (int i = 0; i < lp; i++){
		swap(g[x3 - i][y3], g[x3][y3 + i]);
	}
	for (int i = 0; i < lp - 1; i++){
		swap(g[x1][y1 - i], g[x1 + i][y1]);
	}
}
int main()
{
	Emsawy();
	cin >> m;
	while (m--){
		sf(n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				sf( g[i][j]);
			}
		}
		int lines = (n + 1) / 2;
		for (int i = 0; i < lines; i++){
			int T; 
			sf(T);
			while (T--){
				sf(k);
				if (k == 1) _1(i);
				else if (k == 2) _2(i);
				else if (k == 3)_3(i);
				else _4(i);
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				cout << g[i][j] << " \n"[j == n - 1];
		}
	}
	return 0;
}
