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

V<V<pair<int,int> > > adj;
const int N = 1e5 + 5;
int n, m, k, w, h;
ll g[N];


ll BIT[1 << 18];
void upd(int idx, int vl){
	idx++;
	for (int id = idx; id < N; id += (id & -id)){
		BIT[id] += vl;
	}
}

ll query(int idx){
	idx++;
	ll ret = 0;
	for (int id = idx; id > 0; id -= (id & -id)){
		ret += BIT[id];
	}
	return ret;
}
ll ans[N];
ll go(ll exp){
	ll ret = 0;
	ll rng = exp, factor = 1;
	for (int i = 1; i < n; ){
		int l = i, r = min(i + rng - 1, (ll) n - 1);
		ret += (query(r) - query(l - 1)) * factor;
		i = r + 1;
		rng *= exp;
		factor++;
	}
	return ret;
}

int main() {

	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> g[i];
		}
		sort(g, g + n);
		reverse(g, g + n);
		for (int i = 0; i < n; i++){
			upd(i, g[i]);
		}
		cin >> w;
		V<int>in(w);
		for (int i = 0; i < w;i++){
			cin >> in[i];
			ans[in[i]] = 1;
		}
		for (int i = 1; i < N; i++){
			if (ans[i] > 0){
				ans[i] = go(i);
			}
		}
		for (int i = 0; i < w; i++){
			cout << ans[in[i]] << " ";
		}
		cout << endl;
	}
	return 0;
}
