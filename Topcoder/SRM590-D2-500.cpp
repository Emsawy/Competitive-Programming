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

int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

class FoxAndGo {
public:
	
	vector<string> bord;
	int vs[30][30], cnt[30][30];
	int cur;
	void go(int i, int j){
		cnt[i][j]++;
		vs[i][j] = cur;
		for (int k = 0; k < 4; k++){
			int x = i + dx[k], y = j + dy[k];
			if (x < 0 || x >= bord.size() || y < 0 || y >= bord.size() || bord[x][y] == 'x' || vs[x][y] == cur|| bord[x][y] == '.') continue;
			go(x, y);
		}
	}
	int maxKill(vector <string> board) {
		bord = board;
		cur = 0;
		fill(vs[0], vs[0] + 30 * 30, 0);
		fill(cnt[0], cnt[0] + 30 * 30, 0);
		int ans = 0;
		for (int i = 0; i < bord.size(); i++){
			for (int j = 0; j < bord[i].size(); j++){
				if (bord[i][j] == '.'){
					cur++;
					go(i, j);
				}
			}
		}
		vector<int> cr(cur + 1);
		for (int i = 0; i < bord.size(); i++){
			for (int j = 0; j < bord.size(); j++){
				if (bord[i][j] == 'o'){
					if (cnt[i][j] == 0) ans++;
					else if(cnt[i][j]  == 1) cr[vs[i][j]] ++;
				}
			}
		}
		int mx = 0;
		for (int i = 1; i < cr.size(); i++){
			mx = max(mx, cr[i]);
		}
		return ans + mx;
	}
};
