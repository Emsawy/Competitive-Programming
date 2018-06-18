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


class PilingRectsDiv2 {
public:
	vector<int> _X, _Y;
	int _limit;
	int dp[51][201][201];

	int go(int id, int x, int y) {
		if (id >= _X.size()) {
			if (x * y >= _limit) return 0;
			return -100000000;
		}
		int &ret = dp[id][x][y];
		if (ret != -1) return ret;
		ret = -100000000;
		ret = max(ret, go(id + 1, min(x, _X[id]), min(y, _Y[id])) + 1);
		ret = max(ret, go(id + 1, min(x, _Y[id]), min(y, _X[id])) + 1);
		ret = max(ret, go(id + 1, x, y));
		return ret;
	}

	int getmax(vector <int> X, vector <int> Y, int limit) {
		_X = X;
		_Y = Y;
		_limit = limit;
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 201; j++) {
				for (int k = 0; k < 201; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		int ret = go(0, 200, 200);
		if (ret == 0) ret = -1;
		return ret;
	}
};
