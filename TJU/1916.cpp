#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

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
struct point{
	ll x, y;
};
int side(point a, point b, point c){
	int x1 = b.x - a.x, y1 = b.y - a.y;
	int x2 = c.x - a.x, y2 = c.y - a.y;
	int p = y2 *x1 - x2 * y1;
	if (p == 0) return 0;
	else if (p > 0) return 1;
	else return -1;
}

ll dis(point a, point b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
	//Emsawy();

	point p, t;
	double r;
	while (cin >> p.x >> p.y >> r){
		if (r < 0) break;
		cin >> n;
		V<point>in;
		for (int i = 0; i < n; i++){
			cin >> t.x >> t.y;
			if (dis(p, t) <= r * r)
				in.push_back(t);
		}
		int ans = 0;
		for (int i = 0; i < in.size(); i++){
			int up = 0, down = 0;
			for (int j = 0; j < in.size(); j++){
				ll ret = side(p, in[j], in[i]);
				if (ret == 0) up++, down++;
				else if (ret < 0) up++;
				else down++;
			}
			ans = max(ans, max(up, down));
		}
		cout << ans << endl;
	}
	return 0;
}
