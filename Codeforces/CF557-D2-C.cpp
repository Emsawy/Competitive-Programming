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

int n, m, k, c;
const int N = 100000 + 5;
map<int, V<int> > cord;
pair<int,int> seg[N * 8];
pair<int, int> g[N];
void update(int p, int s, int e, int x){

	if (s == e){
		seg[p] = MP(0,0);
		return;
	}
	int mid = (s + e) / 2;
	if (x <= mid)
		update(p * 2, s, mid, x);
	else
		update(p * 2 + 1, mid + 1, e, x);

	seg[p].first = seg[p * 2].first + seg[p * 2 + 1].first;
	seg[p].second = seg[p * 2].second + seg[p * 2 + 1].second;
}
int query(int p, int s, int e, int kth){
	if (s == e)
		return seg[p].first;

	if (kth <= seg[p * 2].second) // take care size must be multplied by * 8 because of leave nodes
		return query(p * 2, s, (s + e) / 2, kth);
	else {
		return seg[p * 2].first + query(p * 2 + 1, (s + e) / 2 + 1, e, kth - seg[p * 2].second);
	}
}
void build(int p, int s, int e){
	if (s == e){
		seg[p] = MP(g[s].first, 1);
		return;
	}
	build(p * 2, s, (s + e) / 2);
	build(p * 2 + 1, (s + e) / 2 + 1, e);
	seg[p].first = seg[p * 2].first + seg[p * 2 + 1].first;
	seg[p].second = seg[p * 2].second + seg[p * 2 + 1].second;
}


int main()
{
	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> g[i].second;
		}
		for (int i = 0; i < n; i++){
			cin >> g[i].first;
		}
		sort(g, g + n);
		for (int i = 0; i < n; i++)
			cord[g[i].second].push_back(i);

		int ans = oo, N = n, tot = 0, lst = 0;
		build(1, 0, n - 1);
		V<pair<int, V<int> > > adj(all(cord));
		reverse(all(adj));
		for (auto it : adj){
			for (int j = 0; j < it.second.size(); j++){
				update(1, 0, n - 1, it.second[j]);
				tot += g[it.second[j]].first;
			}
			
			int rem = N - (it.second.size() * 2 - 1);
			int qu = 0;
			if (rem > 0){
				qu = query(1, 0, n - 1, rem);
			}
			ans = min(ans, qu + lst);
			lst = tot;
			N -= it.second.size();
		}
		cout << ans << endl;
	}
	return 0;
}
/*

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
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define clr(v,d)     memset(v, d, sizeof(v))
#define length(a)    (hypot((a).imag(), (a).real()))
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

int n, m, k, c;
const int N = 100000 + 5;
pair<int, int> g[N];
int cnt[N], p[300], lstp[300];

int main()
{
	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> g[i].first;
		}
		for (int i = 0; i < n; i++){
			cin >> g[i].second;
		}
		sort(g, g + n);
		for (int i = n - 1; i >= 0; i--){
			cnt[i] = g[i].second;
			if (i + 1 < n){
				cnt[i] += cnt[i + 1];
			}
		}
		int ans = oo, maxlen = 0;
		for (int i = 0; i < n; i++){
			p[g[i].second] ++;
			maxlen++;
			if (g[i].first != g[i + 1].first){
				int cur = 0, rem = (i + 1) - (maxlen * 2 - 1);
				if (rem > 0){
					for (int j = 0; j < 300; j++){
						if (rem - lstp[j] >= 0){
							rem -= lstp[j];
							cur += lstp[j] * j;
						}
						else{
							cur += rem * j;
							rem = 0;
							break;
						}
					}
				}
				ans = min(ans, cnt[i + 1] + cur);
				for (int j = 0; j < 300; j++){
					lstp[j] += p[j];
				}
				clr(p, 0);
				maxlen = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
*/
