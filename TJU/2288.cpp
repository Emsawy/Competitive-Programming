#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
#define V vector
typedef long long ll;
/*
- i get the edges which will make the MST
*/
int n, m, k;
struct point{
	int x, y , node;
	point(){}; 
	point(int X, int Y , int Node){
		x = X, y = Y , node = Node;
	}
};
struct edge{
	point a, b;
	ll dis;
	edge(){};
	edge(point A, point B){
		a = A, b = B;
		dis = (A.x - B.x)* (A.x - B.x) + (A.y - B.y)* (A.y - B.y);
	}
	bool operator <(const edge & a) const{ // 1 2 3
		return dis > a.dis;
	}
};
struct UnionFind{
	vector<int> rank, F;
	int comp;
	UnionFind(int n){
		rank = vector<int>(n);
		F = vector<int>(n);
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

int main()
{
	while (cin >> n){
		V<point>v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i].x >> v[i].y;
			v[i].node = i;
		}
		priority_queue<edge>pq;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				pq.push(edge(v[i], v[j]));
			}
		}
		UnionFind f(n);
		cin >> m;
		int l , r;
		for (int i = 0; i < m; i++){
			cin >> l >> r;
			l--, r--;
			f.union_set(l, r);
		}
		V<edge>ans;
		while (!pq.empty()){
			if (f.union_set(pq.top().a.node, pq.top().b.node)){
				ans.push_back(pq.top());
			}
			pq.pop();
		}
		for (int i = 0; i < ans.size(); i++){
			cout<< ans[i].a.node + 1 <<" " << ans[i].b.node + 1 << endl;
		}
	}
	return 0;
}
