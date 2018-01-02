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
struct edge{
	int u, v, w;
	edge(){}
	bool operator < (const edge & l) const{
		if (w < l.w) return 1;
		return 0;
	}
};
struct  UnionFind
{
	vector<int>F, rank;
	int cmp = 0;
	UnionFind(int n){
		F = vector<int>(n);
		rank = vector<int>(n);
		for (int i = 0; i < n; i++)
			F[i] = i;
		cmp = n;
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
		x = find_set(x);
		y = find_set(y);
		if (x == y) return 0;
		link(x, y);
		cmp--;
		return 1;
	}
};
class TimeTravellingSalesman {
public:
	long long determineCost(int N, vector <string> roads) {
		char sep;
		vector<edge> v;
		string s;
		for (int i = 0; i < roads.size(); i++){
			s += roads[i];
		}

		v.push_back(edge());
		stringstream ss;
		ss << s;
		while (ss >> v.back().u >> sep >> v.back().v >> sep >> v.back().w){
			v.push_back(edge());
		}
		v.pop_back();
		sort(v.begin(), v.end());
		UnionFind uf(N);
		int ans = 0;
		for (int i = 0; i < v.size(); i++){
			if (uf.union_set(v[i].u, v[i].v)){
				ans += v[i].w;
			}
		}
		return (uf.cmp == 1? ans: -1);
	}
};
