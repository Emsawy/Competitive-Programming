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
	bool operator <(const edge &e) const {
		if (w > e.w) return 1;
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
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

class ActivateGame {
public:
	int get(char ch){
		if (isdigit(ch)) return ch - '0';
		else if (islower(ch)) return ch - 'a' + 10;
		else return ch - 'A' + 10 + 26;
	}
	int findMaxScore(vector <string> grid) {
		V<edge>edges;
		for (int i = 0; i < grid.size(); i++){
			for (int j = 0; j < grid[i].size(); j++){
				for (int k = 0; k < 4; k++){
					int x = dx[k] + i, y = dy[k] + j;
					if (x < 0 || x >= grid.size() || y < 0 || y >= grid[i].size()) continue;
					edges.push_back(edge(i * grid[i].size() + j, x * grid[i].size() + y, abs(get(grid[x][y]) - get(grid[i][j]))));
				}
			}
		}
		UnionFind uf(grid.size() * grid[0].size());
		int ans = 0;
		sort(edges.begin(), edges.end());
		for (int i = 0; i < edges.size(); i++){
			if (uf.union_set(edges[i].u, edges[i].v)){
				ans += edges[i].w;
			}
		}
		return ans;
	}
};
