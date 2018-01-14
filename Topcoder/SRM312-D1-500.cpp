
/*
https://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm312
*/
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
stack<int>st;
const int N = 101;
int inStack[N], low[N], dfn[N], cmp[N], depth, cmpN, n, in[N];
vector<vector<int> > org, adj;
struct Targan
{
	Targan(){
		for (int i = 0; i < N; i++) dfn[i] = -1;
		depth = cmpN = 0;
	}
	void targan(int src){
		st.push(src);
		inStack[src] = 1;
		dfn[src] = low[src] = depth++;
		for (int i = 0; i < org[src].size(); i++){
			int child = org[src][i];
			if (dfn[child] == -1){
				targan(child);
				low[src] = min(low[src], low[child]);
			}
			else if (inStack[child])
				low[src] = min(dfn[child], low[src]);
		}
		if (low[src] == dfn[src]){
			int cur = -1;
			while (cur != src){
				cur = st.top();
				inStack[cur] = 0;
				cmp[cur] = cmpN;
				st.pop();
			}
			cmpN++;
		}
	}
	void computeCompGraph(){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < org[i].size(); j++){
				int x = cmp[i], y = cmp[org[i][j]];
				if (x != y){
					adj[x].push_back(y);
					in[y] = 1;
				}
			}
		}
	}
};

class AntarcticaPolice {
public:
	double minAverageCost(vector <int> costs, vector <string> roads) {
		n = costs.size();
		org.clear();
		org.resize(n);
		for (int i = 0; i < roads.size(); i++){
			for (int j = 0; j < roads[i].size(); j++){
				if (roads[i][j] == 'Y'){
					org[i].push_back(j);
				}
			}
		}
		Targan tr;
		double ret = 0;
		for (int i = 0; i < roads.size(); i++){
			if (dfn[i] == -1){
				tr.targan(i);
			}
		}
		adj.clear();
		adj.resize(cmpN);
		tr.computeCompGraph();
		vector<int> rem;
		map<int, int>mp;
		int all = 0;
		for (int i = 0; i < cmpN; i++){
			if (in[i] == 0){
				int cst = 1e9, idx = -1;
				for (int j = 0; j < roads.size(); j++){
					if (cmp[j] == i){
						if (cst >= costs[j]){
							cst = costs[j];
							idx = j;
						}
					}
				}
				ret += cst, all++;
				mp[idx] = 1;
			}
		}
		for (int i = 0; i < n; i++){
			if (mp[i]) continue;
			rem.push_back(costs[i]);
		}
		sort(rem.begin(), rem.end());
		for (int i = 0; i < rem.size(); i++){
			if ((ret + rem[i]) *  all  <= ret * (all + 1)){
				ret += rem[i];
				all++;
			}
		}
		return ret /= all;
	}
};
