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
const ll N = 50 + 5;
int n, m, k, w, a, b;
int g[N];

V<ll> l, r, now;

void go(int id, ll sum, bool ok) {
	if (id >= now.size()) {
		if (ok) l.push_back(sum);
		else r.push_back(sum);
		return;
	}
	go(id + 1, sum + now[id], ok);
	go(id + 1, sum, ok);
}

int main() {

	Emsawy();
	while (cin >> n >> a >> b) {
		for (int i = 0; i < n; i++)
			cin >> g[i];

		now.clear();
		for (int i = 0; i < n/2; i++) {
			now.push_back(g[i]);
		}
		go(0, 0, 1);

		now.clear();
		for (int i = n/2; i < n; i++) {
			now.push_back(g[i]);
		}
		go(0, 0, 0);
		ll ans = 0;
		sort(all(r));
		for (int i = 0; i < l.size(); i++) {
			int s = upper_bound(all(r), b - l[i]) - r.begin();
			int e = lower_bound(all(r), a - l[i]) - r.begin();
			ans += s - e;
		}
		cout << ans << endl;
	}
	return 0;
}






