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
int n, m, k, t, c;
const int N = 100000 + 5;
int g[N];

int go(int id){
	if (id == g[id]) return id-1;
	return g[id] = go(g[id] + 1);
}

int main()
{
	Emsawy();
	string s;
	while (cin >> s){
		stack<pair<char, int> > st;
		for (int i = 0; i < s.size(); i++){
			g[i] = i;
			if (st.empty()){
				st.push(MP(s[i], i));
				continue;
			}
			if (st.top().first == '[' && s[i] == ']' || st.top().first == '(' && s[i] == ')'){
				g[st.top().second] = i;
				st.pop();
				continue;
			}
			st.push(MP(s[i], i));
		}
		int ans = 0;
		g[s.size()] = s.size();
		for (int i = 0; i < s.size(); i ++){
			if (i == g[i]) continue;
			i = go(i) + 1;
		}
		for (int i = 0; i < s.size(); i = g[i] + 1){
			int now = 0;
			for (int j = i; j < g[i] + 1; j++)
				if (s[j] == '[') now++;
			if (now > ans && g[i] + 1 - i > 1)
				ans = now;
		}
		string sub;
		for (int i = 0; i < s.size(); i = g[i] + 1){
			int now = 0;
			for (int j = i; j < g[i] + 1; j++)
				if (s[j] == '[') now++;
			if (now == ans && g[i] + 1 - i > 1){
				sub = s.substr(i, g[i] + 1 - i);
				break;
			}
		}
		cout << ans << endl;
		cout << sub << endl;
	}
	return 0;
}
