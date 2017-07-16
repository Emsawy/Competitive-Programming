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
int n, m, k, t, c;

const int size = 100006;
int seg[size * 4], input[size];
int g[size];
void update(int p, int s, int e, int x){

	if (s == e){
		seg[p] = g[s];
		return;
	}
	int mid = (s + e) / 2;
	if (x <= mid)
		update(p * 2, s, mid, x);
	else
		update(p * 2 + 1, mid + 1, e, x);

	seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}
ll query(int p, int s, int e, int x, int y){
	if (s > y || e < x)
		return oo;          // take care
	if (x <= s && e <= y)
		return seg[p];

	return min(query(p * 2, s, (s + e) / 2, x, y), query(p * 2 + 1, (s + e) / 2 + 1, e, x, y));
}


void build(int p, int s, int e){
	if (s == e){
		seg[p] = g[s];
		return;
	}
	build(p * 2, s, (s + e) / 2);
	build(p * 2 + 1, (s + e) / 2 + 1, e);
	seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}
//sscanf(str, "%*[^=]%*c%[^&]%*[^=]%*c", buf1);

int main()
{
	Emsawy();
	while (cin >> n >> m){
		for (int i = 0; i < n; i++){
			sf(g[i]);
		}
		build(1, 0, n - 1);
		char s[33],num[10],ay7aga[10];
		gets(num);
		while (m--){
			gets(s);
			int size = strlen(s), inSize = 0, len = 0;
			while (sscanf(s + len, "%[^0123456789]%[^ ,)]%", ay7aga, num) == 2){
				input[inSize++] = stoi(num) - 1;
				len += strlen(num) + strlen(ay7aga);
			}
			if (s[0] == 's'){
				int end = g[input[0]];
				for (int i = 0; i + 1 < inSize; i++){
					swap(g[input[i]], g[input[i + 1]]);
				}
				g[input[inSize - 1]] = end;
				for (int i = 0; i < inSize; i++){
					update(1, 0, n - 1, input[i]);
				}
			}
			else printf("%d\n", query(1, 0, n - 1, input[0], input[1]));
		}
	}
	return 0;
}
