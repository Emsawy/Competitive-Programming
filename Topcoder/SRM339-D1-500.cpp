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


class TestBettingStrategy {
public:
	int _goalSum;
	double _prob;
	double dp[1001][51][51];
	double ans(int sm, int ro, int pr) {
		sm = min(sm, _goalSum);
		if (sm == _goalSum) return 1;
		if (ro == 0) return 0;
		if (dp[sm][ro][pr] != -1) return dp[sm][ro][pr];
		int bet = (1 << pr);
		if (sm - bet < 0) return 0;
		return dp[sm][ro][pr] = _prob * ans(sm + bet, ro - 1, 0) + (1 - _prob) * ans(sm - bet, ro - 1, pr + 1);

	}
	double winProbability(int initSum, int goalSum, int rounds, int prob) {
		_goalSum = goalSum;
		_prob = prob / 100.0;
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 51; j++) {
				for (int k = 0; k < 51; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		return ans(initSum, rounds, 0);
	}
};
