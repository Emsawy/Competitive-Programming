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

const ll N = 500010;
int n, m, k, w, h;

struct Node {
	int size;
	char l, r;
	Node(){}
	Node(int size, int l, int r) :size(size), l(l), r(r) {}
	int getl() {
		return l - 'a';
	}
	int getr() {
		return r - 'a';
	}
}v[N];

int dp[26][26];

int main() {

	Emsawy();
	string s;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> s;
			v[i] = Node(s.size(), s[0],s.back());
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				if (dp[j][v[i].getl()] > 0)
					dp[j][v[i].getr()] = max(dp[j][v[i].getr()], dp[j][v[i].getl()] + v[i].size);
			}
			dp[v[i].getl()][v[i].getr()] = max(dp[v[i].getl()][v[i].getr()], v[i].size);
		}
		int mx = 0;
		for (int i = 0; i < 26; i++) {
			mx = max(dp[i][i], mx);
		}
		cout << mx << endl;

		clr(dp, 0);
	}
	return 0;
}
