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

/*
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

enum T {
	Tree, LL, LR, UL, UR
};
struct Event {
	int y, x, vl;
	T t;
	int idx;
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
			ev[i] = {y,x, vl, Tree, 0};
		}
		cin >> m;
		for (; i < m * 4 + n; i++) {
			cin >> x >> y >> x1 >> y1;
			int id = (i - n) / 4;
			ev[i] = {y - 1,x - 1, 0, LL,id};
			ev[++i] = {y - 1,x1,0,LR,id};
			ev[++i] = {y1,x - 1,0,UL,id};
			ev[++i] = {y1,x1,0,UR,id};
		}
		iota(sorted, sorted + i, 0);
		sort(sorted, sorted + i,
				[](int a, int b) {
					if(make_pair(make_pair(ev[a].y,ev[a].x), ev[a].t) < make_pair(make_pair(ev[b].y,ev[b].x), ev[b].t)) return 1;
					else return 0;
				});

		for (int j = 0; j < i; j++) {
			Event &e = ev[sorted[j]];
			if (e.t == Tree)
				add(e.x, e.vl);
			else if (e.t == LL)
				ans[e.idx] += get(e.x);
			else if (e.t == LR)
				ans[e.idx] -= get(e.x);
			else if (e.t == UL)
				ans[e.idx] -= get(e.x);
			else
				ans[e.idx] += get(e.x);
		}
		for (int i = 0; i < m; i++)
			cout << ans[i] << "\n";
		memset(tr, 0, sizeof tr);
		memset(ans, 0, sizeof ans);
	}

	return 0;
}

*/
