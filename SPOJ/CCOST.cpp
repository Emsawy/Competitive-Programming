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
const ll N = (1 << 24);
int n, m, k, w;

ll tr[N];
ll get(int idx) {
	idx++;
	ll res = 0;
	while (idx > 0) {
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

enum T {
	Bottom,Tree, Top
};
struct Event {
	int y;
	T t;
	union{
        struct{
            int l, r, idx;
        };
        struct{
            int x, price;
        };
    };
} ev[N];
int sorted[N];
ll ans[N];

int main() {

	Emsawy();
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int x, y, x1, y1, vl, i;
		for (i = 0; i < n; i++) {
			cin >> x >> y >> vl;
			ev[i] = {y,Tree, x, vl};
		}
		cin >> m;
		for (; i < m * 2 + n; i++) {
			cin >> x >> y >> x1 >> y1;
			int id = (i - n) / 2;
			ev[i] = {y, Bottom, x, x1,id};
			ev[++i] = {y1, Top, x, x1,id};
		}
		iota(sorted, sorted + i, 0);
		sort(sorted, sorted + i,
				[](int a, int b) {
					if(make_pair(ev[a].y,ev[a].t) < make_pair(ev[b].y,ev[b].t)) return 1;
					else return 0;
				});

		for (int j = 0; j < i; j++) {
			Event &e = ev[sorted[j]];
			if (e.t == Tree)
				add(e.x, e.price);
			else if (e.t == Bottom)
				ans[e.idx] -= get(e.r) - get(e.l - 1);
			else if (e.t == Top)
				ans[e.idx] += get(e.r) - get(e.l - 1);
		}
		for (int i = 0; i < m; i++)
			cout << ans[i] << "\n";
		memset(tr, 0, sizeof tr);
		memset(ans, 0, sizeof ans);
	}

	return 0;
}
