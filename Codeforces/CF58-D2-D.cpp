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
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

V<V<int> > adj;
const ll N = 100000 + 5;
ll n, m, k, w;

int main() {

	Emsawy();
	while (cin >> n){
		V<string>s(n);
		char ch;
		set<string>A;
		set<string>B;
		int len = 0;
		for (int i = 0; i < n; i++){
			cin >> s[i];
			len += s[i].size();
		}
		len /= (n / 2);
		cin >> ch;
		for (int i = 0; i < n; i++){
			A.insert(s[i] + ch);
			B.insert(s[i]);
		}
		string ans = "";
		while (A.size()){
			string tmp = *A.begin();
			A.erase(A.begin());
			ans += tmp;
			tmp.pop_back();
			B.erase(B.find(tmp));
			int tp = len - tmp.size();
			string mn = "";
			for (auto it : B){
				if (tp == it.size()){
					if (mn.size() == 0) mn = it;
					mn = min(mn, it);
				}
			}
			B.erase(B.find(mn));
			ans += mn;
			mn += ch;
			A.erase(A.find(mn));
			ans += '\n';
		}
		cout << ans << endl;
	}
	return 0;
}
