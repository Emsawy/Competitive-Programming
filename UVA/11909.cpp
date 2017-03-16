/*
- Get the angle (A) between l and h divided by 2.
- if the given angle is smaller than A, then the answer is (l * w * h - (traingle with angle A and side l))
- if the given angle is not smaller thant A, then the answer is the (traingle with angle (90-A) and side h). 
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
int n, m, k, t, c;
double toRadian(double degree){
	return (degree * PI / 180.0);
}
double toDegree(double radian){
	if (radian < 0) radian += PI * 2.0;
	return (radian * 180.0 / PI);
}
double fixAngle(double A){
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}
bool dcmp(double a, double b){
	if (abs(a - b) <= EPS) return 1;
	if (a < b) return 1;
	return 0;
}
double get0(double ang, double l, double w){
	double x = sin(toRadian(ang)) * l / sin(toRadian(90 - ang));
	return l * w * x / 2.0;
}
double get1(double ang, double h, double w){
	double x = sin(toRadian(ang)) * h / sin(toRadian(90 - ang));
	return h * w * x / 2.0;
}
double getAngle_A_abc(double a, double b, double c){
	return acos(fixAngle((b*b + c*c - a*a) / (2 * b*c)));
}
int main()
{
	Emsawy();
	double l, w, h, ang;
	while (cin >> l >> w >> h >> ang){
		double th =  toDegree( getAngle_A_abc(h, l, sqrt(l * l + h * h)) );
		double vol = 0;
		if (dcmp(ang, th) == 1)
			vol = l * w * h - get0(ang, l, w);
		else
			vol = get1(90 - ang, h, w);
		printf("%0.3f mL\n", vol);
	}
	return 0;
}
