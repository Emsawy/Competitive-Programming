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
#define V vector
using namespace std;

struct edge{
	int u, v, w;
	edge(){}
	edge(int u, int v, int w) :u(u), v(v), w(w){}
	bool operator <(edge &e){
		if (w < e.w) return 1;
		return 0;
	}
};
struct UnionFind{
	V<int> rank, F;
	int comp;
	UnionFind(int n){
		rank = V<int>(n);
		F = V<int>(n);
		comp = n;
		for (int i = 0; i < n; i++)
			F[i] = i;
	}
	int find_set(int x){
		if (x == F[x]) return x;
		return F[x] = find_set(F[x]);
	}
	void link(int x, int y){
		if (rank[x] > rank[y]) swap(x, y);
		if (rank[x] == rank[y]) rank[y]++;
		F[x] = y;
	}
	bool union_set(int x, int y){
		x = find_set(x), y = find_set(y);
		if (x == y) return 0;
		link(x, y);
		comp--;
		return 1;
	}
};

class KingdomReorganization {
public:
	int get(char ch){
		if (isupper(ch)) return ch - 'A';
		return (ch - 'a') + 26;
	}
	int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
		V<edge> des, bul;
		for (int i = 0; i < kingdom.size(); i++){
			for (int j = i + 1; j < kingdom[i].size(); j++){
				if (kingdom[i][j] == '1')
					des.push_back(edge(i, j, get(destroy[i][j])));
				else
					bul.push_back(edge(i, j, get(build[i][j])));
			}
		}
		int ret = 0;
		UnionFind uf(kingdom.size());
		sort(des.rbegin(), des.rend());
		for (int i = 0; i < des.size(); i++){
			if (!uf.union_set(des[i].u, des[i].v)){
				ret += des[i].w;
			}
		}
		sort(bul.begin(), bul.end());
		for (int i = 0; i < bul.size(); i++){
			if (uf.union_set(bul[i].u, bul[i].v)){
				ret += bul[i].w;
			}
		}
		return ret;
	}
};
