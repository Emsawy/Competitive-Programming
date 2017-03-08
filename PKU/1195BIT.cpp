/*
- I used Binary search Tree .
*/
//------------------------------------------------------------------
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
#define rotate0(p,ang)  ((p)*exp(Point(0,ang)))
#define rotateA(p,ang,A)(rotate0(vec(A,p),ang)+A)
#define reflect0(v,m)   (conj((v)/(m))*(m))
#define pii				pair<int,int>
#define V				vector
#define MP				make_pair
#define X				real()
#define Y				imag()

typedef complex<double> Point;
typedef long long ll;
const double PI = acos(-1.0);
const double EPS = acos(1e-10);
const ll mod = ll(1e9 + 7), oo = ll(1e9) , si = 1025;
V<V<pii> > adj;

int n, m, k;
int BIT[si][si];

void updateTree(int x, int y, int vl){
	while (y <= n){
		BIT[x][y] += vl;
		y += (y & -y);
	}
}
void update(int x, int y, int vl){
	while (x <= n){
		updateTree(x, y, vl);
		x += (x & -x);
	}
}
int getTree(int x, int y){
	int sum = 0;
	while (y > 0){
		sum += BIT[x][y];
		y -= (y & -y);
	}
	return sum;
}
int get(int x, int y){
	int sum = 0;
	while (x > 0){
		sum += getTree(x, y);
		x -= (x & -x);
	}
	return sum;
}

int main()
{
	Emsawy();
	bool ok = 1;
	int x, y, A, x0, y0;
	while (sf2(n,n) && ok){
		while (sf(m) && ok){
			if (m == 1){
				sf3(x, y, A);
				x++, y++;
				update(x, y, A);
			}
			else if (m == 2){
				sf2(x0, y0);
				sf2(x, y);
				x++, y++, x0++, y0++;
				int A = get(min(x0, x) - 1, max(y0, y)); int A0 = get(max(x0, x), max(y0, y));
				int B = get(min(x0, x) - 1, min(y0, y) - 1); int B0 = get(max(x0, x), min(y0, y) - 1);
				printf("%d\n", A0 - A - B0 + B);
			}
			else ok = 0;
		}

	}
	return 0;
}
