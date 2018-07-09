#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;
#define all(c) ((c).begin()), ((c).end())
#define V vector


struct tree {
	int n;
	V<int>deg;
	V<V<int> > adj;
	queue<int> q;
	tree(int _n) {
		n = _n;
		adj.resize(n);
	}
	void dfs(int node, int lst) {
		deg[node] = adj[node].size();
		for (int i = 0; i < adj[node].size(); i++) {
			if (adj[node][i] == lst) continue;
			dfs(adj[node][i], node);
		}
		if (adj[node].size() == 1)
			q.push(node);
	}
	V<int> Tree(int node) {
		deg.clear();
		deg.resize(n);
		dfs(node, node);
		int N = n;
		while (N > 2) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				int p = q.front(); q.pop();
				for (int ch = 0; ch < adj[p].size(); ch++) {
					if (--deg[adj[p][ch]] == 1)
						q.push(adj[p][ch]);
				}
				N--;
			}
		}
		V<int> ret;
		if (q.size()) ret.push_back(q.front()), q.pop();
		if (q.size()) ret.push_back(q.front()), q.pop();
		return ret;
	}
};

string iso(tree &t, int node, int lst) {
	vector<string> ret;
	for (int i = 0; i < t.adj[node].size(); i++) {
		int ch = t.adj[node][i];
		if (ch != lst) {
			ret.push_back(iso(t, ch, node));
		}
	}
	sort(all(ret));
	string s;
	for (int i = 0; i < ret.size(); i++)
		s += ret[i];
	return "(" + s + ")";
}

bool solve(tree &S, tree &T) {
	auto x = S.Tree(0), y = T.Tree(0);
	if (x.size() != y.size()) return false;
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			if (x[i] == -1 || y[j] == -1) continue;
			if (iso(S, x[i], x[i]) == iso(T, y[j], y[j])) {
				return 1;
			}
		}
	}
	return 0;
}


int main() {
	int t; 
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "YES" << endl;
			continue;
		}
		tree S(n), T(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			S.adj[u - 1].push_back(v - 1);
			S.adj[v - 1].push_back(u - 1);

		}
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			T.adj[u - 1].push_back(v - 1);
			T.adj[v - 1].push_back(u - 1);
		}
		if (solve(S, T)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
