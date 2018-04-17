#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 100, oo = 1000000009;

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

const int N = 1000000;
ll n, m, k, w, h;
ll ar[N];

int main() {

	Emsawy();
	set<pair<int, int> > st;
	int idx = -1;
	st.insert(MP(1, 1));
	ar[1] = ar[2] = 1;
	for (int i = 3; i < N; i++) {
		ar[i] = (ar[i - 1] + ar[i - 2]) % 100;
		if (!st.insert(MP(ar[i], ar[i - 1])).second) {
			idx = i;
			break;
		}
	}
	ar[idx--] = 0;
	ar[idx--] = 0;
	for (int i = 1; i <= idx; i++) {
		ar[i] += ar[i - 1];
	}
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld\n", &n, &m);
		n--;
		ll suml = ((n-1) / idx) * ar[idx] + ar[((n-1) % idx) + 1];
		ll sumr = ((m-1) / idx) * ar[idx] + ar[((m - 1) % idx) + 1];
		printf("%lld\n", sumr - suml);
	}
	return 0;
}
