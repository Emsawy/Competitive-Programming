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
const ll N = 3000 + 5;
int n, m, k, w, h;
bool g[301][301];

struct point {
	int x, y;
	bool operator<(const point &l) const {
		if (x < l.x) return 1;
		else if (x == l.x && y < l.y) return 1;
		return 0;
	}
};

V<point> comp;
void connect(point pt) {

	comp.push_back(pt);
	g[pt.x][pt.y] = 0;
	for (int i = 0; i < 4; i++) {
		point to;
		to.x = dx[i] + pt.x;
		to.y = dy[i] + pt.y;
		if (to.x < 0 || to.x > w || to.y < 0 || to.y > h || !g[to.x][to.y]) continue;
		connect(to);
	}
}
char dir(point a, point b) {
	if (a.x == b.x) {
		if (b.y > a.y) return 'U';
		else return 'D';
	}
	else {
		if (b.x > a.x) return 'R';
		else return 'L';
	}
}
string s;
int nd;
void canon(point pt) {
	g[pt.x + 120][pt.y + 120] = 0;
	for (int i = 0; i < 4; i++) {
		point to;
		to.x = dx[i] + pt.x;
		to.y = dy[i] + pt.y;
		if (!g[to.x + 120][to.y + 120]) continue;
		s += dir(pt, to);
		canon(to);
		s += dir(to, pt);
	}
}
void pre(V<point>&pt) {
	sort(all(pt));
	for (int i = 0; i < pt.size(); i++) {
		g[pt[i].x + 120][pt[i].y + 120] = 1;
	}
	canon(pt[0]);
}

// a = 1, b = -1
// a = -1, b = 1
// a = -1, b = -1

void rev(V<point> &pt, int a, int b) {
	for (int i = 0; i < pt.size(); i++) {
		pt[i] = { pt[i].x * a, pt[i].y * b };
	}
}
void rotate(V<point> &pt) {
	for (int i = 0; i < pt.size(); i++) {
		pt[i] = { pt[i].y , -pt[i].x };
	}
}
multiset<string>::iterator it;
bool OK(V<point> pt, multiset<string> &st) {
	pre(pt);
	it = st.find(s);
	if (it != st.end()) {
		st.erase(it);
		s.clear();
		return 1;
	}
	s.clear();
	return 0;
}
int main() {

	Emsawy();	
	int t;
	cin >> t;
	while (t--) {
		cin >> w >> h >> n;
		point pt;
		for (int i = 1; i <= n; i++) {
			cin >> pt.x >> pt.y;
			g[pt.x][pt.y] = 1;
		}
		multiset<string> st;
		for (int i = 0; i <= w; i++) {
			for (int j = 0; j <= h; j++) {
				if (g[i][j]) {
					connect(point{ i,j });
					pre(comp);
					st.insert(s);
					s.clear();
					comp.clear();
				}
			}
		}

		V<V<point> > pts;
		for (int i = 0; i < n; i++) {
			cin >> pt.x >> pt.y;
			g[pt.x][pt.y] = 1;
		}
		for (int i = 0; i <= w; i++) {
			for (int j = 0; j <= h; j++) {
				if (g[i][j]) {
					connect(point{ i,j });
					sort(all(comp));
					pts.push_back(comp);
					comp.clear();
				}
			}
		}
		bool notfound = 0;
		for (int i = 0; i < pts.size(); i++) {

			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);

			rev(pts[i], 1, -1);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			rev(pts[i], 1, -1);

			rev(pts[i], -1, 1);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			if (OK(pts[i], st)) continue;
			rotate(pts[i]);
			rev(pts[i], -1, 1);

			notfound = 1;
			break;
		}
		if (notfound) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
