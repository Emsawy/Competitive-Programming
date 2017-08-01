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
const double EPS = 1e-9;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<int> > adj;
int n, m, k, t, c;

const int size = 1000006;
int seg[3][21][size * 4];
pair<int, bool> lz[21][size * 4];
void shift(int p, int s, int  e, int row){
	if (lz[row][p].first){
		if (lz[row][p].second){
		//	while (p >= size * 4);
			seg[0][row][p] += lz[row][p].first * (e - s + 1);
			seg[1][row][p] += lz[row][p].first;
			seg[2][row][p] += lz[row][p].first;

			if (s != e){
			//	while (p * 2 + 1 >= size * 4);
				lz[row][p * 2].first += lz[row][p].first;
				lz[row][p * 2 + 1].first += lz[row][p].first;
				lz[row][p * 2].second &= lz[row][p].second;
				lz[row][p * 2 + 1].second &= lz[row][p].second;
			}
		}
		else{
			//while (p >= size * 4);
			seg[0][row][p] = lz[row][p].first * (e - s + 1);
			seg[1][row][p] = lz[row][p].first;
			seg[2][row][p] = lz[row][p].first;
			
			if (s != e){
				//while (p * 2 + 1 >= size * 4);
				lz[row][p * 2].first = lz[row][p].first;
				lz[row][p * 2 + 1].first = lz[row][p].first;
				lz[row][p * 2].second &= lz[row][p].second;
				lz[row][p * 2 + 1].second &= lz[row][p].second;
			}
		}

	}
	lz[row][p] = MP(0, 1);
}
void upd(int p, int s, int e, int x, int y, int add, int typ, int row){
	shift(p, s, e, row);
	if (s > e || x > e || s > y) return;
	if (x <= s && e <= y){
		//while (p >= size * 4);
		lz[row][p] = MP(add, typ);
		shift(p, s, e, row);
		return;
	}
	seg[0][row][p] = 0;
	seg[1][row][p] = 0;
	seg[2][row][p] = 0;
	lz[row][p] = { 0, 1 };
	int mid = (s + e) / 2;
	upd(p * 2, s, mid, x, y, add, typ, row);
	upd(p * 2 + 1, mid + 1, e, x, y, add, typ, row);

	//while (p * 2 + 1 >= size * 4);
	seg[0][row][p] = seg[0][row][p * 2 + 1] + seg[0][row][p * 2];
	seg[2][row][p] = max(seg[2][row][p * 2 + 1] , seg[2][row][p * 2]);
	seg[1][row][p] = min(seg[1][row][p * 2 + 1] , seg[1][row][p * 2]);
}
int sum(int p, int s, int e, int x, int y, int row){
	shift(p, s, e, row);
	if (s > e || x > e || s > y) return 0;
	//while (p >= size * 4);
	if (x <= s && e <= y)
		return seg[0][row][p];
	return sum(p * 2, s, (s + e) / 2, x, y, row) + sum(p * 2 + 1, (s + e) / 2 + 1, e, x, y, row);
}
int mx(int p, int s, int e, int x, int y, int row){
	//while (p >= size * 4);
	shift(p, s, e, row);
	if (s > e || x > e || s > y) return 0;
	if (x <= s && e <= y) return seg[2][row][p];
	return max(mx(p * 2, s, (s + e) / 2, x, y, row), mx(p * 2 + 1, (s + e) / 2 + 1, e, x, y, row));
}
int mn(int p, int s, int e, int x, int y, int row){
	//while (p >= size * 4);
	shift(p, s, e, row);
	if (s > e || x > e || s > y) return oo;
	if (x <= s && e <= y) return seg[1][row][p];
	return min(mn(p * 2, s, (s + e) / 2, x, y, row), mn(p * 2 + 1, (s + e) / 2 + 1, e, x, y, row));
}
int main()
{
	Emsawy();

	while (cin >> n >> m >> c){
		int l, r, a, b, v;
		while (c--){
			sf(t);
			sf2(l, r);
			sf2(a, b);
			if (t == 1 || t == 2){
				sf(v);
				for (int i = l; i <= a; i++){
					upd(1, 1, m, r, b, v, t == 1 ? 1 : 0 , i);
				}
			}
			else{
				int am = 0, amn = oo, amx = 0;
				for (int i = l; i <= a; i++){
					am += sum(1, 1, m, r, b, i);
					amn = min(amn, mn(1, 1, m, r, b, i));
					amx = max(amx, mx(1, 1, m, r, b, i));
				}
				printf("%d %d %d\n", am, amn, amx);
			} 
		}
	}
	return 0;
}
