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
int n, m, k, t, c , i;

double sto(string s){
	stringstream ss;
	ss << s;
	double ret;
	ss >> ret;
	return ret;
}
bool valid(char s){
	return (s == '-' || s == '+' || isdigit(s) || s == '.');
}
string s;
double go(){

	while (i < s.size()){

		double p = 0;
		string r = "";
		while (i < s.size() && (s[i] == ' ' || s[i] == ')')) i++;
		if (s[i] == '('){
			i++;
			while (i < s.size() && s[i] == ' ') i++;
			while (i < s.size() && valid(s[i])) r += s[i], i++;
			p = sto(r);
			double e1 = go();
			double e2 = go();
			return p * (e1+e2) + (1 - p) * (e1-e2);
		}
		if (valid(s[i])){
			while (i < s.size() && valid(s[i])) r += s[i], i++;
			p = sto(r);
			return p;
		}
	}
}
int main()
{
	Emsawy();
	while (getline(cin,s)){
		if (s[0] == '(' && s[1] == ')') break;
		double res;
		if (s[0] != '(')
			res = sto(s);
		else 
			res = go();
		printf("%0.2f\n", res);
		i = 0;
	}
	return 0;
}

