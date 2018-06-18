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
typedef long long ll;

class LastDigit {
public:
	ll op(ll mid) {
		ll sum = 0, clone = mid;
		while (clone) {
			sum += clone;
			clone /= 10;
		}
		return sum;
	}
	long long findX(long long S) {
		ll s = 0, e = 1e18, res = 0;
		while (s <= e) {
			ll mid = (s + e) / 2;
			ll sum = op(mid);
			if (sum >= S) {
				res = mid;
				e = mid - 1;
			}
			else
				s = mid + 1;
		}
		if (op(res) == S) return res;
		return -1;
	}
};
