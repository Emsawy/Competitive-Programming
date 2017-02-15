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
ll n, m, ar[4], one = 0, zero = 0;
ll getH(ll x){
	//if (x == 1) return 1;
	ll s = 0, e = 1e5, res = 0;
	while (s <= e){
		ll mid = (s + e) /2;
		if (suf(mid) >= x) res = mid + 1, e = mid - 1;
		else s = mid + 1;
	}
	return res;
}
ll getS(){
	if (zero == 0) return 0;
	ll s = 0, e = 1e7, res = 0;
	while (s <= e){
		ll mid = (s + e) / 2;
		if (mid * zero <= ar[2]) res = mid, s = mid + 1;
		else e = mid - 1;
	}
	return res;
}
bool valid(string s){
	ll a = count(all(s), '1');
	ll b = count(all(s), '0');
	if (a * (a - 1) / 2 != ar[0]) return  0;
	if (b * (b - 1) / 2 != ar[3]) return  0;
	ll bk10 = 0 , bk01 = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '0') ar[1] -= bk10;
		else bk10++;
		if (s[i] == '1') ar[2] -= bk01;
		else bk01++;
	}
	if (ar[1] == 0 && ar[2] == 0) return 1;
	return 0;
}
int main()
{
	Emsawy();
	while (cin >> ar[0] >> ar[1] >> ar[2] >> ar[3]){
		if ((ar[0] + ar[1] + ar[2] + ar[3]) == 0){
			puts("0");
			continue;
		}
		swap(ar[1], ar[2]);
		swap(ar[0], ar[3]);
		one = getH(ar[0]);
		zero = getH(ar[3]);
		if (one == 1 && ar[1] == 0 && ar[2] == 0) one = 0;
		if (zero == 1 && ar[1] == 0 && ar[2] == 0) zero = 0;
		int o = 0;
		string s = "";
		ll shift = getS();
		for (int i = 0; i < one - shift; i++) s += '1';
		for (int i = 0; i < zero; i++) s += '0';
		for (int i = 0; i < shift; i++) s += '1';
		ll rem = ar[2] - shift * zero , ok = 0 , cnt = 0;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '0') ok = 1;
			if (ok){
				rem--;
				if (rem == 0){
					s.insert(i + 1 , 1 , '1');
					ok++;
					break;
				}
			}
		}
		if (ok == 2) s.erase(0, 1);
		if (valid(s)) cout << s << endl;
		else cout << "Impossible\n";
	}
	return 0;
}
