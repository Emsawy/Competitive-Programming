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


class PipeCuts {
public:
	double probability(vector <int> weldLocations, int L) {
		double ans = 0;
		int cnt = 0;
		for (int i = 0; i < weldLocations.size(); i++) {
			for (int j = i + 1; j < weldLocations.size(); j++) {
				cnt++;
				int l = weldLocations[i], r = weldLocations[j];
				if (l > r)
					swap(l, r);
				if (l > L) {
					ans++;
					continue;
				}
				if (r - l > L) {
					ans++;
					continue;
				}
				if (100 - r > L) {
					ans++;
					continue;
				}
			}
		}
		return ans / cnt;
	}

};
