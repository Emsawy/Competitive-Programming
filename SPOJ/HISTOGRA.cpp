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
const ll mod = 1e9 + 7, oo = 1e10;

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

ll n, m,k, t, c;
const int N = 100000 + 5, s = 1000000;
ll v[N], st[N];

int main()
{
	Emsawy();
	while (cin >> n){
		if (n == 0) break;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
	
		ll ans = 0, top = 1;
		v[0] = v[n + 1] = st[0] = 0;
		for (int i = 1; i <= n + 1; i++){
			while (top > 1 && v[st[top-1]] >= v[i]){
				ans = max(ans, (i - (st[top - 2]) - 1) * v[st[top - 1]]);
				top--;
			}
			st[top++] = i;
		}
		cout << ans << endl;
	}
	return 0;
}


/*
//Divid and conqer#define _CRT_SECURE_NO_WARNINGS
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

ll n, m,k, t, c;
const int N = 100000 + 5, s = 1000000;

pair<int, int> seg[N * 4];
int g[N];
pair<int, int> query(int p, int l, int r, int x, int y){
	if (l > y || r < x)
		return MP(oo, oo);   // take care
	if (x <= l && r <= y)
		return seg[p];

	return min(query(p * 2, l, (l + r) / 2, x, y), query(p * 2 + 1, (l + r) / 2 + 1, r, x, y));
}

ll divid(int s, int e){
	if (s > e) return 0;
	if (s == e)
		return g[s];
	pair<int,int> mid = query(1, 1, n, s, e);
	ll ret = mid.first * 1LL * (e - s + 1);
	ret = max(ret,divid(s, mid.second - 1));
	ret = max(ret,divid(mid.second + 1, e));
	return ret;
}

void build(int p, int l, int r){
	if (l == r){
		seg[p] = MP(g[l], l);
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, (l + r) / 2 + 1, r);
	seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}

int main()
{
	Emsawy();
	while (cin >> n){
		if (n == 0) break;
		for (int i = 1; i <= n; i++)
			cin >> g[i];
		build(1, 1, n);
		cout << divid(1, n) << endl;
	}
	return 0;
}

*/
