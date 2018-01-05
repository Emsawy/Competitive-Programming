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


class ColorfulRabbits {
public:
	int getMinimum(vector <int> replies) {
		map<int, int>mp;
		for (int i = 0; i < replies.size(); i++){
			mp[replies[i]] ++;
		}
		int ans = 0;
		for (auto it : mp){
			int tot = it.first + 1;
			ans += ceil((it.second * 1.0) / tot) * tot;
		}
		return ans;
	}
};
