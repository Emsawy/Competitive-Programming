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


class BagsOfGold {
public:

	vector<int> v;
	int dp[55][55][2];
	int go(int l, int r, bool ml){
		if (l > r) return 0;
		int &ret = dp[l][r][ml];
		if (ret != -1) return ret;
		ret = -1e9;
		if (ml){
			ret = 1e9;
			ret = min(ret, go(l + 1, r, !ml) + v[l] * -1);
			ret = min(ret, go(l, r - 1, !ml) + v[r] * -1);
			return ret;
		}
		ret = max(ret, go(l + 1, r, !ml) + v[l]);
		ret = max(ret, go(l, r - 1, !ml) + v[r]);
		return ret;
	}
	int netGain(vector <int> bags) {
		v = bags;
		for (int i = 0; i < 55; i++)
			for (int j = 0; j < 55; j++)
				dp[i][j][0] = dp[i][j][1] = -1;

		return go(0, bags.size() - 1, 0);
	}
};
