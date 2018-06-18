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


class QuizShow {
public:

	int a, b, c;
	vector<int> sc;
	double Prob(int id, int mask) {
		if (id == 3) {
			int s1 = sc[0], s2 = sc[1], s3 = sc[2];

			if ((mask >> 0) & 1)
				s1 += a;
			else
				s1 -= a;

			if ((mask >> 1) & 1)
				s2 += b;
			else
				s2 -= b;

			if ((mask >> 2) & 1)
				s3 += c;
			else
				s3 -= c;

			if (s1 > s2 && s1 > s3) return 1;
			return 0;
		}
		return Prob(id + 1, mask | (1 << id)) * 0.5 + Prob(id + 1, mask) * 0.5;
	}
	
	int wager(vector <int> scores, int wager1, int wager2) {
		sc = scores;
		b = wager1;
		c = wager2;
		int ans = 0;
		double mx = 0;
		for (int i = 0; i <= scores[0]; i++) {
			a = i;
			double ret = Prob(0, 0);
			if (mx < ret) {
				mx = ret;
				ans = i;
			}
		}
		return ans;
	}
};
