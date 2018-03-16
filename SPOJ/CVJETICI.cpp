#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
#define V	         vector
const ll N = (1 << 18);
int n, m, k, w;

const int siz = (1 << 21);
long long a[siz], b[siz];

void add(int i, long long valA, long long valB) {
	i++;
	while (i <= siz) {
		a[i - 1] += valA;
		b[i - 1] += valB;
		i += (i & -i);
	}
}

long long get(int i) {
	int ii = i++;
	long long res = 0;
	while (i) {
		res += a[i - 1] + b[i - 1] * 1LL * ii;
		i -= (i & -i);
	}
	return res;
}

void addRange(int st, int en, long long val) {
//	int si = en - st + 1;
	add(st, -val * (st - 1), val);
//  add(en + 1, val * (st - 1) + val * si, -val);
	add(en + 1, val * en, -val);
}

int main() {

	Emsawy();
	int l, r;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin>>l>>r;
			int L = get(l) - get(l - 1), R = get(r) - get(r - 1);
			cout<<L + R<<endl;
			addRange(l, l, -L);
			addRange(r, r, -R);
			addRange(l + 1, r - 1, 1);
		}
	}

	return 0;
}
