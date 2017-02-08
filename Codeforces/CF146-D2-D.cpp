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
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<pair<int, int> > > adj;
const ll mod = (ll) 1e9 + 7, oo = (ll) 1e9;
int n, m;
string go(int id , char ch){
	string s;
	while (id--) s += ch;
	return s;
}
int main()
{
	Emsawy();
	int a, b, c, d;
	while (cin >> a >> b >> c >> d){
		if (abs(c - d) > 1){
			cout << -1 << endl;
			continue;
		}
		string s;
		if (c > d){
			while (c--) s += "47";
			a -= count(all(s), '4');
			b -= count(all(s), '7');
			if (a < 0 || b < 0){
				cout << -1 << endl;
				continue;
			}
			cout << go(a, '4') + s + go(b, '7') << endl;
		}
		else if (d > c){
			while (d--) s += "74";//4747474
			a -= count(all(s), '4');
			b -= count(all(s), '7');
			if (a < 0 || b < 0){
				cout << -1 << endl;
				continue;
			}
			s.erase(0, 1);
			s.erase(s.size() - 1, 1);
			cout << "7" + go(a, '4') + s + go(b, '7') + "4" << endl;
		}
		else{

			while (c--) s += "47";
			s += '4';
			int aa = a, bb = b;
			aa -= count(all(s), '4');
			bb -= count(all(s), '7');
			if (aa >= 0 && bb >= 0){
				s.erase(s.size() - 1, 1);
				cout << go(aa, '4') + s + go(bb, '7') + '4' << endl;
				continue;
			}
			s = "";
			while (d--) s += "74";//7474747
			s += '7';
			a -= count(all(s), '4');
			b -= count(all(s), '7');
			if (a < 0 || b < 0){
				cout << -1 << endl;
				continue;
			}
			s.erase(0, 1);
			cout << "7" + go(a, '4') + s + go(b, '7') << endl;
		}
	}
	return 0;
}
