

/*
  It is helpfull.
  http://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm162
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

using namespace std;


class JarBox {
public:
	int numJars(int radius, int woodlength) {
		int ans = 0;
		for (int i = 0; i < woodlength; i ++){
			double h = i * sqrt(3) * radius + 2 * radius , w = (woodlength - h * 2) / 2;
			if (h * 2 + w * 2 > woodlength) break;
			int rows = i + 1;
			int inrow = w / (2 * radius);
			if ((w - (inrow * 2 * radius)) - radius < 1e-9)
				ans = max(ans, int(((rows + 1) / 2) * inrow + (rows / 2) * (inrow - 1)));
			else
				ans = max(ans, int(rows * inrow));
		}
		return ans;
	}
};
