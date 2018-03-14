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

class TheLotteryBothDivs {
public:
	bool isPropersuffix(string &a, string &b) {
		if (a.size() <= b.size())
			return 0;
		if (a.substr(a.size() - b.size(), b.size()) == b)
			return 1;
		return 0;
	}
	double find(vector<string> goodSuffixes) {
		set<string> st;
		for(int i = 0;i<(int)goodSuffixes.size();i++){
			st.insert(goodSuffixes[i]);
		}
		vector<string> v;
		for (auto it : st) {
			bool ok = 0;
			for (auto itt : st) {
				ok |= isPropersuffix(it, itt);
			}
			if(!ok) v.push_back(it);
		}
		double sum = 0;
		for (auto it : v) {
			long long pw = 1;
			for (int i = 0; i < 9 - (int) it.size(); i++) {
				pw *= 10;
			}
			sum += pw;
		}
		return sum / 1000000000.0;
	}
};
