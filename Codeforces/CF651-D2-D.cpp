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

int n, m, a,b,T;
double x;
const int N = 500000 + 5;
char g[N];
ll l[N], r[N];

int main()
{
	Emsawy();
	while (cin >> n >> a >> b >> T){
		for (int i = 0; i < n; i++)
			cin >> g[i];
		for (int i = 0; i < n; i++){
			l[i] = (i?a:0) + (g[i] == 'w' ? b : 0) + 1;
			if (i)
				l[i] += l[i - 1];
		//	bug(l[i]);
		}
		//puts("");
		for (int i = n - 1; i >= 0; i--){
			r[i] = a + (g[i] == 'w' ? b : 0) + 1;
			if (i != n - 1)
				r[i] += r[i + 1];
			//bug(r[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			ll now = T - l[i];
			if (now >= 0)
				ans = max(ans, i + 1);
			now -= i * 1LL * a;
			if (now <= 0) continue;
			int s = 0, e = n - 1;
			while (s <= e){
				int mid = (s + e) / 2;
				if (r[mid] > now) s = mid + 1;
				else e = mid - 1;
			}
			if (s == n) continue;
			ans = max(ans, i + 1 + n - s);
		}
		for (int i = n - 1; i >= 0; i--){
			ll now = T - r[i];
			now -= (n - i) * a;
			if (now <= 0) continue;
			int s = 0, e = n - 1;
			while (s <= e){
				int mid = (s + e) / 2;
				if (l[mid] > now) e = mid - 1;
				else s = mid + 1;
			}
			if (e == -1) continue;
			ans = max(ans, n - i + e + 1);
		}
		cout << min(n,ans) << endl;
	}
	return 0;
}
