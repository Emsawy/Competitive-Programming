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


class NarrowPassage2Easy {
public:
	vector<int> f;
	int mx;
	set<vector<int> > mp;
	int dfs(vector<int> v){
		if (mp.find(v) != mp.end()) return 0;
		mp.insert(v);
		int ret = 1;
		for (int i = 0; i + 1 < v.size(); i++){
			if (f[v[i]] + f[v[i + 1]] <= mx){
				swap(v[i], v[i + 1]);
				ret += dfs(v);
				swap(v[i], v[i + 1]);
			}
		}
		return ret;
	}
	int count(vector <int> size, int maxSizeSum) {
		vector<int> v;
		for (int i = 0; i < size.size(); i++)
			v.push_back(i);
		mx = maxSizeSum;
		f = size;
		return dfs(v);
	}
};
