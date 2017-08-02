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
#define rotate0(p,ang)		((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)	(rotate0(vec(about,p),ang)+about)
#define reflect0(v,m)		(conj((v)/(m))*(m))
#define normalize(a)		(a)/length(a)
#define lengthSqr(p)		dp(p,p)
#define pii			pair<int,int>
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()

typedef complex<int> 	point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-9;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<int> > adj;
int n, m, k, t, c;
struct Node
{
	point a, b;
	Node(){}
	Node(point a, point b) : a(a), b(b){}
	bool operator<(const Node& r) const {
		if (a.X < r.a.X) return 1;
		else if (a.X == r.a.X && a.Y < r.a.Y) return 1;
		return 0;
	}
};
void rotate(Node &nd){
	int x = nd.a.X - nd.b.X;
	int y = nd.a.Y - nd.b.Y;
	nd.a = point(nd.b.X - y, nd.b.Y + x);
}
double dis(point a, point b){
	return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}
bool valid(Node nd[4]){
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++)
			if (nd[i].a == nd[j].a)
				return 0;
	int cnt = 0;
	set<int>st;
	for (int i = 0; i < 4; i++){
		for (int j = i + 1; j < 4; j++){
			st.insert(dis(nd[i].a, nd[j].a));
			if (nd[i].a.X == nd[j].a.X || nd[i].a.Y == nd[j].a.Y)cnt++;
		}
	}
	if (st.size() == 2)
		return 1;
	return 0;
}
int main()
{
	Emsawy();
	while (cin >> n){
		int a, b, c, d;
		for (int i = 0; i < n; i++){
			Node nd[4];
			for (int j = 0; j < 4; j++){
				sf2(a, b);
				sf2(c, d);
				nd[j].a = point(a, b);
				nd[j].b = point(c, d);
			}
			int cnt = oo;
			for (int a = 0; a < 4; a++){
				for (int b = 0; b < 4; b++){
					for (int c = 0; c < 4; c++){
						for (int d = 0; d < 4; d++){
							if (valid(nd)){
								cnt = min(cnt, a + b + c + d);
							}
							rotate(nd[3]);
						}
						rotate(nd[2]);
					}
					rotate(nd[1]);
				}
				rotate(nd[0]);
			}
			if (cnt == oo) cnt = -1;
			cout << cnt << endl;
		}
	}
	return 0;
}
