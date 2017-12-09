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

struct Node{
	int a, b;
	Node(){}
	Node(int a, int b) :a(a), b(b){}
	bool operator==(Node x){
		return x.a == a && x.b == b;
	}
};

map<string, V<Node> > adj;
map<string, int>mp;
int n, m, k, c;
const int N = 10000 + 4;
bool valid(){
	
	V<pair<pair<int, pair<int, int> >,string> > standing;
	for (auto it : adj){
		pair<pair<int, pair<int, int> >, string> p;
		for (int j = 0; j < it.second.size(); j++){
			if (it.second[j].a == it.second[j].b){
				p.first.first++;
			}
			else if (it.second[j].a > it.second[j].b){
				p.first.first += 3;
			}
			p.first.second.second += it.second[j].a;
			p.first.second.first += it.second[j].a - it.second[j].b;
		}
		p.second = it.first;
		p.first.first *= -1;
		p.first.second.first *= -1;
		p.first.second.second *= -1;
		standing.push_back(p);
	}
	sort(all(standing));
	if (standing[0].second == "BERLAND") return 1;
	if (standing[1].second == "BERLAND") return 1;
	return 0;

}
int main()
{
	Emsawy();
	char ch;
	string sa, sb;
	int a, b;
	for (int i = 0; i < 5; i++){
		cin >> sa >> sb >> a >> ch >> b;
		adj[sa].push_back(Node(a, b));
		adj[sb].push_back(Node(b, a));
		if (a == b){
			mp[sa] ++;
			mp[sb]++;
		}
		else {
			mp[sa] += (a > b ? 3 : 0);
			mp[sb] += (b > a ? 3 : 0);
		}
	}
	string team1, team2;
	for (auto it : adj){
		if (it.second.size() == 2){
			if (team1 == "")
				team1 = it.first;
			else
				team2 = it.first;
		}
	}
	if (team2 == "BERLAND")
		swap(team1, team2);
	pair<int, int> ans = MP(oo,oo);
	for (int i = 1; i < 50; i++){
		for (int j = 0; j < i; j++){
			int x = i, y = j;
			adj[team1].push_back(Node(x, y));
			adj[team2].push_back(Node(y, x));
			if (valid()){
				ans = min(ans, MP(x - y, y));
			}
			adj[team1].erase(find(all(adj[team1]),Node(x, y)));
			adj[team2].erase(find(all(adj[team2]), Node(y, x)));
		}
	}
	if (ans.first == oo) cout << "IMPOSSIBLE" << endl;
	else cout << ans.first + ans.second << ":" << ans.second << endl;
	return 0;
}
