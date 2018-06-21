/*

I get the internal polygon after cutting with the trip size,
First, beside the mid point for every three point I get the internal new point after cutting with the trip size.
example:
	Point a,b,c in the polygon, after cutting will apear a new internal point (P) beside the point b (with get_point(a,b,c) function in my code).
	Vector (a,b) will make a another paralle internal vector(a',b') above vector(a,b) and distance (d) between the two vectors.
aslo 	Vector (b,c) will make a another paralle internal vector(b',c') above vector(b,c) and distance (d) between the two vectors.
	After that i get the intersection point of the vector (a',b') and vector (b',c') to get the point (P).
	The new polyon after cutting will be the points (P) connected.

	The preprocessing to get the vector (a',b') for vector(a,b)
		The function get_vetical_up_line(a,b) return a point with distance d away from the vector(a,b) and it's side for the vector(a,b) must be negative to ensure that the returned point will be inside the polygon.
		Now i can get the vector(a',b') with get_vetical_up_line(a,b) + vec(a,b).
		So now i have two vectors (a',b') and (b',c') inside the polygon for every three point in the polygon (a,b,c) and i can get their intersection(P).
		Then calculating the inside plygon area with polygonArea() function.

Note: i used the angleCMP to sort the polygon point in CW oreder to insure the every theree point is connected.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
const ll N = 3000 + 5;
int n, m, k, w, h;

const double eps = 1e-12, PI = acos(-1);
#define O            const point &
#define CD           const double &
#define EQ(a, b)     (fabs((a) - (b)) <= eps) /* equal to */
#define LT(a, b)     ((a) < (b)-eps) /* less than */
#define sz(v)	     ((int)((v).size()))

double INF = 1e100;
double EPS = 1e-12;


struct point
{
	double x, y;
	point() :x(0), y(0) {}
	point(O p) : x(p.x), y(p.y) {}
	point(const pair<double, double> & p) : x(p.first), y(p.second) {}
	point(CD a, CD b) : x(a), y(b) {}

	bool operator<(const point& p) const {
		return EQ(x, p.x) ? LT(y, p.y) : LT(x, p.x);
	}

	bool operator>(const point& p) const {
		return EQ(x, p.x) ? LT(p.y, y) : LT(p.x, x);
	}

	bool operator == (O p) const { return EQ(x, p.x) && EQ(y, p.y); }
	bool operator != (O p) const { return !(*this == p); }
	bool operator <= (O p) const { return !(*this > p); }
	bool operator >= (O p) const { return !(*this < p); }
	point operator + (O p) const { return point(x + p.x, y + p.y); }
	point operator - (O p) const { return point(x - p.x, y - p.y); }
	point operator + (CD v) const { return point(x + v, y + v); }
	point operator - (CD v) const { return point(x - v, y - v); }
	point operator * (CD v) const { return point(x * v, y * v); }
	point operator / (CD v) const { return point(x / v, y / v); }
	point & operator += (O p) { x += p.x; y += p.y; return *this; }
	point & operator -= (O p) { x -= p.x; y -= p.y; return *this; }
	point & operator += (CD v) { x += v; y += v; return *this; }
	point & operator -= (CD v) { x -= v; y -= v; return *this; }
	point & operator *= (CD v) { x *= v; y *= v; return *this; }
	point & operator /= (CD v) { x /= v; y /= v; return *this; }
	friend point operator + (CD v, O p) { return p + v; }
	friend point operator * (CD v, O p) { return p * v; }

