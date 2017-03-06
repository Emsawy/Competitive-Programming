#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include <algorithm>
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
using namespace std;
#define V vector
typedef long long ll;
/*
- i get the edges which will make the MST
*/
int n, m, k , x[950] , y[950] , parent[950] , rnk[950] , nodes = 0 , print = 0;
bool ok[950][950];
struct edge{
	ll dis, l, r;
	edge(){};
	edge(int A, int B){
		l = A, r = B;
		int a = x[A], b = y[A] , c = x[B] , d = y[B];
		dis = (a - c)* (a - c) + (b - d)* (b - d);
	}
	bool operator <(const edge & a) const{ // 1 2 3
		return dis < a.dis;
	}
};
void Make_set(int i){
	parent[i] = i;
	rnk[i] = 0;
}
int FindSet(int x){
	if (x == parent[x]) return x;
	parent[x] = FindSet(parent[x]);
}
void Union(int u, int v){
	int e = FindSet(u), o = FindSet(v);
	if (e == o) return;
	if (print) cout << u+1 << " " << v+1 << endl;
	nodes--;
	if (rnk[e] > rnk[o]) parent[o] = e;
	else{
		parent[e] = o;
		if (rnk[e] == rnk[o]) rnk[o]++;
	}
}

int main()
{
	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++){
			scanf("%d%d", x + i, y + i);
		}
		for (int i = 0; i < n; i++)
			Make_set(i);
		nodes = n;
		scanf("%d", &m);
		int u, v;
		for (int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			u--, v--;
			ok[u][v] = ok[v][u] = 1;
			Union(u, v);
		}
		V<edge>ed;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (ok[i][j]) continue;
				ed.push_back(edge(i, j));
			}
		}
		print = 1;
		sort(ed.begin() , ed.end());
		for (int i = 0; i < ed.size() ; i++){
			Union(ed[i].l, ed[i].r);
		}
	}
	return 0;
}
