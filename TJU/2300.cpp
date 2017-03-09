
/*
- I used the concept of matrices to get the answer because of the number of iterations is very larg.
- Initial matrix is filled with zeros and the first row with ai.
- Transition matrix is filled with zeros and the last column from last row is bi , and filled the second diogonal with ones to shift the sequence one shift.
- Use the power function to get the trasition matrix with the power of (i-th) then multiply it with initial matrix.
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
const ll mod = ll(10000), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k;

const int MAX = 105;
struct matrix{
	int N, M, g[MAX][MAX];
	matrix(int N_, int M_){
		N = N_, M = M_;
	}
	matrix(int N_, int M_, int v){
		N = N_, M = M_;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				g[i][j] = v;

	}
	matrix operator * (const matrix &b) const{
		matrix c(N, b.M);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < b.M; j++){
				c.g[i][j] = 0;
				for (int k = 0; k < N; k++){
					c.g[i][j] = (c.g[i][j] + (g[i][k] * 1LL * b.g[k][j])) % mod;
				}
			}
		}
		return c;
	}

	matrix pw_matrix(const matrix &b, long long p){
		if (p == 1) return b;
		matrix me = pw_matrix(b, p / 2LL);
		me = me * me;
		if (p % 2 == 1) me = me * b;
		return me;
	}
};

int main()
{
	Emsawy();
	while (cin >> k){
		if (k == 0) break;
		matrix init(k, k, 0), transition(k, k, 0);
		for (int i = 0; i < k; i++)
			cin >> init.g[0][i];

		for (int i = k - 1; i >= 0; i--)
			cin >> transition.g[i][k - 1];

		for (int i = 1; i < k; i++)
			transition.g[i][i - 1] = 1;
		
		cin >> n;
		if (n < k)
			cout << init.g[0][n] << endl;
		else
			cout << (init * (transition = transition.pw_matrix(transition, n - k + 1))).g[0][k-1] << endl;
	}
	return 0;
}