	double norm() const { return x * x + y * y; }
	double abs() const { return sqrt(x * x + y * y); }
	double arg() const { return atan2(y, x); }
	double dot(O p) const { return x * p.x + y * p.y; }
	double cross(O p) const { return x * p.y - y * p.x; }
	double proj(O p) const { return dot(p) / p.abs(); } //onto p
	point rot90() const { return point(-y, x); }
	point normalize() const {
		return (EQ(x, 0) && EQ(y, 0)) ? point(0, 0) : (point(x, y) / abs());
	}
	point rotateCW(CD t) const {
		//rotate t radians CW about origin
		return point(x * cos(t) + y * sin(t), y * cos(t) - x * sin(t));
	}
	point rotateCCW(CD t) const {
		//rotate t radians CCW about origin
		return point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t));
	}
	point rotateCW(O p, CD t) const {
		//rotate t radians CW about point p
		return (*this - p).rotateCW(t) + p;
	}
	point rotateCCW(O p, CD t) const {
		//rotate t radians CCW about point p
		return (*this - p).rotateCCW(t) + p;
	}
	point reflect(O p) const {
		//reflect across point p
		return point(2 * p.x - x, 2 * p.y - y);
	}
	point reflect(O p, O q) const {
		//reflect across the line containing points p and q
		if (p == q) return reflect(p);
		point r(*this - p), s = q - p;
		r = point(r.x * s.x + r.y * s.y, r.x * s.y - r.y * s.x) / s.norm();
		r = point(r.x * s.x - r.y * s.y, r.x * s.y + r.y * s.x) + p;
		return r;
	}
	point vec(O b) const {
		// make a vector from a to b
		return b - *(this);
	}
	bool same(O b) const {
		// is the two vector equals
		return ((b - *this).dot(b - *this) <= eps);
	}
	bool isCollinear(O b, O c) const {
		// Is the points on the same line?
		return fabs((b - *this).cross(c - *this)) < eps;
	}
	int pointState(O b, O c) const {
		/*
		if the point up, down or on the line
		didn't work untill now
		you can use the standard equation Ax+By+C=0
		*/
		double w = fabs((b - *this).cross(c - *this));
		return (w == 0 ? 0 : (w > 0 ? 1 : -1));
	}
	bool ispointOnRay(O b, O c) const {
		if (!(*this).isCollinear(b, c)) return 0;
		return LT(0.0, (b - (*this)).dot(c - (*this)));
	}
	bool ispointOnSegment(O b, O c) const {
		return (*this).ispointOnRay(b, c) && b.ispointOnRay((*this), c);
	}
	double distToLine(O b, O c) const {
		double dist = (b - (*this)).cross(c - (*this)) / (b - (*this)).abs();
		return fabs(dist);
	}
	double distToSegment(O b, O c) const {
		point a(x, y);
		double d1, d2; // (w*cos(0)/vl) == (w*vl*cos(0)/vl*vl) == (w.vl / vl*vl)
		point v1 = b - a, v2 = c - a;
		if ((d1 = v1.dot(v2)) < 0) return (c - a).abs();
		if ((d2 = v1.dot(v1)) <= d1) return (c - b).abs();
		double t = d1 / d2;
		return (c - (a + v1 * t)).abs();
	}
	bool intersectionSegments(O b, O c, O d, point &intersect) const {
		point a(x, y);
		double d1 = (a - b).cross(d - c), d2 = (a - c).cross(d - c), d3 = (a - b).cross(a - c);
		if (fabs(d1) < eps) return 0;
		double t1 = d2 / d1, t2 = d3 / d1;
		intersect = a + (b - a) * t1;
		if (t1 < -eps || t1 > 1 + eps || t2 < -eps || t2 > 1 + eps)
			return 0;
		return 1; // segment with segment
	}
	int ccw(O b, O c) const {
		/*
		ccw -> +1				   angle > 0
		cw  -> -1				   angle < 0
		before line -> ccw -> -1   angle = 0
		after  line -> cw  -> +1   angle = 0
		undifined -> 0			   angle = 0
		*/
		point a(x, y), v1(b - a), v2(c - a);
		if (v1.cross(v2) > +eps) return +1;
		if (v1.cross(v2) < -eps) return -1;
		if (v1.x*v2.x < -eps || v1.y*v2.y < -eps) return -1;
		if (v1.norm() < v2.norm() - eps) return +1;
		return 0;
	}
	bool intersect(O b, O c, O d) const {
		point a(x, y);
		bool x = (a == b), y = (c == d);
		if (x && y) return a == c;
		if (x)      return c.ccw(d, a) == 0;
		if (y)      return a.ccw(b, c) == 0;

		x = (a.ccw(b, c) * a.ccw(b, d) <= 0);
		y = (c.ccw(d, a) * c.ccw(d, b) <= 0);

		return x && y;
	}
	double findCircl(O b, O c, point &center) const {
		// don't call it if (a,b,c) is Collinear
		point a(x, y);
		point m1 = (a + b) * 0.5, v1 = (b - a), pv1 = point(v1.y, -v1.x);
		point m2 = (b + c) * 0.5, v2 = (b - c), pv2 = point(v2.y, -v2.x);
		point end1 = m1 + pv1, end2 = m2 + pv2;
		m1.intersectionSegments(end1, m2, end2, center);
		return (a - center).abs();
	}
	V<point> intersectionLineCircle(O p1, O C, CD r)const {
		// get the intersection of line pass with a circle (at most 2 points)
		point p0(x, y);
		double a = (p1 - p0).dot(p1 - p0), b = 2 * (p1 - p0).dot(p0 - C), c = (p0 - C).dot(p0 - C) - r*r;
		double f = b * b - 4 * a*c;  //sqrt(b^2 - 4*a*c)
		V<point> v;
		if (EQ(f, 0) || LT(0, f)) {
			if (EQ(f, 0)) f = 0; // have one solution
			double t1 = (-b + sqrt(f)) / (2 * a);
			double t2 = (-b - sqrt(f)) / (2 * a);
			v.push_back(p0 + t1*(p1 - p0));
			if (!EQ(f, 0))
				v.push_back(p0 + t2*(p1 - p0)); // have two solution
		}
		return v;
	}
	V<point> intersectionCircleCircle(CD r1, O c2, CD r2) const {
		point c1(x, y);
		if (c1.same(c2) && EQ(r1, r2) && LT(0, r1)) // LT mean that they are not two points
			return V<point>(3, c1); // infinity number of intersections

		double ang1 = (c2 - c1).arg(), ang2 = Angle_A_abc(r2, r1, (c2 - c1).abs());

		if (::isnan(ang2)) // mean that either they are intersect in one point or not intersect
			ang2 = 0;

		complex<double> p = polar(r1, ang1 + ang2);
		V<point> v(1, point(p.real(), p.imag()) + c1);

		if (!EQ((v[0] - c1).dot(v[0] - c1), r1*r1) || !EQ((v[0] - c2).dot(v[0] - c2), r2*r2)) // the arnt intersect
			return V<point>();

		p = polar(r1, ang1 - ang2);
		v.push_back(point(p.real(), p.imag()) + c1);

		if (v[0].same(v[1]))
			v.pop_back();

		return v;
	}
	double fixAngle(CD A)const {
		return A > 1 ? 1 : (A < -1 ? -1 : A);
	}
	pair<point, double> MEC(V<point> & pt, V<point> & On) const {
		if (pt.empty() && On.size() == 2) {
			pair<point, double> cnt;
			cnt.first = (On[0] + On[1]) / 2;
			cnt.second = (On[0] - cnt.first).abs();
			return cnt;
		}
		if (On.size() == 3) {
			pair<point, double> cnt;
			cnt.second = On[0].findCircl(On[1], On[2], cnt.first);
			return cnt;
		}
		if (pt.empty()) {
			pair<point, double> cnt;
			if (!On.empty()) {
				cnt.first = On[0];
				cnt.second = 0;
			}
			return cnt;
		}
		point tmp = pt.back();
		pt.pop_back();
		pair<point, double> ret = MEC(pt, On);

		if ((tmp - ret.first).abs() > ret.second) {
			On.push_back(tmp);
			ret = MEC(pt, On);
			On.pop_back();
		}
		pt.push_back(tmp);
		return ret;
	}
	double dis(O b) const {
		point a(x, y);
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
	double triangleArea(O b, O c) const {
		// return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x; Another solution
		point a(x, y);
		double p0 = a.dis(b), p1 = a.dis(c), p2 = b.dis(c);
		double s = (p0 + p1 + p2) / 2.0;
		return sqrt((s - p0) * (s - p1) * (s - p2) * s);
	}
	double radiusForTraingleInsideCircle(O p1, O p2)const {
		point p0(x, y);
		double a = p0.dis(p1), b = p0.dis(p2), c = p1.dis(p2);
		return (a * b * c) / (4.0 * p0.triangleArea(p1, p2));
	}
	double toRadian(CD degree)const {
		return (degree * PI / 180.0);
	}
	double toDegree(double radian)const {
		if (radian < 0) radian += PI * 2.0;
		return (radian * 180.0 / PI);
	}
	double Angle_A_abc(CD a, CD b, CD c)const {
		// a*a = b*b + c*c + 2abcos(A)
		return acos(fixAngle((b*b + c*c - a*a) / (2 * b*c)));
	}
	double Side_a_bAB(CD b, CD A, CD B)const {
		// sin(A)/a = sin(B)/b = sin(C)/c
		return (sin(A) * b) / sin(B);
	}
	double Angle_A_abB(CD a, CD b, CD B)const {
		return asin(fixAngle((a * sin(B)) / b));
	}
	double traingleAreaWithMedians(CD m1, CD m2, CD m3)const {
		if (m1 <= 0 || m2 <= 0 || m3 <= 0) return -1; // impossipole
		double s = 0.5 * (m1 + m2 + m3);
		double medians_area = (s * (s - m1) * (s - m2) * (s - m3));
		double area = 4.0 / 3.0 * sqrt(medians_area);
		if (medians_area <= 0.0 || area <= 0.0) return -1; // impossipole
		return area;
	}
	double radiusForCircleInsideTraingle(point p0, point p1, point p2) {
		double a = p0.dis(p1), b = p0.dis(p2), c = p1.dis(p2);
		double s = (a + b + c) / 2.0;
		return sqrt((s - a) * (s - b) * (s - c) / s);
	}
	double areaOfCircle(double r)const {
		return PI * r * r;
	}
	double circumferenceOfCircle(double r)const {
		return PI * r * 2.0;
	}
	double areaOfSector(double angle, double r)const {
		return (angle / 360.0) * areaOfCircle(r);
	}
	double areaOfSectorArc(double angle, double r)const {
		return (angle / 360.0) * circumferenceOfCircle(r);
	}
	double angle0(O o, O b)const {
		point a(x, y);
		point v1(a - o), v2(b - o);
		return acos(fixAngle(v1.dot(v2) / v1.abs() / v2.abs()));
	}
	bool isInsidePoly(V<point> &p)const {
		point pt(x, y);
		double angleSum = 0;
		p.push_back(p[0]);
		for (int i = 0; i < int(p.size()) - 1; i++) {
			if (p[i].ccw(p[i + 1], pt) == 0) {
				p.pop_back();
				return true;
			}
			angleSum += p[i].angle0(pt, p[i + 1]) * pt.ccw(p[i], p[i + 1]);
		}
		p.pop_back();
		// Answer is either 0(outside) or 2PI (inside)
		//  return fabs(fabs(angleSum) - 2 * PI) < eps;
		return fabs(angleSum) > PI;
	}
	bool isInsidePolyBest(V<point> &p) const {
		point p0(x, y);
		int wn = 0;
		for (int i = 0; i<int(p.size()); i++) {
			point cur = p[i], nxt = p[(i + 1) % int(p.size())];
			if (cur.ispointOnSegment(nxt, p0))
				return true;
			if (cur.y <= p0.y) {
				// why (nxt.y > p0.y) not (nxt.y >= p0.y) !! take care of this well
				// UPD: because if >= will not hapen because of the line ispointOnsegment()
				if (nxt.y > p0.y && (nxt - cur).cross(p0 - cur) > eps)
					++wn;
			}
			else {
				if (nxt.y <= p0.y && (nxt - cur).cross(p0 - cur) < -eps)
					--wn;
			}
		}
		return wn != 0;
	}


	friend double norm(O p) { return p.norm(); }
	friend double abs(O p) { return p.abs(); }
	friend double arg(O p) { return p.arg(); }
	friend double dot(O p, O q) { return p.dot(q); }
	friend double cross(O p, O q) { return p.cross(q); }
	friend double proj(O p, O q) { return p.proj(q); }  //!
	friend point rot90(O p) { return p.rot90(); }
	friend point normalize(O p) { return p.normalize(); }
	friend point rotateCW(O p, CD t) { return p.rotateCW(t); }
	friend point rotateCCW(O p, CD t) { return p.rotateCCW(t); }
	friend point rotateCW(O p, O q, CD t) { return p.rotateCW(q, t); }
	friend point rotateCCW(O p, O q, CD t) { return p.rotateCCW(q, t); }
	friend point reflect(O p, O q) { return p.reflect(q); }
	friend point reflect(O p, O a, O b) { return p.reflect(a, b); } //!
	friend point vec(O a, O b) { return a.vec(b); }
	friend bool same(O a, O b) { return a.same(b); } //!
	friend bool isCollinear(O a, O b, O c) { return a.isCollinear(b, c); }
	friend int pointState(O a, O b, O c) { return a.pointState(b, c); } // XX
	friend bool ispointOnRay(O a, O b, O c) { return a.ispointOnRay(b, c); }
	friend bool ispointOnSegment(O a, O b, O c) { return a.ispointOnSegment(b, c); }
	friend double distToLine(O a, O b, O c) { return a.distToLine(b, c); }
	friend double distToSegment(O a, O b, O c) { return a.distToSegment(b, c); }
	friend bool intersectionSegments(O a, O b, O c, O d, point &in) { return a.intersectionSegments(b, c, d, in); }
	friend int ccw(O a, O b, O c) { return a.ccw(b, c); }
	friend bool intersect(O a, O b, O c, O d) { return a.intersect(b, c, d); }
	friend double findCircl(O a, O b, O c, point &center) { return a.findCircl(b, c, center); }
	friend V<point> intersectionLineCircle(O p0, O p1, O C, CD r) { return p0.intersectionLineCircle(p1, C, r); }
	friend V<point> intersectionCircleCircle(O c1, CD r1, O c2, CD r2) { return c1.intersectionCircleCircle(r1, c2, r2); }
	friend double fixAngle(CD A, O X) { return X.fixAngle(A); }
	friend pair<point, double> MEC(V<point> & pt, V<point> & On, O X) { return X.MEC(pt, On); }
	friend double dis(O a, O b) { return a.dis(b); }
	friend double triangleArea(O a, O b, O c) { return a.triangleArea(b, c); }
	friend double radiusForTraingleInsideCircle(O p0, O p1, O p2) { return p0.radiusForTraingleInsideCircle(p1, p2); }
	friend double toRadian(CD degree, O X) { return X.toRadian(degree); }
	friend double toDegree(double radian, O X) { return X.toDegree(radian); }
	friend double Angle_A_abc(CD a, CD b, CD c, O X) { return X.Angle_A_abc(a, b, c); }
	friend double Side_a_bAB(CD b, CD A, CD B, O X) { return X.Side_a_bAB(b, A, B); }
	friend double Angle_A_abB(CD a, CD b, CD B, O X) { return X.Angle_A_abB(a, b, B); }
	friend double traingleAreaWithMedians(CD m1, CD m2, CD m3, O X) { return X.traingleAreaWithMedians(m1, m2, m3); }
	friend double areaOfCircle(CD r, O X) { return X.areaOfCircle(r); }
	friend double circumferenceOfCircle(CD r, O X) { return  X.circumferenceOfCircle(r); }
	friend double areaOfSector(CD angle, CD r, O X) { return X.areaOfSector(angle, r); }
	friend double areaOfSectorArc(CD angle, CD r, O X) { return X.areaOfSectorArc(angle, r); }
	friend double angle0(O a, O o, O b) { return a.angle0(o, b); }
	friend bool isInsidePoly(V<point> &p, O pt) { return pt.isInsidePoly(p); }
	friend bool isInsidePolyBest(V<point> &p, O pt) { return pt.isInsidePolyBest(p); }


	friend std::ostream & operator << (std::ostream & out, O p) {
		out << "(";
		out << (fabs(p.x) < eps ? 0 : p.x) << ", ";
		out << (fabs(p.y) < eps ? 0 : p.y) << ") ";
		return out;

	}
};


