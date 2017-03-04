
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define sz(v) ((int)((v).size()))
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<pair<int, int> > > adj;
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
int n, m, k;

int main()
{
	Emsawy();
	string s;
	map<string,V<string> >mp;
	V<string>ans;
	while (getline(cin,s)){
		if (s[0] == '#')break;
		stringstream ss;
		ss << s;
		while (ss >> s) {
			string tmp = "";
			for (int i = 0; i < s.size(); i++)
				tmp += tolower(s[i]);
			sort(all(tmp));
			mp[tmp].push_back(s);
		}	
	}
	for (auto it : mp){
		if (it.second.size() == 1){
			ans.push_back(it.second[0]);
		}
	}
	sort(all(ans));
	for (auto it : ans)
		cout << it << endl;

	return 0;
}
