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
	ios::sync_with_stdio(false);   // don't use scanf & printf
	cin.tie(0);
	cout.tie(0);
}

#define p00          point(0,0)
#define O            const point & 
#define CD           const double &  
#define EQ(a, b)     (fabs((a) - (b)) <= eps) /* equal to */
#define LT(a, b)     ((a) < (b)-eps) /* less than */
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define clr(v,d)     memset(v, d, sizeof(v))
#define length(a)    (hypot((a).imag(), (a).real()))
#define dp(a,b)	     ((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)	     ((conj(a)*(b)).imag()) // if zero parl
#define pii	         pair<int,int>
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;

typedef long long ll;

const double PI = acos(-1.0);
const double eps = 1e-10;
const ll mod = 1e9 + 7, oo = 1e9;

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

V<V<pii> > adj;
int n, m, k, c;
const int N = 10000 + 4;
int oc2[26][26],oc3[26][26][26];
string s;
int dp[N][4];
int go(int id,int op){
	if (id >= sz(s)) return id == sz(s) && op != 1;
	int &ret = dp[id][op];
	if (ret != -1) return ret;
	ret = 0;
	if (op == 1)
		ret = go(id + 1, 1);
	if (id + 2 <= sz(s) && (op != 2 || s[id - 2] != s[id] || s[id - 1] != s[id + 1])){
		oc2[s[id]-'a'][s[id + 1]-'a'] ++;
		bool rt = go(id + 2, 2);
		if (!rt)
			oc2[s[id]-'a'][s[id + 1]-'a'] --;
		else
			ret = 1;
	}
	if (id + 3 <= sz(s) && (op != 3 || s[id - 3] != s[id] || s[id - 2] != s[id + 1] || s[id - 1] != s[id + 2])){
		oc3[s[id] - 'a'][s[id + 1] - 'a'][s[id + 2] - 'a'] ++;
		bool rt = go(id + 3, 3);
		if (!rt)
			oc3[s[id] - 'a'][s[id + 1] - 'a'][s[id + 2]-'a'] --;
		else
			ret = 1;
	}
	return ret;
}
int main()
{
	Emsawy();
	while (cin >> s){
		clr(dp, -1);
		go(5, 1);
		V<string>ans;
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < 26; j++){
				if (oc2[i][j] > 0){
					char a = i + 'a', b = j + 'a';
					string ap;
					ap.push_back(a);
					ap.push_back(b);
					ans.push_back(ap);
				}
				for (int k = 0; k < 26; k++){
					if (oc3[i][j][k] > 0){
						char a = i + 'a', b = j + 'a',c = k + 'a';
						string ap;
						ap.push_back(a);
						ap.push_back(b);
						ap.push_back(c);
						ans.push_back(ap);
					}
				}
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] << "\n";
		}
	}
	return 0;
}
