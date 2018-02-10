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
const ll N = 4e2 + 5;
int n, m, k, w, h;

int main() {

	Emsawy();
	while (cin >> n){
		V<int>v(n + 1), ans(n + 1),l(n + 1, 1),r(n + 1, n);
		for (int i = 1; i <= n; i++){
			cin >> v[i];
		}
		stack<int> st;
		for (int i = 1; i <= n; i++){
			while (!st.empty() && v[i] <= v[st.top()]){
				st.pop();
			}
			if (!st.empty()) l[i] = st.top() + 1;
			st.push(i);
		}
		while (st.empty() == false) st.pop();
		for (int i = n; i >= 1; i--){
			while (!st.empty() && v[i] <= v[st.top()]){
				st.pop();
			}
			if (!st.empty()) r[i] = st.top() - 1;
			st.push(i);
		}
		while (st.empty() == false) st.pop();
		
		for (int i = 1; i <= n; i++){
			ans[r[i] - l[i] + 1] = max(v[i], ans[r[i] - l[i] + 1]);
		}
		for (int i = n - 1; i >= 1; i--){
			ans[i] = max(ans[i], ans[i + 1]);
		}
		for (int i = 1; i <= n; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
} 
