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
int n, m, k, t, c, q;

map<set<int>, int >a;
map<int, set<int> > b;
int rename(set<int> st){
	int &ret = a[st];
	if (ret == 0)
		ret = a.size(), b[ret] = st;
	return ret;
}
int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> q;
		char s[30];
		stack<int>st;
		while (q--){
			scanf("%s", s);
			if (!strcmp(s, "PUSH")){
				st.push(rename(set<int>()));
			}
			else if (!strcmp(s, "DUP")){
				st.push(st.top());
			}
			else if (!strcmp(s, "UNION")){
				int l = st.top(); st.pop();
				int r = st.top(); st.pop();
				set<int>L = b[l] , R = b[r] , c;
				set_union(L.begin(), L.end(), R.begin(), R.end(), inserter(c, c.begin()));
				st.push(rename(c));
			}
			else if (!strcmp(s, "INTERSECT")){
				int l = st.top(); st.pop();
				int r = st.top(); st.pop();
				set<int>L = b[l], R = b[r], c;
				set_intersection(L.begin(), L.end(), R.begin(), R.end(), inserter(c, c.begin()));
				st.push(rename(c));
			}
			else if (!strcmp(s, "ADD")){
				int l = st.top(); st.pop();
				int r = st.top(); st.pop();
				set<int> c = b[r];
				c.insert(l);
				st.push(rename(c));
			}
			cout << b[st.top()].size() << endl;
		}
		cout << "***\n";
		a.clear();
		b.clear();
	}
	return 0;
}
