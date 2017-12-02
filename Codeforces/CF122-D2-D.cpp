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
const int N = 100000 + 5;
char g[N];
int main()
{
	Emsawy();
	while (cin >> n >> m){
		for (int i = 1; i <= n; i++)
			cin >> g[i];
		int id = -1;
		for (int i = 1; i + 1 <= n; i++){
			if (m <= 0) break;
			if (g[i] == '4' && g[i + 1] == '7'){
				if (i % 2) {
					g[i + 1] = '4';
					i--;
				}
				else
					g[i] = '7';
				m--;
				continue;
			}
			if (g[i] == '4' && g[i + 1] == '4' && i % 2){
				if (i + 2 <= n && g[i + 2] == '7'){
					id = i;
					break;
				}
			}
		}
		if (m > 0 && id != -1){
			if (m % 2){
				if ((id + 1) % 2)
					g[id + 2] = '4';
				else
					g[id + 1] = '7';
			}
		}
		for (int i = 1; i <= n; i++)
			cout << g[i];
		cout << endl;
	}
	return 0;
}
