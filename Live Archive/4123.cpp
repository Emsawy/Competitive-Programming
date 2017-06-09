/*
  It is a dp counting problem, some analysis needed to reach the answer.
  Constructino the string of angels need some rules.
  rulse:
        No two O's consecutive to help the garden to see all the corners(take some unvalid example and see what happens).
        At least there is 4 more R's for colsing the circl, mean R's - O's = 4.
        For each O the is must followed with R ( for returning to it's dirction after O , use example to see that) (RRRORROR).
        Corner Case, String may be cyclic, OR may occurs but not seen, like this (ORRRRR or RRRRRO)
*/


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

V<V<pii> > adj;
int n, m, k, t, c , O = 1 , R = 0;
ll dp[1001][2100][2][2];
ll go(int id, int seq, bool st , bool en){
	if (id == n) {
		if (seq == 4 && (st == R || en != O))
			return 1;
		return 0;
	}
	ll &ret = dp[id][seq + 1000][st][en];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(id + 1, seq + 1, st , R);
	if (en != O)
		ret += go(id + 1, seq - 1, st, O);
	return ret;
}
int main()
{
	Emsawy();
	while (cin >> n){
		if (n == 0) break;
		if (n < 4 || n % 2){
			cout << "Case " << ++c << ": 0" << endl;
			continue;
		}
		clr(dp, -1);
		cout << "Case " << ++c << ": " << go(1, 1, R, R) + go(1, -1, O, O) << endl;
	}
	return 0;
}
