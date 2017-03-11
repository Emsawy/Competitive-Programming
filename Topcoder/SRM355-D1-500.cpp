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

using namespace std;
/*
http://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm355
*/

class Tetrahedron {
public:
	double dis(double x, double y, double a, double b){
		return sqrt((x - a) * (x - a) + (y - b) * (y - b));
	}
	bool comp(double a, double b){
		if (abs(a - b) <= 1e-9) return 1;
		if (a < b) return 1;
		return 0;
	}
	string exists(vector <string> d) {
		int t;
		vector<vector<int> > v(4);
		for (int i = 0; i < d.size(); i++){
			stringstream ss;
			ss << d[i];
			while (ss >> t) v[i].push_back(t);
		}
		int AB = v[0][1];
		int AC = v[0][2];
		int AD = v[0][3];
		int BC = v[1][2];
		int BD = v[1][3];
		int CD = v[2][3];

		// point p2
		double A1 = ((AC * AC) + (AB * AB) - (BC * BC)) / (2.0 * AC * AB);  // Cos(theta) between AC and AB
		double X1 = AC * A1;
		double Y1 = sqrt(AC * AC - X1 * X1);

		// point p3
		double A2 = ((AD * AD) + (AB * AB) - (BD * BD)) / (2.0 * AD * AB); // Cos(theta) between AD and AB
		double X2 = AD * A2;
		double Y2 = sqrt(AD * AD - X2 * X2);

		double mn = dis(X1, Y1, X2, Y2);
		double mx = dis(X1, Y1, X2, -Y2);

		if (comp(CD, mx) && comp(mn, CD)) return "YES";
		return "NO";
	}
};