double polygonArea(V<point> & points) {
	double a = 0;
	for (int i = 0; i < points.size(); i++)
		a += cross(points[i], points[(i + 1) % sz(points)]);
	return fabs(a / 2.0);
}
double d;
ll side(point a, point b, point c) {
	ll x1 = b.x - a.x, y1 = b.y - a.y;
	ll x2 = c.x - a.x, y2 = c.y - a.y;
	ll p = y2 *x1 - x2 * y1;
	if (p == 0) return 0;
	else if (p > 0) return 1;
	else return -1;
}
point get_vetical_up_line(point a, point b) {
	point ba = b;
	while (side(a, b, ba) >= 0) {
		point t = vec(a, ba);
		t = point(t.y, -t.x);
		ba = a + t;
	}
	point vba = vec(a, ba);
	return a + vba * (d / abs(vba));
}
point get_point(point a, point b, point c) {
	point l = get_vetical_up_line(a, b);
	point l2 = l + vec(a, b);
	point r = get_vetical_up_line(b, c);
	point r2 = r + vec(b, c);
	point ret;
	intersectionSegments(l, l2, r, r2, ret);
	return ret;
}

struct angleCMP {
	point center;
	angleCMP(point c) : center(c) {}
	bool operator() (O p0, O p1) const {
		if (EQ(cross(p0 - center, p1 - center), 0)) {
			if (fabs(p0.y - p1.y) < eps)
				return p0.x < p1.x;
			return p0.y < p1.y;
		}
		return cross(p0 - center, p1 - center) < 0;  // how this!!!!
	}
};

int main() {

	Emsawy();
	while (cin >> d >> n) {
		if (d + n <= 0) break;
		V<point> pt(n);
		for (int i = 0; i < n; i++) {
			cin >> pt[i].x >> pt[i].y;
		}
		for (int i = 0; i < pt.size(); i++) {
			if (pt[0] < pt[i])
				swap(pt[0], pt[i]);
		}
		sort(pt.begin() + 1, pt.end(), angleCMP(pt[0]));

		V<point> ans;
		for (int i = 0; i < n; i++) {
			ans.push_back(get_point(pt[i], pt[(i + 1) % n], pt[(i + 2) % n]));
		}
		cout <<fixed << setprecision(3) << polygonArea(ans) << endl;
	}
	return 0;
}
