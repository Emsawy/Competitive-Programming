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
const ll N = 40;
int n, m, k, w, h;
string s;

int main() {

	Emsawy();
	while (cin >> s){
		pair <ll, ll>a, b, ans;
		for (int i = 0; i < s.size(); i++){
			a.first += s[i] == 'a';
			b.first += s[i] == 'b';
			swap(a.first, a.second);
			swap(b.first, b.second);
			if (s[i] == 'a'){
				ans.first += a.first;
				ans.second += a.second;
			}
			else{
				ans.first += b.first;
				ans.second += b.second;
			}
		}
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}
