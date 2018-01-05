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


class TomekPhone {
public:
	int minKeystrokes(vector <int> frequencies, vector <int> keySizes) {
		vector<int> f = frequencies;
		vector<int> key = keySizes;
		sort(f.begin(), f.end());
		sort(key.rbegin(), key.rend());
		int ans = 0, st = 0;
		while (f.size()){
			if (key.size() == 0) return -1;
			ans += (ceil((st+1) / (1.0*key.size()))) * f.back();
			f.pop_back();
			key[st % key.size()] --;
			if (key[st % key.size()] <= 0){
				st -= (ceil((st + 1) / (1.0*key.size())));
				key.pop_back();
			}
			st++;
		}
		return ans;
	}
};
