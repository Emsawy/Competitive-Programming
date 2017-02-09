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


class RaceManagement {
public:
	vector<int>p, a;
	long long sum = 0;
	double res = 0;
	double go(int id, int win, int cnt, double po , double f){
		if (id == a.size()){
			if (cnt == 1) return (((sum - a[win]) - a[win] * f) * (po / 100.0));
			return (sum * (po / 100.0));
		}
		double ret = 0;
		ret += go(id + 1, id, cnt + 1, (po * p[id]) / 100 , f);
		ret += go(id + 1, win, cnt, (po * (100 - p[id])) / 100 , f);
		return ret;
	}
	bool comp(double a, double b){
		if (abs(a - b) <= 1e-9) return 1;
		if (a < b) return 1;
		return 0;
	}
	double getPayoutFactor(vector <int> probability, vector <int> amounts, int minimumMoney) {
		p = probability, a = amounts;
		for (int i = 0; i < a.size(); i++)
			sum += a[i];

		int lp = 100000;
		double s = -10000, e = 10000, rs = 0;
		while (lp --){
			double mid = (s + e) / 2.0;
			if (comp(go(0, -1, 0, 100, mid), minimumMoney)) e = mid - 1, rs = mid;
			else s = mid + 1 ;
		}
		if (go(0, -1, 0, 100, 1e6) >= minimumMoney && go(0, -1, 0, 100, -1e6) >= minimumMoney) return -2;
		if (rs < 0) return -1.0;
		return rs;
	}
};
