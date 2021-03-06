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
int n, m, k, w, t;
int cnt[30][30];

int main() {

	Emsawy();
	int ca = 0;
	while (cin >> n >> t){
		if (n == 0 && t == 0) break;
		cout << "Case #" << ++ca << endl;
		map<string, int> indx;
		V<string> vn(n);
		for (int i = 0; i < n; i++) {
			cin >> vn[i];
			indx[vn[i]] = i;
		}
		clr(cnt, 0);
		string a, b;
		int val;
		for (int i = 0; i < t; i++) {
			cin >> a >> b >> val;
			int ia = indx[a], ib = indx[b];
			cnt[ia][0] -= val;
			cnt[0][ib] += val;
		}
		for (int i = 1; i < n; i++) {
			int now = cnt[0][i] + cnt[i][0];
			if (now < 0) {
				cout << vn[0] << " " << vn[i] << " " << now * -1 << endl;
			}
			else {
				cout << vn[i] << " " << vn[0] << " " << now << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
