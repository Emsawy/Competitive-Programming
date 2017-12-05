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
const int mod = 1e9 + 7, oo = 1e9;

int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};

ll n, m,k, t, c;


int main()
{
	Emsawy();
	while (cin >> n >> k){
		V<int>v(n);
		map<int, int>mp;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			mp[v[i]]++;
		}
		map<int, int> killed;
		ll s, e, ex = 0;
		for (auto it : mp){
			s = 0, e = it.first - ex;
			if (e <= 0) continue;
			if (e * n <= k){
				k -= e * n;
				ex += e;
				n -= it.second;
				killed[it.first] = 1;
				continue;
			}
			if (e == 1) break;
			while (s < e){
				ll mid = s + (e - s + 1) / 2;
				if (mid*n > k) e = mid - 1;
				else s = mid;
			}
			if (s == 0) break;
			k -= s * n;
			ex += s;
		}
		deque<pair<int, int> > seq;
		for (int i = 0; i < v.size(); i++){
			if (killed[v[i]]) continue;
			seq.push_back(MP(v[i] - ex, i));
		}
		int si = seq.size();
		for (int i = 0; i < si; i++){
			if (k <= 0) break;
			seq.front().first--;		
			seq.push_back(seq.front());
			seq.pop_front();
			k--;
		}
		if (k > 0) cout << "-1" << endl;
		else {
			for (int i = 0; i < seq.size(); i++){
				if (seq[i].first > 0){
					cout << seq[i].second +1<< " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}
