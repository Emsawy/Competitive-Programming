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

	typedef long long ll;

	struct Node {
		Node * g[10];
		bool leaf;
	};


	void insert(Node * root, string s) {

		for (int i = s.size() - 1; i >= 0; i--) {
			if (root->g[s[i] - '0'] == NULL) {
				root->g[s[i] - '0'] = new Node();
			}
			root = root->g[s[i] - '0'];
		}
		root->leaf = 1;
	}
	ll ans = 0;
	void pw(int cnt) {
		int rem = 9 - cnt, cal = 1;
		while (rem--) {
			cal *= 10;
		}
		ans += cal;
	}
	void dfs(Node * root, int cnt = 0) {
		for (int i = 0; i < 10; i++) {
			if (root->g[i] != NULL) {
				if (root->g[i]->leaf) {
					pw(cnt + 1);
					continue;
				}
				dfs(root->g[i], cnt + 1);
			}
		}
	}

	double find(vector <string> goodSuffixes) {
		Node *root = new Node();
		for (int i = 0; i < goodSuffixes.size(); i++) {
			insert(root, goodSuffixes[i]);
		}
		dfs(root, 0);
		return ans / (1000000000.0);
	}
};
