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


class QuadraticLaw {
public:
	long long getTime(long long d) {
		
		long long  s = 0, e = 1e9 + 100, res = 0;
		while (s <= e){
			long long mid = (s + e) / 2;
			if (mid + mid * mid <= d) s = mid + 1, res = mid;
			else e = mid - 1;
		}
		return res;
	}
};
