#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
int n, m, k, w;

int main() {

	Emsawy();
	while (cin >> n){
		stack<int>st;
		int mx = 0;
		for (int i = 0; i < n; i++){
			cin >> m;
			while (!st.empty()){
				mx = max(mx, st.top() ^ m);
				if (st.top() > m) break;
				st.pop();
			}
			st.push(m);
		}
		cout << mx << endl;
	}
	return 0;
}
