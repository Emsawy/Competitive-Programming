#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

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
const ll N = 4100;
int n, m, k, w;
int a[N], b[N], c[N], d[N];

int main() {

	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++){
			scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		}
		unordered_map<int, int > mp;
		unordered_map<int, int >::iterator it;
		mp.reserve(16000000);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				mp[(a[i] + b[j])]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				it = mp.find(-(c[i] + d[j]));
				if (it != mp.end()){
					ans += it->second;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
