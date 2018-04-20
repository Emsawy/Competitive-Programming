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
const ll N = 100 + 5;
ll n, m, l, k, w;
V<int> pil;
int dp[188][400001];
int go(int id, int rem) {
	if (rem == 0) return 0;
	if (rem < 0 || id >= pil.size()) return oo;
	int &ret = dp[id][rem];
	if (ret != -1) return ret;
	ret = oo;
	ret = min(ret, go(id, rem - pil[id]) + 1);
	ret = min(ret, go(id + 1, rem));
	return ret;
}
int main() {

	Emsawy();
	for (int i = 0; i*i*i <= 400000; i++) {
		pil.push_back(i*i*i);
	}
	for (int i = 1, j = 1; j <= 400000; i++, j+= i*i) {
		pil.push_back(j);
	}
	clr(dp, -1);
	while (cin >> n) {
		if (n == -1) break;
		cout << go(1, n) << endl;
	}
	return 0;
}
