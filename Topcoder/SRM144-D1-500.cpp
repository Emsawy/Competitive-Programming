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


class Lottery {
public:
	long long fac[10];
	long long go_00(long long n, int m){
		long long ret = 1;
		for (int i = 0; i < m; i++){
			ret *= n;
		}
		return ret;
	}
	long long go_11(long long n, int m){
		long long ret = 1;
		for (int i = n; i > n - m; i--){
			ret *= i * 1LL;
		}
		return ret / fac[m];
	}
	long long go_01(long long n, int m){
		long long ret = 1;
		for (int i = n; i > n - m; i--){
			ret *= i * 1LL;
		}
		return ret;
	}
	long long go_10(long long n, int m){
		n += (m - 1);
		long long ret = 1;
		for (int i = n; i > n - m; i--){
			ret *= i * 1LL;
		}
		return ret / fac[m];
	}

	vector <string> sortByOdds(vector <string> rules) {
		fac[0] = 1;
		for (int i = 1; i < 10; i++)
			fac[i] = fac[i - 1] * 1LL * i;
		vector<pair<long long,string > > ans;
		for (int i = 0; i < rules.size(); i++){
			string s;
			int n, m;
			char o, uq;
			stringstream ss;
			for (int j = 0; j < rules[i].size(); j++){
				if (rules[i][j] == ':') {
					rules[i][j] = ' ';
					break;
				}
				s += rules[i][j];
				rules[i][j] = ' ';
			}
			ss << rules[i];
			ss >> n >> m >> o >> uq;
			if (o == 'T' && uq == 'T')
				ans.push_back(make_pair(go_11(n, m),s));
			else if (o == 'T' && uq == 'F')
				ans.push_back(make_pair(go_10(n, m),s));
			else if (o == 'F' && uq == 'T')
				ans.push_back(make_pair(go_01(n, m),s));
			else
				ans.push_back(make_pair(go_00(n, m),s));
		}
		sort(ans.begin(), ans.end());
		vector<string> ret;
		for (int i = 0; i < ans.size(); i++){
			ret.push_back(ans[i].second);
		}
		return ret;
	}
};
