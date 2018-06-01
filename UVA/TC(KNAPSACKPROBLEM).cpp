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

class KnapsackProblem {
public:
	int c, n;
	vector<int> a, b, g;
	void goa(int id , int sum = 0) {
		if (sum > c) return;
		if (id >= g.size() / 2) {
			a.push_back(sum);
			return;
		}
		goa(id + 1, sum + g[id]);
		goa(id + 1, sum);
	}
	void gob(int id , int sum = 0) {
		if (sum > c) return;
		if (id >= n) {
			b.push_back(sum);
			return;
		}
		gob(id + 1, sum + g[id]);
		gob(id + 1, sum);
	}
	int numberOfWays(vector <int> x, int C) {
		n = x.size();
		g = x;
		c = C;
		goa(0, 0);
		gob(n / 2, 0);
		int ans = 0;
		sort(b.begin(), b.end());
		for (int i = 0; i < a.size(); i++) {
			int pos = upper_bound(b.begin(), b.end(), c - a[i]) - b.begin();
			ans += pos;
		}

		return ans;
	}
};
