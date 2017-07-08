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

V<V<pii> > adj;
ll n, m, k, t, c , ag , lw, mx = 1.1e18;
ll valid(ll age, ll mid){
	
	ll p = 1, ret = 0;
	while (age){
		int dig = age % 10;
		age /= 10;
		if (dig && p > mx / dig || p*dig > mx - ret) return mx;
		ret += (p * dig);
		if (age && p > mx / mid) return mx;
		p *= mid;
	}
	return ret;
}
ll maxbase(ll age,ll low){
	ll s = 10, e = age, res;
	while (s <= e){
		ll mid = (s + e) / 2;
		if (valid(low, mid) > age)  e = mid - 1;
		else s = mid + 1, res = mid;
	}
	return res;
}
bool Okay(ll age, ll base){
	while (age){
		if (age%base > 9) return 0;
		age /= base;
	}
	return 1;
}


ll valid(ll mid, string s){
	ll ret = 0;
	for (int i = s.size() - 1; i >= 0; i--){
		if (ret > mx / mid || ret * mid > mx - (s[i] - '0')) return mx;
		ret = (ret * mid + (s[i] - '0'));
	}
	return ret;
}
ll size = 11111, base = 1;
ll yDIGITi(ll y, ll i){
	string st;
	while (i){
		st += (i % 10 + '0');
		i /= 10;
	}

	ll s = 10, e = mx, res = -mx - 100;
	while (s <= e){
		ll mid = (s + e) / 2;
		if (valid(mid, st) > y) e = mid - 1;
		else res = mid, s = mid + 1;
	}
	if (valid(res, st) == y) return res;
	return  -mx;
}
int main()
{
	Emsawy();
	while (cin >> ag >> lw){

		ll maxres = maxbase(ag, lw);

		if (maxres < 10000000){
			for (int i = maxres; i >= 10; i--){
				if (Okay(ag,i)){
					cout << i << endl;
					break;
				}
			}
			continue;
		}
		base = 10;
		for (int i = lw; i <= 1000; i++){
			base = yDIGITi(ag, i);
			if (base != -mx) break;
		}
		ll res = 0;
		for (int i = 1000000; i >= 10; i--){
			if (Okay(ag, i)){
				res = i;
				break;
			}
		}
		cout << max(res,base) << endl;
	
	}
	return 0;
}
