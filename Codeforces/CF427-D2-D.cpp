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
const int MAXLEN = 100000 + 5;
struct SA {
	state st[MAXLEN * 2];
	int fpos[MAXLEN * 2];
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
		fpos[cur] = st[cur].len - 1;
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
				fpos[clone] = fpos[q];
				for (; p != -1 && st[p].next[c] == q; p = st[p].link)
					st[p].next[c] = clone;
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}
};
SA sa;
int finals_0[MAXLEN * 2], finals_1[MAXLEN * 2];
int dfs_0(int nd){
	if (finals_0[nd] != -1) return finals_0[nd];
	finals_0[nd] = sa.st[nd].next.find('#') != sa.st[nd].next.end();
	for (auto v : sa.st[nd].next){
		if (v.first == '#' || v.first == '$') continue;
		finals_0[nd] += dfs_0(v.second);
	}
	return finals_0[nd];
}
int dfs_1(int nd){
	if (finals_1[nd] != -1) return finals_1[nd];
	finals_1[nd] = sa.st[nd].next.find('$') != sa.st[nd].next.end();
	for (auto v : sa.st[nd].next){
		if (v.first == '$' || v.first == '#') continue;
		finals_1[nd] += dfs_1(v.second);
	}
	return finals_1[nd];
}

int main() {
	Emsawy();

	string a, b;
	while (cin >> a >> b){
		a += '#';
		a += b;
		a += '$';
		sa.sa_init();
		for (int i = 0; i < a.size(); i++){
			sa.sa_extend(a[i]);
		}
		memset(finals_0, -1, sizeof finals_0);
		memset(finals_1, -1, sizeof finals_1);
		dfs_0(0); 
		dfs_1(0);
		int ans = 1e9;
		for (int i = 0; i < sa.sz; i++){
			if (finals_0[i] == finals_1[i] && finals_0[i] == 1){
				ans = min(ans, sa.st[sa.st[i].link].len + 1);
			}
		}
		if (ans == 1e9) ans = -1;
		cout << ans << endl;
	}
	return 0;
}
