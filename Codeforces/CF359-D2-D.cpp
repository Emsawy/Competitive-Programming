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
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;

set<int>ans;

int n, m, k, t, c, v[300005], v0[300005], e[300005], mx;
void L(){

	int cur = v[0];
	if (v0[0] > 0)
		cur = min(v[0], v0[0]);
	for (int i = 0; i < n; i++){
		if (v[i] % cur == 0)
			v0[i] = cur;
		else{
			cur = v[i];
			if (v0[i] > 0) cur = min(v[i], v0[i]);
			i--;
		}
	}
}
void R(){

	int cur = v[n-1];
	if (v0[n - 1] > 0)
		cur = min(v[n - 1], v0[n - 1]);
	for (int i = n - 1; i >= 0; i--){
		if (v[i] % cur == 0)
			v0[i] = cur;
		else{
			cur = v[i];
			if (v0[i] > 0) cur = min(v[i], v0[i]);
			i++;
		}
	}

}
int getmx(){
	int mx0 = 0, cnt = 0;
	for (int i = 1; i < n; i++){
		if (v0[i] == v0[i - 1]){
			cnt++;
			mx0 = max(mx0, cnt);
		}
		else cnt = 0;
	}
	return mx0;
}
void solve(){
	int cnt = 0;
	for (int i = 1; i < n; i++){
		if (v0[i] == v0[i - 1]){
			cnt++;
			if (mx == cnt){
				ans.insert(i - mx);
			}
		}
		else cnt = 0;
	}
}
int main()
{
	Emsawy();
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> v[i];
			e[i] = v[i];
		}

		ans.clear();

		clr(v0, 0);
		L();
		R();
		mx = getmx();
		solve();

		clr(v0, 0);
		R();
		L();
		solve();

		if (ans.size() == 0)
			for (int i = 0; i < n; i++)
				ans.insert(i);

		cout << ans.size() << " " << mx << endl;
		for (auto it : ans){
			cout << it + 1 << " ";
		}
		puts("");
	}
	return 0;
}
