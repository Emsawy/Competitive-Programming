#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}
using namespace std;

struct state {
	int len, link;
	map<char, int>next;
};
const int MAXLEN = 200000 + 5;
struct SA {
	state st[MAXLEN * 2];
	int sz, last;

	void sa_init() {
		sz = last = 0;
		st[0].len = 0;
		st[0].link = -1;
		++sz;
	}

	void sa_extend(char c) {
		int cur = sz++;
		st[cur].len = st[last].len + 1;
		int p;
		for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
			st[p].next[c] = cur;

		if (p == -1)
			st[cur].link = 0;
		else {
			int q = st[p].next[c];
			if (st[p].len + 1 == st[q].len)
				st[cur].link = q;
			else {
				int clone = sz++;
				st[clone].len = st[p].len + 1;
				st[clone].next = st[q].next;
				st[clone].link = st[q].link;
				for (; p != -1 && st[p].next[c] == q; p = st[p].link)
					st[p].next[c] = clone;
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}
} sa;
int finals[MAXLEN * 2];
int dfs(int nd){
	if (finals[nd] != -1) return finals[nd];
	finals[nd] = sa.st[nd].next.find('$') != sa.st[nd].next.end();
	for (auto v : sa.st[nd].next){
		finals[nd] += dfs(v.second);
	}
	return finals[nd];
}
vector<vector<int> > tree;
char s[MAXLEN], c;
int n, m, kth, fob[MAXLEN * 2];
void go(int nd){
	for (auto u : tree[nd]){
		go(u);
		fob[nd] += fob[u];
	}
}
int main() {
	Emsawy();
	while (cin >> n){
		cin >> s;
		sa.sa_init();
		vector<char>v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
			sa.sa_extend(s[i]);
		}
		sa.sa_extend('$');
		memset(finals, -1, sizeof finals);
		dfs(0);
		int cur = 0;
		long long ans = 0;
		tree.resize(sa.sz);
		for (int i = 1; i < sa.sz; i++){
			tree[sa.st[i].link].push_back(i);
		}
		for (int i = 0; i < n; i++){
			cur = sa.st[cur].next[s[i]];
			if (v[i] == '1'){
				fob[cur]++;
			}
		}
		go(0);
		for (int i = 0; i < sa.sz; i++){
			ans = max(ans, sa.st[i].len * 1LL * (finals[i] - fob[i]));
		}
		cout << ans << endl;
	}
	return 0;
}
