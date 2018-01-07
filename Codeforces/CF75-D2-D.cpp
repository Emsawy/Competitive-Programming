#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1e17;

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
const ll N = 2.5e5 + 5;
int n, m, k, w;
struct Node
{
	V<ll> v;
	ll l, r, all, mx;
	Node(){
		l = r = mx = -oo;
		all = 0;
	}
	void mxmid(){
		ll cur = 0;
		for (int i = 0; i < v.size(); i++){
			cur += v[i];
			all += v[i];
			mx = max(mx, cur);
			cur = max(0LL, cur);
		}
	}
	void mxl(){
		ll cur = 0;
		for (int i = 0; i < v.size(); i++){
			cur += v[i];
			l = max(l, cur);
		}
		
	}
	void mxr(){
		ll cur = 0;
		for (int i = v.size() - 1; i >= 0; i--){
			cur += v[i];
			r = max(r, cur);
		}
	}
};
ll dp[N];

int main() {

	Emsawy();
	while (cin >> n >> m){
		V<Node> ord(n);
		for (int i = 0; i < n; i++){
			cin >> w;
			for (int j = 0; j < w; j++){
				cin >> k;
				ord[i].v.push_back(k);
			}
			ord[i].mxl();
			ord[i].mxr();
			ord[i].mxmid();
		}
		V<int> in(m);
		for (int i = 0; i < m; i++){
			cin >> in[i];
			in[i]--;
		}
		fill(dp, dp + N, -oo);
		dp[0] = ord[in[0]].l;
		for (int i = 1; i < m; i++){
			dp[i] = max(dp[i], ord[in[i - 1]].r + 0LL + ord[in[i]].l);
			dp[i] = max(dp[i], ((dp[i - 1] - ord[in[i - 1]].l) + ord[in[i - 1]].all) + ord[in[i]].l);
		}
		ll ans = -oo;
		for (int i = 0; i < m; i++){
			ans = max(ans, dp[i]);
			ans = max(ans, 0LL + ord[in[i]].mx);
		}
		cout << ans << endl;
	}
	return 0;
}
