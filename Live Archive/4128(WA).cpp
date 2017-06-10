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
const ll mod = ll(1e9 + 7), oo = ll(1e9), si = 1000000;

V<V<pair<int,int> > > adj;
int n, m, k, t, c , sx , sy , ex , ey;
int g[101][101], dir[4][101][101];
	//   R  D  L   U
int dx[]{0, 1, 0, -1, 1, -1, 1, -1};
int dy[]{1, 0, -1, 0, 1, -1, -1, 1};


struct Node{

	int ir, cost;
	bool pk;
	pair<int, int> f;
	Node(int cost, pair<int, int> f, int ir, int pk) :cost(cost), f(f), ir(ir),pk(pk) {}
	bool operator<(const Node &x) const{
		return cost > x.cost;
	}
};

int Value(int lx, int ly ,int lr , int x,int y , int i , bool &pk){

	if (lr == 0 && (i == 1 || i == 3) || lr == 2 && (i == 1 || i == 3)) return dir[i][x][y] * 2 + (pk ? dir[lr][lx][ly]+(pk=0) : 0);
	if (lr == 1 && (i == 0 || i == 2) || lr == 3 && (i == 0 || i == 2)) return dir[i][x][y] * 2 + (pk ? dir[lr][lx][ly]+(pk=0) : 0);
	pk = 1;
	return dir[i][x][y];
}

int main()
{
	Emsawy();
	int x;
	pair<int, int> s, e;
	while (cin >> n >> m >> s.first >> s.second >> e.first >> e.second){
		if (n == 0 && m == 0 && s.first == 0 && s.second == 0 && e.first == 0 && e.second == 0) break;
		s.first--, s.second--, e.first--, e.second--;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m - 1; j++){
				cin >> x;
				dir[0][i][j + 1] = x;
				dir[2][i][j] = x;
			}
			if (i == n - 1) continue;
			for (int j = 0; j < m; j++){
				cin >> x;
				dir[1][i + 1][j] = x;
				dir[3][i][j] = x;
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m;j++)
				g[i][j] = oo;

		priority_queue<Node> pq;
		pq.push(Node(0, s, -1,1));
		g[s.first][s.second] = 0;
		while (!pq.empty()){
			Node p = pq.top();
			pq.pop();
			for (int i = 0; i < 4; i++){
				int x = p.f.first + dx[i], y = p.f.second + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m || dir[i][x][y] == 0) continue;
				int value = Value(p.f.first, p.f.second, p.ir, x, y, i, p.pk) + p.cost + (p.f == s && MP(x, y) == e ? dir[i][x][y] * 2 : (p.f == s ? dir[i][x][y] : (MP(x, y) == e ? dir[i][x][y] : 0)));
				if (value >= g[x][y]) continue;
				g[x][y] = value;
				pq.push(Node(value, MP(x, y), i,p.pk));
			}
		}
		cout << "Case " <<++c<< ": ";
		if (g[e.first][e.second] == oo) cout << "Impossible" << endl;
		else cout << g[e.first][e.second] << endl;
		clr(dir, 0);
	}
	return 0;
}
