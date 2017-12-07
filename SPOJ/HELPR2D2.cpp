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
int n, m, k, t, c, e;
const int N = 100000 + 5;
pair<int, int> seg[N * 4];
int g[N];
void update(int p, int l, int r, int x){

	if (l == r){
		seg[p].first = g[l];
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid)
		update(p * 2, l, mid, x);
	else
		update(p * 2 + 1, mid + 1, r, x);

	seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}
pair<int, int> query(int p, int l, int r, int v){
	if (l == r)
		return seg[p];
	if (k - seg[p * 2].first >= v)
		return query(p * 2, l, (l + r) / 2, v);
	return query(p * 2+1, (l + r) / 2 + 1, r,v);
}


void build(int p, int l, int r){
	if (l == r){
		g[l] = 0;
		seg[p] = MP(g[l], l);
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, (l + r) / 2 + 1, r);
	seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}

int to = 100000;
void solve(int v){
	pair<int, int> p = query(1, 1, to, v);
	g[p.second] += v;
	update(1, 1, to, p.second);
}

int main()
{
	Emsawy();
	scanf("%d", &t);
	while (t--){
		build(1, 1, to);
		scanf("%d%d\n", &k, &n);
		char s[20];
		while (n--){
			scanf("%s", s);
			if (s[0] == 'b'){
				int lp, v;
				scanf("%s",s);
				sscanf(s, "%d", &lp);
				scanf("%s", s);
				sscanf(s, "%d", &v);
				n++;
				for (int i = 0; i < lp; i++){
					solve(v);
					n--;
				}
			}
			else {
				int v;
				sscanf(s, "%d", &v);
				solve(v);
			}
		}
		ll ans = 0, cnt = 0;
		for (int i = 1; i <= to; i++){
			if (g[i]){
				ans += k - g[i];
				cnt++;
			}
			else break;
		}
		printf("%lld %lld\n", cnt, ans);
	}
	return 0;
}
