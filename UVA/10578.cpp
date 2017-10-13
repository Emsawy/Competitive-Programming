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
const ll mod = 10056, oo = ll(1e9);

V<V<pii> > adj;
int n, m, k, t, c;

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

int remofe(int mask, int id){
	int ret = 0, mul = 1;
	while (mask > 0){
		id--;
		if (id <= 0)
			ret += (mul * ((mask % 5) - 1)) , id = oo;
		else
			ret += (mul * (mask % 5));
		mul *= 5;
		mask /= 5;
	}
	return ret;
}

int dp[32][15624 + 1][2];
int go(int sum, int mask,bool pl){
	if (sum > 31)
		return (pl ? 0 : 1);
	int id = 1, cpy = mask;
	int &ret = dp[sum][mask][pl];
	if (ret != -1) return ret;
	ret = pl;
	while (cpy > 0){
		if (cpy % 5 > 0){
			if (pl)
				ret &= go(sum + id, remofe(mask, id), !pl);
			else
				ret |= go(sum + id, remofe(mask, id), !pl);
		}
		id++;
		cpy /= 5;
	}
	return ret;
}
int main()
{
	Emsawy();
	string s;
	while (cin>>s){
		int sum = 0, mask = 15624;
		for (int i = 0; i < s.size(); i++){
			int dig = s[i] - '0';
			sum += dig;
			mask = remofe(mask, dig);
		}
		clr(dp, -1);
		int ret = go(sum, mask, 0);
		cout << s << " ";
		if (ret && s.size() % 2 == 0) puts("A");
		else if (ret && s.size() % 2 == 1) puts("B");
		else if (!ret && s.size()% 2 == 0) puts("B");
		else if (!ret && s.size()% 2 == 1) puts("A");
	}

	return 0;
}
