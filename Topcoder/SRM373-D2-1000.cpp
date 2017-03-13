
/*
- I get the area of rectangles which contain one or more end point (it is easy task).
- when geting the area of rectagles which intersect segments, will apear three cases to check the intersection.
  1- if the segment is horizental. 
  2- if the segment is vertical.
  3- if the segment not horizental or vertical.
 - we must handle all cases.
 - http://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm373
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>

using namespace std;
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define rotate0(p,ang)	((p)*exp(point(0,ang)))
#define rotateA(p,ang,A)(rotate0(vec(A,p),ang)+A)
#define reflect0(v,m)	(conj((v)/(m))*(m))
#define pii				pair<int,int>
#define V				vector
#define MP				make_pair
#define x				real()
#define y				imag()

typedef complex<double> point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

class RectangleCrossings {
public:

	void getInput(vector<string>r, vector<pair<point, point> > &ret){
		string s;
		for (int i = 0; i < r.size(); i++){
			istringstream ss(r[i]);
			ret.push_back(pair<point, point>());
			int a, b;
			ss >> a >> b; ret.back().first = point(a, b);
			ss >> a >> b; ret.back().second = point(a, b);
		}
	}
	bool btw(pair<point, point> a, point p){
		int ok = 0;
		if (p.x > min(a.first.x, a.second.x) && p.x < max(a.first.x, a.second.x)) ok++;
		if (p.y > min(a.first.y, a.second.y) && p.y < max(a.first.y, a.second.y)) ok++;
		return (ok == 2);
	}
	int Area(point a, point b){
		return abs(a.x - b.x) * abs(a.y - b.y);
	}
	bool isVert(point a , point b){
		return dcmp(a.x , b.x) == 0;
	}

	bool isHor(point a, point b){
		return dcmp(a.y, b.y) == 0;
	}
	int dcmp(double a, double b){
		return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
	}
	bool isCollinear(point a, point b, point c){
		return fabs((cp(b - a, c - a))) < EPS;
	}
	bool ispointOnRay(point a, point b, point c){
		if (!isCollinear(a, b, c)) return 0;
		return (dcmp(dp(b - a, c - a), 0.0) == 0) || (dcmp(dp(b - a, c - a), 0.0) == 1);
	}
	bool ispointOnSegment(point a, point b, point c){
		return ispointOnRay(a, b, c) && ispointOnRay(b, a, c);
	}
	bool intersectionSegments(point a, point b, point c, point d){
		double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
		if (fabs(d1) < EPS) return 0;
		double t1 = d2 / d1, t2 = d3 / d1;
		if (t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
			return 0;
		return 1; // segment with segment
	}
	vector <int> countAreas(vector <string> rectangles, vector <string> segments) {
		vector<pair<point , point > > r, s;
		getInput(rectangles, r);	
		getInput(segments, s);
		int endp = 0, intr = 0;
		for (int i = 0; i < r.size(); i++){
			for (int j = 0; j < s.size(); j++){
				if (btw(r[i], s[j].first) || btw(r[i], s[j].second)){
					endp += Area(r[i].first, r[i].second);
					break;
				}
			}
		}
		for (int i = 0; i < r.size(); i++){
			point p0 (r[i].first.x , r[i].second.y), p1 = r[i].second, p2(r[i].second.x , r[i].first.y), p3 = r[i].first;
			int ok = 0;
			for (int j = 0; j < s.size(); j++){
				if (btw(r[i], s[j].first) || btw(r[i], s[j].second)){
					ok = 0;
					break;
				}
				if (isHor(s[j].first, s[j].second)){
					if (ispointOnSegment(p0, p1, s[j].first) || ispointOnSegment(p0, p1, s[j].second)) ok++;
					if (ispointOnSegment(p3, p2, s[j].first) || ispointOnSegment(p3, p2, s[j].second)) ok++;
					if (intersectionSegments(p0, p3, s[j].first, s[j].second)) ok++;
					if (intersectionSegments(p1, p2, s[j].first, s[j].second)) ok++;
				}
				else if (isVert(s[j].first, s[j].second)){
					if (ispointOnSegment(p0, p3, s[j].first) || ispointOnSegment(p0, p3, s[j].second)) ok++;
					if (ispointOnSegment(p1, p2, s[j].first) || ispointOnSegment(p1, p2, s[j].second)) ok++;
					if (intersectionSegments(p0, p1, s[j].first, s[j].second)) ok++;
					if (intersectionSegments(p3, p2, s[j].first, s[j].second)) ok++;
				}
				else {
					if (intersectionSegments(p0, p1, s[j].first, s[j].second)) ok++;
					if (intersectionSegments(p1, p2, s[j].first, s[j].second)) ok++;
					if (intersectionSegments(p2, p3, s[j].first, s[j].second)) ok++;
					if (intersectionSegments(p3, p0, s[j].first, s[j].second)) ok++;
				}
			}
			if (ok){
				intr += Area(r[i].first, r[i].second);
			}
		}

		vector<int>ret;
		ret.push_back(endp);
		ret.push_back(intr);
		return ret;
	}
};
