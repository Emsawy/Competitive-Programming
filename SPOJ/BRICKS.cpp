#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
#define V	         vector
const ll N = (1 << 18);
int n, m, k, w;

int tr[N];
int get(int idx) {
	int res = 0;
	while (idx) {
		res += tr[idx - 1];
		idx -= (idx & -idx);
	}
	return res;
}

void add(int idx, int val) {
	++idx;
	while (idx <= N) {
		tr[idx - 1] += val;
		idx += (idx & -idx);
	}
}

stack<int> st[26];
int abl[26][26];

int main() {

	Emsawy();
	int t;
	cin >> t;
	while (t--) {
		char u, v;
		string a, b;
		cin >> a >> b;
		cin >> m;
		memset(tr, 0, sizeof tr);
		memset(abl, 0, sizeof abl);
		fill(st, st + 26, stack<int>());

		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			abl[u - 'a'][v - 'a'] = abl[v - 'a'][u - 'a'] = 1;
		}
		for (int i = a.size() - 1; i >= 0; i--) {
			st[a[i] - 'a'].push(i);
		}
		ll ans = 0;
		for (int i = 0; i < (int) b.size(); i++) {
			int ch = b[i] - 'a';
			if (st[ch].empty()) {
				ans = -1;
				break;
			}
			int curPos = st[ch].top() - get(st[ch].top());
			for (int j = 0; j < 26; j++) {
				if (st[j].empty())
					continue;
				int posNow = st[j].top() - get(st[j].top());
				if (posNow < curPos && abl[j][ch] == 0) {
					ans = -1;
					break;
				}
			}
			if (ans == -1)
				break;
			else {
				ans += curPos;
				add(st[ch].top(), 1);
				st[ch].pop();
			}
		}
		cout << ans << endl;
	}

	return 0;
}
