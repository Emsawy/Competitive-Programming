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


class BeautifulString {
public:
	int maximumLength(int countA, int countB, int maxA, int maxB) {
		long long ca = countA, cb = countB, ma = maxA, mb = maxB;
		if (ma == 0 && mb == 0) return 0;
		else if (ma == 0) return min(cb,mb);
		else if (mb == 0) return min(ca,ma);

		int ret = 0;
		long long mn = (ca + ma - 1) / ma - 1;
		long long mx = (ca + 1) * mb;
		if (cb >= mn){
			mx = min(mx, cb);
			ret = max((long long)ret, mx + ca);
		}

		mn = (cb + mb - 1) / mb - 1;
		mx = (cb + 1) * ma;
		if (ca >= mn){
			mx = min(mx, ca);
			ret = max((long long) ret, mx + cb);
		}
		return ret;
	}
};
