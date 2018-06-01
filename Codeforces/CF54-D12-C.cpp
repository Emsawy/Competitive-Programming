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
const ll N = 1000 + 5;
ll n, m, k, w, l , r;
ll one[19], good[N], tot[N];
ll getOnes(ll x) {
	ll clone = x, sub = 1;
	int lst = 0, cnt = 0;
	while (x) {
		lst = x % 10;
		x /= 10;
		cnt++;
		sub *= 10;
	}
	if (lst != 1)
		return one[cnt];

	sub /= 10;
	return one[cnt - 1] + (clone - sub) + 1;
}
double dp[N][N];
double go(int id, int perc) {
	if (id >= n) {
		if (1.0 * perc / n * 100 >= k) 
			return 1;
		return 0;
	}
	double &ret = dp[id][perc];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(id + 1, perc + 1) * 1.0 * good[id] / tot[id];
	ret += go(id + 1, perc) * (1 - (1.0 * good[id] / tot[id]));
	return ret;
}

int main() {

	Emsawy();
	ll sub = 1;
	for (int i = 1; i < 19; i++) {
		one[i] = sub + one[i - 1];
		sub *= 10;
	}
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> l >> r;
			good[i] = getOnes(r) - getOnes(l - 1);
			tot[i] = (r - l + 1);
		}
		cin >> k;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = -1;
			}
		}
		cout <<fixed << setprecision(12)<< go(0, 0) << endl;
	}
	return 0;
}






