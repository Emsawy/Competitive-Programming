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

typedef long long ll;

class WolfInZooDivTwo {
public:
	vector<int> l[400], r[400];
	int n, mod = 1e9 + 7;
	ll dp[303][303];
	ll go(int nd, int lst){
		if (nd == n) return 1;
		ll &ret = dp[nd][lst+1];
		if (ret != -1) return ret;
		ret = 0;
		for (int i = 0; i < l[nd].size(); i++){
			if (l[nd][i] > lst)
				return ret = go(nd + 1, nd) % mod;
		}
		ret = (ret + go(nd + 1, nd)) % mod; 
		ret = (ret + go(nd + 1, lst)) % mod;
		return ret;
	}
	int count(int N, vector <string> L, vector <string> R) {
		int a,b;
		string sl, sr;
		for (int i = 0; i < L.size(); i++) sl += L[i];
		for (int i = 0; i < R.size(); i++) sr += R[i];

		stringstream A, B;
		A << sl;
		B << sr;
		while (A >> a && B >> b)
			l[b].push_back(a);

		n = N;
		for(int i = 0;i<303;i++)
			for(int j = 0;j<303;j++)
				dp[i][j] = -1;
		
		return go(0, -1);

	}
};
