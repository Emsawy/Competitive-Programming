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

int n, m, w;
const int N = 1 * 100000 + 5;
int ar[N], fow[N];

int main()
{
	Emsawy();
	while (cin >> n >> m >> w){
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		ll s = 0, e = 2e9, resl;
		while (s <= e){
			ll mid = (s + e) / 2;
			clr(fow, 0);
			ll now = 0, res = 0;
			for (int i = 0; i < n; i++){
				now += fow[i];
				ll up = now + ar[i];
				if (mid - up > 0){
					res += (mid - up);
					now += (mid - up);
					fow[min(i + w, n)] -= (mid - up);
				}
			}
			if (res > m) e = mid - 1;
			else s = mid + 1, resl = mid;
		}
		cout << resl << endl;
	}
	return 0;
}
