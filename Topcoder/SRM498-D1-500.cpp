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

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

class FoxStones {
public:

	int dis(int a, int b, int c, int d){
		return max(abs(a - c), abs(b - d));
	}
	int getCount(int N, int M, vector <int> sx, vector <int> sy) {
		swap(N, M);
		for (int i = 0; i < sx.size(); i++)
			sx[i]--, sy[i]--;
		long long ans = 1, mod = 1e9 + 9, fact[50000];
		fact[0] = fact[1] = 1;
		for (int i = 1; i < 50000; i++)
			fact[i] = (i * fact[i - 1]) % mod;
		vector<int> g[202][202];
		map<vector<int>, long long>mp;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				for (int k = 0; k < sx.size(); k++){
					g[i][j].push_back(dis(sy[k], sx[k], i, j));
				}
				mp[g[i][j]]++;
			}
		}
		for (auto it : mp){
			ans = (ans * fact[it.second]) % mod;
		}
		return ans;
	}
};
