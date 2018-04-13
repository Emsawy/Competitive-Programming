#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 2e9+10;

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

ll valid(int x) {
	bool ok = 0;
	if (x % 2) ok = 1, x--;
	else x -= 2;
	if (x <= 0) return ok;
	x /= 2;
	return ((x * x + 1) / 2)*4 + ok;
}

int main() {

	Emsawy();
	while (cin >> n) {
		w = 0;
		for (int i = 1; i < 1000000; i++) {
			int _4 = 0, _2 = 0, _1 = 0;
			if (i % 2 == 0) {
				int edg = (i - 2) / 2;
				_4 = (edg * edg + 1) / 2;
			}
			else {
				int edg = (i - 1) / 2;
				_4 = (edg * edg + 1) / 2;
				if (edg % 2 == 0)
					_2 = edg * 2;
				else
					_2 = (((((i - 2) / 2) + 1) / 2) * 2 * 2);
				_1 = 1;
			}
			int N = n;
			if (_4 * 4 <= N) {
				N -= _4 * 4;
				if (_2 <= N) {
					N -= _2;
					if (_1 <= N) {
						N -= _1;
					}
				}
				else {
					N %= 2;
					if (_1 <= N) {
						N -= _1;
					}
				}
			}
			else {
				N %= 4;
				if (_2 <= N) {
					N -= _2;
					if (_1 <= N) {
						N -= _1;
					}
				}
				else {
					N %= 2;
					if (_1 <= N) {
						N -= _1;
					}
				}
			}
			if (N == 0) {
				w = i;
				break;
			}
			int rem = ((((i - 1) / 2 + 1) / 2) * 2) * 2;
			if (rem >= n) {
				if (n % 2 == 0) {
					w = i;
					break;
				}
			}
		}
		
		cout << w << endl;
	}
	return 0;
}

