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

int unCord[N];
map<int, int> cord;
pair<char, int> inp[N];

int tr[N];
int get(int idx) {
	idx++;
	int ret = 0;
	while (idx) {
		ret += tr[idx - 1];
		idx -= (idx & -idx);
	}
	return ret;
}
void add(int idx, int val) {
	idx++;
	while (idx <= N) {
		tr[idx - 1] += val;
		idx += (idx & -idx);
	}
}
int find(int t) {
	int s = 0;
	for (int sz = (N >> 1); sz; sz >>= 1) {
		if (tr[s + sz - 1] < t)
			t -= tr[(s += sz) - 1];
	}
	return s;
}
void init() {
	memset(tr, 0, sizeof tr);
}
int cnt(int val) {
	return get(val) - get(val - 1);
}
int sz() {
	return get(N - 1);
}
void insert(int val) {
	if (!cnt(val))
		add(val, 1);
}
void del(int val) {
	if (cnt(val) > 0)
		add(val, -1);
}
int getByIndex(int idx) {
	return find(idx);
}

int main() {

	Emsawy();
	int q;
	while (cin >> q) {
		init();
		for (int i = 0; i < q; i++) {
			cin >> inp[i].first >> inp[i].second;
		}
		int siz = 0;
		for (int i = 0; i < q; i++)
			if (inp[i].first != 'K')
				cord[inp[i].second];
		for (auto &it : cord) {
			it.second = siz++;
			unCord[it.second] = it.first;
		}
		for (int i = 0; i < q; i++) {
			switch (inp[i].first) {
			case 'I':
				insert(cord[inp[i].second]);
				break;
			case 'D':
				del(cord[inp[i].second]);
				break;
			case 'C':
				cout << get(cord[inp[i].second]) - cnt(cord[inp[i].second]) << endl;
				break;
			case 'K':
				if (inp[i].second > sz())
					cout << "invalid" << endl;
				else
					cout << unCord[find(inp[i].second)] << endl;
				break;
			}
		}
	}

	return 0;
}
