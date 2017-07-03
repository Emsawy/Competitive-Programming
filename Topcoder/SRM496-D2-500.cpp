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


class ColoredStrokes {
public:
	int getGPo(vector<string>&g){
		for (int i = 0; i < g.size(); i++){
			for (int j = 0; j < g[i].size(); j++){
				if (g[i][j] == 'G'){
					return i * g[0].size() + j;
				}
			}
		}
		return -1;
	}
	int getLeast(vector <string> picture) {
		vector<string> g = picture;
		int ret = 0 , ans = 0;
		while ((ret = getGPo(g)) != -1){
			int x = ret / g[0].size(), y = ret % g[0].size();
			int po = y + 1;
			while (po < g[x].size() && (g[x][po] == 'G' || g[x][po] == 'R')){
				if (g[x][po] == 'G') g[x][po] = 'B';
				else g[x][po] = '.';
				po++;
			}
			po = y - 1;
			while (po >= 0 && (g[x][po] == 'G' || g[x][po] == 'R')){
				if (g[x][po] == 'G') g[x][po] = 'B';
				else g[x][po] = '.';
				po--;
			}
			g[x][y] = 'B';
			ans++;
		}

		for (int i = 0; i < g.size(); i++){
			for (int j = 0; j < g[i].size(); j++){
				if (g[i][j] == 'R'){
					int x = i, y = j, po = y + 1;
					while (po < g[x].size() && g[x][po] == 'R'){
						g[x][po] = '.';
						po++;
					}
					po = y - 1;
					while (po >= 0 && g[x][po] == 'R'){
						g[x][po] = '.';
						po--;
					}
					g[x][y] = '.';
					ans++;
				}
			}
		}


		for (int i = 0; i < g.size(); i++){
			for (int j = 0; j < g[i].size(); j++){
				if (g[i][j] == 'B'){
					int x = i, y = j, po = x + 1;
					while (po < g.size() && g[po][y] == 'B'){
						g[po][y] = '.';
						po++;
					}
					po = x - 1;
					while (po >= 0 && g[po][y] == 'B'){
						g[po][y] = '.';
						po--;
					}
					g[x][y] = '.';
					ans++;
				}
			}
		}

		return ans;
	}
};
