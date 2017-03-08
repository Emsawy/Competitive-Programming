
/*
- I use Segment trees to divide the Y-axes (columns) and for each node in the tree is an array with lenght (n).
- Each array of the tree is a partial sum for it's column.
- I used update function to get range (y,y) and update the arrays with the intend value (A) for all the nodes which i will pass.
- I used get fuction to get the answers of the quaries and for each nodes of the tree contains this range(y0,y) i will return the differece between the end x and the start x - 1 (because i used partial sum ).
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <set>

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
#define sfll3(x,y,z)	scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define rotate0(p,ang)	((p)*exp(Point(0,ang)))
#define rotateA(p,ang,A)(rotate0(vec(A,p),ang)+A)
#define reflect0(v,m)	(conj((v)/(m))*(m))
#define pii				pair<int,int>
#define V				vector
#define MP				make_pair
#define X				real()
#define Y				imag()
typedef complex<double> Point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = acos(1e-10);
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k;
int tr[(1 << 11) + 1][1025];
void up(int v[], int A, int x){
	for (int i = x; i <= n ; i++){
		v[i] += A;
	}
}
void update(int p, int l, int r, int x, int y , int A , int x0){
	if (l > y || r < x)
		return;
	if (x <= l && r <= y){
		up(tr[p], A, x0);
		return;
	}
	up(tr[p], A, x0);
	int mid = (l + r) / 2;
	if (y <= mid)
		update(p * 2, l, (l + r) / 2, x, y, A,x0);
	else
		update(p * 2 + 1, (l + r) / 2 + 1, r, x, y, A,x0);
}
ll get(int p, int l, int r, int x, int y , int x0 , int y0){
	if (l > y || r < x)
		return 0;
	if (x <= l && r <= y){
		return tr[p][y0] - tr[p][x0 - 1];
	}
	return get(p * 2, l, (l + r) / 2, x, y, x0, y0) + get(p * 2 + 1, (l + r) / 2 + 1, r, x, y, x0, y0);
}

int main()
{
	Emsawy();
	int x, y, A, x0, y0 , ok = 1;
	while (sf2(n,n) && ok){
		while (sf(m) && ok){
			if (m == 1){
				sf3(x, y, A);
				update(1, 1, n, y+1, y+1, A, x+1);
			}
			else if(m == 2) {
				sf2(x0, y0);
				sf2(x, y);
				printf("%d\n", get(1, 1, n, y0+1, y+1, x0+1, x+1));
			}
			else ok = 0;
		}
	}
	return 0;
}
