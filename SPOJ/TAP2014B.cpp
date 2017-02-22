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
int dp[11][400000];
int go(int id, int sum){
	if (sum == n) 
		return 1;
	if (id == 10) return 0;
	if (dp[id][sum + 200000] != -1) return dp[id][sum + 200000];
	if (go(id + 1, sum + 0 * pow(3, id))) return dp[id][sum + 200000] = 1;
	if (go(id + 1, sum + 1 * pow(3, id))) return dp[id][sum + 200000] = 1;
	if (go(id + 1, sum + -1 * pow(3, id))) return dp[id][sum + 200000] = 1;
	return dp[id][sum + 200000] = 0;
}
V<char>ans;
void path(int id, int sum){
	if (sum == n) return ;
	if (id == 10) return ;
	if (dp[id][sum + 200000] == go(id + 1, sum + 0 * pow(3, id))) return  ans.push_back('0'), path(id + 1, sum + 0 * pow(3, id));
	if (dp[id][sum + 200000] == go(id + 1, sum + 1 * pow(3, id))) return  ans.push_back('+'), path(id + 1, sum + 1 * pow(3, id));
	if (dp[id][sum + 200000] == go(id + 1, sum + -1 * pow(3, id))) return  ans.push_back('-'), path(id + 1, sum + -1 * pow(3, id));
}
int main()
{
	Emsawy();
	int T ;
	cin >> T;
	while (T--){
		cin >> n;
		clr(dp, -1);
		go(0, 0);
		path(0, 0);
		reverse(all(ans));
		for (auto it : ans)
			cout << it;
		cout << endl;
		ans.clear();
	}
	return 0;
}
