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
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<pair<int, int> > > adj;
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
double n, m;

const double PI = acos(-1.0);
struct point{
	int x, y;
	point(int X, int Y){
		x = X, y = Y;
	}
};
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
// sin(A)/a = sin(B)/b = sin(C)/c
double getSide_a_bAB(double b, double A, double B){
	return (sin(A) * b) / sin(B);
}
double getAngle_A_abB(double a, double b, double B){
	return asin(fixAngle((a * sin(B)) / b));
}
// a*a = b*b + c*c + 2abcos(A)
double getAngle_A_abc(double a, double b, double c){
	return acos(fixAngle((b*b + c*c - a*a) / (2 * b*c)));
}
double dis(point a, point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double dis(double a, double b){
	return sqrt(a * a + b * b);
}
double triangleArea(point p0, point p1, point p2){
	double a = dis(p0, p1), b = dis(p0, p2), c = dis(p1, p2);
	double s = (a + b + c) / 2.0;
	return sqrt((s - a) * (s - b) * (s - c) * s);
}
double traingleAreaWithMedians(double m1, double m2, double m3){
	if (m1 <= 0 || m2 <= 0 || m3 <= 0) return -1; // impossipole
	double s = 0.5 * (m1 + m2 + m3);
	double medians_area = (s * (s - m1) * (s - m2) * (s - m3));
	double area = 4.0 / 3.0 * sqrt(medians_area);
	if (medians_area <= 0.0 || area <= 0.0) return -1; // impossipole
	return area;
}
double radiusForTraingleInsideCircle(point p0, point p1, point p2){
	// his points on the boundry of the circle
	double a = dis(p0, p1), b = dis(p0, p2), c = dis(p1, p2);
	return (a * b * c) / (4.0 * triangleArea(p0, p1, p2));
}
double radiusForCircleInsideTraingle(point p0, point p1, point p2){
	double a = dis(p0, p1), b = dis(p0, p2), c = dis(p1, p2);
	double s = (a + b + c) / 2.0;
	return sqrt((s - a) * (s - b) * (s - c) / s);
}
double areaOfCircle(double r){
	return PI * r * r;
}
double circumferenceOfCircle(double r){
	return PI * r * 2.0;
}
double areaOfSector(double angle, double r){
	return (angle / 360.0) * areaOfCircle(r);
}
double areaOfSectorArc(double angle, double r){
	return (angle / 360.0) * circumferenceOfCircle(r);
}

bool comp(double a, double b){
	if (abs(a - b) <= 1e-5) return 1;
	if (a < b) return 1;
	return 0;
}
bool valid(double mid){
	double x = n * mid, y = m * mid;
	double r = dis(x / 2, y / 2);
	double ang = atan(y / x), pri = 2 * PI * r;
	double A = pri * (ang / (PI * 2));
	long double tot = x * 2.0 + A * 4;
	return comp(tot, 400);
}
int main()
{
	Emsawy();
	char c;
	int cc = 1;
	while (cin >> n >> c >> m){
		int p = 10000;
		double s = 0, e = 1e9, res;
		while (p--){
			double mid = (s + e) / 2.0;
			if (valid(mid)) s = mid + 1, res = mid;
			else e = mid - 1;
		}
		cout << "Case " << cc++ << ": " << fixed << setprecision(10) << res * n << " " << res * m << endl;
	}
	return 0;
}
