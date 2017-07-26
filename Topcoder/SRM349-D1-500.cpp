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


class DiceGames {
public:
	vector<int> side;
	long long dp[33][33];
	long long go(int id, int lst){
		if (id == side.size())
			return 1;
		long long &ret = dp[id][lst];
		if (ret != -1) return ret;
		ret = 0;
		for (int i = min(lst, side[id]); i >= 1; i--){
			ret += go(id + 1, i);
		}
		return ret;
	}

	long long countFormations(vector <int> sides) {
		sort(sides.rbegin() , sides.rend());
		side = sides;
		for (int i = 0; i < 33; i++)
			for (int j = 0; j < 33; j++)
				dp[i][j] = -1;
		return go(0, 32);
	}
};
