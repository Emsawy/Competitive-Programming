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
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

V<V<int> > adj;
const ll N = 100000 + 5;
ll n, m, k, w;

int main() {

	Emsawy();
	while (cin >> n >> k >> w){
		n--;
		while (w--){
			cin >> m;
			m--;
			if (n == 0){
				if (k == 1) cout << "X";
				else cout << ".";
				continue;
			}
			if (m == 0){
				if (n + 1 == k)cout << "X";
				else cout << ".";
				continue;
			}
			ll N = n - (n % 2 == 0 && k > 1);
			ll rem = N - m + 1;
			if ((rem + 1) / 2 <= (k - (n % 2 == 0))){
				if (m == n && k > 0){
					cout << "X";
					continue;
				}
				if (N % 2 == m % 2) {
					cout << "X";
					continue;
				}
				ll remK = (k - (n % 2 == 0)) - (N + 1) / 2;
				if (remK <= 0) {
					cout << ".";
					continue;
				}
				remK *= 2;
				//remK++;
				ll lst = N - remK;
				if (m >= lst) cout << "X";
				else cout << ".";
			}
			else if (n == m && k > 0) cout << "X";
			else cout << ".";
		}
		cout << endl;
	}
	return 0;
}
