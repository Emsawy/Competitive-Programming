/*
Just implement the solution;
ex: (A0 + A1) * (B0 - B1)
A0 * B0 + A0 + B1 + A1 * B0 + A1 * B1
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
const ll N = 1000;
int n, m, k, w;
struct Term{
	int px, py, factor;
	bool sign;
	Term(){}
	int Num(string &s, int st){
		string ret = "";
		while (st < s.size() && isdigit(s[st])){
			ret += s[st];
			st++;
		}	
		if (st <= s.size())
			s.erase(0, st);
		if (ret.size() == 0) return 1;
		return  stoi(ret);
	}
	Term(string s){
		if (s[0] != '+' && s[0] != '-') s.insert(0, 1, '+');
		if (s[0] == '+') sign = 1;
		else sign = 0;

		s.erase(s.begin());
		factor = Num(s, 0);
		px = py = 0;
		int loop = 2;
		while (loop--){
			if (s.size() && s[0] == 'x')
				px = Num(s, 1);
			if (s.size() && s[0] == 'y')
				py = Num(s, 1);
		}
	}
	bool operator<(const Term &l) const{
		if (px > l.px) return 1;
		else if (px == l.px && py < l.py) return 1;
		return 0;
	}
	bool Getsign(bool l, bool r) const {
		if (l == 0 && r == 0) return 1;
		if (l == 0 || r == 0) return 0;
		return 1;
	}
	Term operator * (const Term & l) const {
		Term ret;
		ret.factor = l.factor * factor;
		ret.px = l.px + px;
		ret.py = l.py + py;
		ret.sign = Getsign(l.sign , sign);
		return ret;
	}
};
void build(string &a, V<Term> &A){
	string tmp = "";
	for (int i = 0; i < a.size(); i++){
		if (a[i] == '-' || a[i] == '+'){
			if (tmp.size())
				A.push_back(Term(tmp));
			tmp = "";
		}
		tmp += a[i];
	}
	if (tmp.size())
		A.push_back(Term(tmp));
}

string itos(int x){
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	return s;
}
int main() {

	Emsawy();
	string a, b;
	while (cin>>a){
		if (a[0] == '#') break;

		cin >> b;
		V<Term> A, B, ans;
		build(a, A);
		build(b, B);
		map<pair<int, int>, int> mp;
		for (int i = 0; i < A.size(); i++){
			for (int j = 0; j < B.size(); j++){
				Term t = (A[i] * B[j]);
				mp[MP(t.px, t.py)] += (t.sign ? t.factor : -t.factor);
			}
		}
		for (auto it : mp){
			Term t;
			if (it.second == 0) continue;
			t.sign = (it.second > 0);
			t.factor = abs(it.second);
			t.px = it.first.first;
			t.py = it.first.second;
			ans.push_back(t);
		}
		sort(all(ans));

		string res, up;
		for (int i = 0; i < ans.size();i++){
			if (i == 0){
				if (ans[i].sign == 0) res += "-", up += ' ';
			}
			else 
				res += (ans[i].sign > 0 ? " + " : " - "), up += "   ";
			
			if (ans[i].factor > 1 || ans[i].px == 0 && ans[i].py == 0){
				string r = itos(ans[i].factor);
				res += r;
				up += string(r.size(), ' ');
			}
			if (ans[i].px > 0){
				res += "x";
				up += ' ';
				if (ans[i].px > 1){
					string r = itos(ans[i].px);
					res += string(r.size(),' ');
					up += r;
				}
			}
			if (ans[i].py > 0){
				res += "y";
				up += ' ';
				if (ans[i].py > 1){
					string r = itos(ans[i].py);
					res += string(r.size(), ' ');
					up += r;
				}
			}
		}
		cout << up << endl;
		if (res.size() == 0) cout << 0 << endl;
		else cout << res << endl;
	}
	return 0;
}
