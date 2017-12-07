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
const int N = 100 + 2;
map<string, V<pair<int, int> > > mp;
map<string, V<pair<int, int> > >:: iterator it;
V<V<int > > cml;
int main()
{
	Emsawy();
	int T;
	cin >> T;
	while (T--){
		cin >> n >> k;
		string t,r;
		int p, q;
		for (int i = 0; i < n; i++){
			cin >> t >> r >> p >> q;
			mp[t].push_back(MP(q, p));
		}
		cml.clear();
		cml.resize(mp.size());
		int st = 0;
		for (it = mp.begin(); it != mp.end(); it ++){
			sort(all(it->second));
			cml[st].resize(it->second.size());
			for (int i = it->second.size() - 1; i >= 0; i--){
				cml[st][i] = it->second[i].second;
				if (i + 1 < it->second.size())
					cml[st][i] = min(cml[st][i], cml[st][i + 1]);
			}
			st++;
		}
		
		int s = 0, e = 1000000000;
		while (s < e){
			int now = k;
			int mid = s + (e - s + 1) / 2;
			int st = 0;
			for (auto it : mp){
				V<pair<int, int> > &p = it.second;
				V<pair<int,int> > ::iterator itt = lower_bound(all(p), MP(mid, (int) -oo));
				if (itt == p.end()) {
					now = -1;
					break;
				}
				now -= cml[st][(itt - p.begin())];
				st++;
				if (now < 0) break;
			}
			if (now < 0) e = mid - 1;
			else s = mid;
		}
		cout << s << endl;
		mp.clear();
	}
	return 0;
}
