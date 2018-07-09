#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
const ll N = 100000 + 5;
int n, m, k, w;

struct point
{
	int x, y;
};

struct gridCompression
{
	int sizeN, sizeM;
	V<int> clineX, clineY;
	map<int, int> cordx, cordy;
	map<int, int > ::iterator it, nxt;
	V<point> p;
	void init(V<point> & t) {
		sizeN = sizeM = 0; 
		p = t;
	}

	void compressX() {
		for (int i = 0; i < p.size(); i++) {
			cordx[p[i].x]; 
			cordx[p[i].x + 1];
		}
		for (it = cordx.begin(); it != cordx.end();it++) {
			nxt = ++it;
			if (nxt == cordx.end()) break;
			--it;
			it->second = sizeN++;
			clineX.push_back(nxt->first - it->first);
		}
	}

	void compressY() {
		for (int i = 0; i < p.size(); i++) {
			cordy[p[i].y];
			cordy[p[i].y + 1];
		}
		for (it = cordy.begin(); it != cordy.end(); it++) {
			nxt = ++it;
			if (nxt == cordy.end()) break;
			--it;
			it->second = sizeM++;
			clineY.push_back(nxt->first - it->first);
		}
	}
	int X(int x) {
		return cordx[x];
	}
	int Y(int y) {
		return cordy[y];
	}
}g;
int vs[300][300], cur = 0;

ll dfs(int x , int y) {
	ll ret = 0;
	vs[x][y] = cur + 1;
	for (int i = 0; i < 8; i++) {
		int xc = dx[i] + x, yc = dy[i] + y;
		if (xc < 0 || xc >= g.sizeN || yc < 0 || yc >= g.sizeM) continue;
		if (vs[xc][yc] != cur) continue;
		ret += dfs(xc, yc);
	}
	return ret + g.clineX[x] * 1LL * g.clineY[y];
}
int main() {

	Emsawy();
	int t;
	cin >> t;
	while (t--) {
		cur++;
		cin >> n;
		V<point> p(n * 2);
		for (int i = 0; i < (n << 1); i+= 2) {
			cin >> p[i].x >> p[i].y >> p[i + 1].x >> p[i + 1].y;
		}

		g.init(p);
		g.compressX();
		g.compressY();

		for (int i = 0; i < (n << 1); i+= 2) {
			int _00x = g.X(p[i].x);
			int _00y = g.Y(p[i].y);

			int _11x = g.X(p[i+1].x);
			int _11y = g.Y(p[i+1].y);

			for (int a = _00x; a < _11x; a++) {
				for (int b = _00y; b < _11y; b++) {
					vs[a][b] = cur;
				}
			}
		}
		cout << dfs(g.X(p[0].x), g.Y(p[0].y)) << endl;
		cur++;
		if (t) cout << endl;
	}
	return 0;
}
