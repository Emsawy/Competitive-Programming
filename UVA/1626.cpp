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
int n, m, k, t, c;
string s;
int dp[101][101];
int go(int l, int r){
	if (l == r)
		return 1;
	if (l > r) 
		return 0;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	ret = oo;
	if (s[l] == '(' && s[r] == ')'){
		ret = min(ret , go(l + 1, r - 1));
	}
	if (s[l] == '[' && s[r] == ']'){
		ret = min(ret, go(l + 1, r - 1));
	}
	for (int i = l; i < r; i++){
		ret = min(ret, go(l, i) + go(i + 1, r));
	}
	return ret;
}
void print(int l, int r){
	if (l == r){
		if (s[l] == '(' || s[r] == ')') cout << "()";
		else cout << "[]";
		return;
	}
	if (l > r)
		return;
	
	if (s[l] == '(' && s[r] == ')'){
		if (go(l, r) == go(l + 1, r - 1)){
			cout << "(";
			print(l + 1, r - 1);
			cout << ")";
			return;
		}
	}
	if (s[l] == '[' && s[r] == ']'){
		if (go(l, r) == go(l + 1, r - 1)){
			cout << "[";
			print(l + 1, r - 1);
			cout << "]";
			return;
		}
	}

	for (int i = l; i < r; i++){
		if (go(l, r) == go(l, i) + go(i + 1, r)){
			print(l, i);
			print(i + 1, r);
			return;
		}
	}
}
int main()
{
	Emsawy();
	cin >> t;
	getchar();
	while (t--){
		getchar();
		getline(cin, s);
		clr(dp, -1);
		go(0, s.size() - 1);
		print(0, s.size() - 1);
		puts("");
		if (t) puts("");
	}
	return 0;
}
