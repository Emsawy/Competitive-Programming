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
const ll N = 1e3 + 5;
ll n, m, k, w, p;
int g[N][N];
ll ans_0[N*N], ans_1[N*N];

int main() {

	Emsawy();
	while (cin >> n >> m >> k >> p){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> g[i][j];
			}
		}
		priority_queue< ll > pq_0, pq_1;
		for (int i = 0; i < n; i++){
			ll sum = 0;
			for (int j = 0; j < m; j++){
				sum += g[i][j];
			}
			pq_0.push(sum);
		}
		for (int i = 0; i < m; i++){
			ll sum = 0;
			for (int j = 0; j < n; j++){
				sum += g[j][i];
			}
			pq_1.push(sum);
		}
		for (int i = 1; i <= k; i++){
			ll top_0 = pq_0.top();
			ll top_1 = pq_1.top();

			pq_0.pop();
			ans_0[i] += top_0;
			ans_0[i] += ans_0[i - 1];
			top_0 -= m * p;
			pq_0.push(top_0);

			pq_1.pop();
			ans_1[i] += top_1;
			ans_1[i] += ans_1[i - 1];
			top_1 -= n * p;
			pq_1.push(top_1);

		}
		ll res = -1e18;
		for (int i = 1; i <= k; i++){
			res = max(res, ans_0[i] + ans_1[k - i] - 1LL * i * p * (k - i));
			res = max(res, ans_0[k - i] + ans_1[i] - 1LL * i * p * (k - i));
		}
		cout << res << endl;
		clr(ans_0, 0);
		clr(ans_1, 0);
	}
	return 0;
}
