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
#define all(v)	     ((v).begin()), ((v).end())
#define clr(v,d)     memset(v, d, sizeof(v))
#define V	         vector

const ll N = (1 << 18);
ll n, m, k, w;

ll get(ll n){
	ll ret = 0;
	while(n > 1){
		ret += 1;
		n /= 2;
	}
	return ret;
}
int main() {
	
	Emsawy();
	while (cin >> n) {
		if(n == 0) break;
		ll ret = get(n);
		cout<<ret<<endl;
	}

	return 0;
}
