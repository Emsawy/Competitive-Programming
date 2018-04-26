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
const ll N = 1111 + 5;
int n, m, k, w, s, p;

int prf[N], suf[N];
int A[N];

int main() {

	Emsawy();
	int t;
	cin >> t;
	string s;
	while (t--) {
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			prf[i] = min(s[i] - 'A', 26 - (s[i] - 'A'));
			suf[i] = prf[i];
		}
		for (int i = 1; i < s.size(); i++)
			prf[i] += prf[i - 1];
		for (int i = s.size() - 2; i >= 0; i--)
			suf[i] += suf[i + 1];

		n = s.size();
		int ans = oo;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if(prf[n - 1] - prf[j] == 0)
					ans = min(ans, prf[j] + j);
				if(suf[0] - suf[i] == 0)
					ans = min(ans, suf[i] + n - i);
				if(prf[j - 1] - prf[i] == 0)
					ans = min(ans, prf[i] + suf[j] + i*2+n - j);

				if (prf[j - 1] - prf[i] == 0)
					ans = min(ans, prf[i] + suf[j] + i + (n - j)*2);
			}
		}
		cout << ans << endl;

	}
	return 0;
}
