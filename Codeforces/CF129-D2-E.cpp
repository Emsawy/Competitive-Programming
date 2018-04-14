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
const ll N = 100000 + 5;
int n, m, k, w;

const int R = 2100, C = 2100;
ll ncr[R][C];
void gen() {
	ncr[0][0] = 1;
	for (int i = 0; i < R; i++) {
		ncr[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			ncr[i][j] = (ncr[i][j] + (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod) % mod;
		}
	}
}

int main() {

	Emsawy();		
	gen();
	while (cin >> n >> m >> k) {
		cout << (ncr[n-1][2*k] * ncr[m-1][2*k]) % mod << endl;
	}
	return 0;
}
