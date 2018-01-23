/*
	- every point is a node in graph you can construct.
	- then with splitting the node to two nodes and add a capacity between them 
	with the max in the problem for every node (i -> (i + n))
	- and run on the graph maxflow algo and get the answer for every node if that node is the destination node

*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
const ll N = 100000 + 5;
int n, m, k, w;


const int si = 110 * 2 + 10;
int g[si][si], vs[si], flow[si][si], cur = 1, cop[si][si];
int getpath(int str, int dis, int mx){
	if (str == dis)
		return mx;
	vs[str] = cur;
	for (int i = 0; i < si; i++){
		if (vs[i] == cur || flow[str][i] >= g[str][i]) continue;
		int ret;
		if (ret = getpath(i, dis, min(mx, g[str][i] - flow[str][i]))){
		//	cout << i << " ";
			flow[str][i] += ret;
			flow[i][str] -= ret;
			return ret;
		}
	}
	return 0;
}
int MaxFlow(int str, int dis){
	clr(flow, 0);
	int ans = 0, ret = 0;
	while (ret = getpath(str, dis, oo)){
		cur++, ans += ret;
		//cout << endl;
	}
	cur++;
	return ans;
}
struct Node{
	int x, y, n, mx;
};
double dist(Node &l, Node &r){
	return (l.x - r.x)*(l.x - r.x) + (l.y - r.y)*(l.y - r.y);
}
void _copy(){
	for (int i = 0; i <= n * 2; i++){
		for (int j = 0; j <= n * 2; j++){
			g[i][j] = cop[i][j];
		}
	}
}
int main() {

	Emsawy();
	int T;
	cin >> T;
	double d, eps = 1e-10;
	while (T--){
		cin >> n >> d;
		V<Node> in(n);
		for (int i = 0; i < n; i++){
			cin >> in[i].x >> in[i].y >> in[i].n >> in[i].mx;
		}
		int start = 2 * n;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (dist(in[i], in[j]) - d * d > eps) continue;
				//cout << i << " " << j << endl;
				cop[i][i + n] = in[i].mx;
				cop[j][j + n] = in[j].mx;
				cop[i + n][j] = oo;
				cop[j + n][i] = oo;
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++){
			cop[start][i] = in[i].n;
			sum += in[i].n;
		}
		bool done = 0;
		for (int i = 0; i < n; i++){
			_copy();
			if (MaxFlow(start, i) == sum){
				if (done) cout << " ";
				cout << i;
				done = 1;
			}
		}
		if (!done) cout << -1;
		cout << endl;
		clr(cop, 0);
		clr(g, 0);
	}
	return 0;
}
