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
}

#define sz(v)			((int)((v).size()))
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define clr(v,d)		memset(v, d, sizeof(v))
#define sf(x)			scanf("%d", &x)
#define sf2(x,y)		scanf("%d %d", &x, &y)
#define sf3(x,y,z)		scanf("%d %d %d", &x, &y, &z)
#define sfll(x)			scanf("%I64d", &x)
#define sfll2(x,y)		scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)		scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) <= EPS)
#define rotate0(p,ang)		((p)*exp(Point(0,ang)))
#define rotateA(p,ang,about)	(rotate0(vec(about,p),ang)+about)
#define reflect0(v,m)		(conj((v)/(m))*(m))
#define normalize(a)		(a)/length(a)
#define lengthSqr(p)		dp(p,p)
#define pii			pair<int,int>
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()

typedef complex<double> 	point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9), si = 1000000;

V<V<pii> > adj;
int n, m, k, t, c;

string word, s[10009];
V<string> ans;
map<string, pair<int,int> > mp;
pair<short, short> dp[1009][2];
pair<short,short> go(int nd , bool amb = 0){
	if (nd == word.size())
		return MP(1, amb);
	string now = "";
	pair<short, short> & ret = dp[nd][amb];
	if (ret != MP(short(-1), short(-1))) return ret;
	for (int i = nd, stop = 0; stop < 105 && i < word.size(); stop++, i++){
		now += word[i];
		string tmp(now);
		sort(all(tmp));
		tmp += now[0];
		tmp += now[now.size() - 1];
		map<string, pair<int,int> > ::iterator it = mp.find(tmp);
		if (it == mp.end()) continue;
		ret = go(i + 1 , amb | (it->second.first > 1));
		if (ret.first){
			ans.push_back(s[it->second.second]);
			return ret;
		}
	}
	return MP(0, 0);
}
int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> word;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> s[i];
			string tmp(s[i]);
			sort(all(tmp));
			tmp += s[i][0];
			tmp += s[i][s[i].size() - 1];
			mp[tmp].first++;
			mp[tmp].second = i;
		}
		clr(dp, -1);
		pair<int, int> ret = go(0, 0);
		if (ret.first && ret.second) puts("ambiguous");
		else if (ret.first){
			reverse(all(ans));
			string pr = "";
			for (auto it : ans) pr += it, pr += ' ';
			pr.pop_back();
			pr += '\n';
			printf("%s", pr.c_str());
		}
		else puts("impossible");
		mp.clear();
		ans.clear();
	}
	return 0;
}
