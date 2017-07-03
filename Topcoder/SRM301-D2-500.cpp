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

#define MP			make_pair
class IndicatorMotionReverse {
public:
	map<pair<char, char>, char> mp;
	string getMinProgram(vector <string> actions) {

		mp[MP('|', 'N')] = mp[MP('N', '-')] = mp[MP('-', '/')] = mp[MP('/', '|')] = 'L';
		mp[MP('N', '|')] = mp[MP('|', '/')] = mp[MP('/', '-')] = mp[MP('-', 'N')] = 'R';
		mp[MP('N', 'N')] = mp[MP('|', '|')] = mp[MP('/', '/')] = mp[MP('-', '-')] = 'S';
		mp[MP('|', '-')] = mp[MP('-', '|')] = mp[MP('/', 'N')] = mp[MP('N', '/')] = 'F';
		string all , v = ".";
		for (int i = 0; i < actions.size(); i++) all += actions[i];
		for (int i = 0; i + 1 < all.size(); i++){
			v.push_back(mp[MP(all[i], all[i + 1])]);
		}

		vector<string> ret ;
		char now = v[v.size() - 1];
		int cnt = 0;
		for (int i = v.size() - 1; i >= 0; i--){
			if (cnt < 99 && now == v[i])
				cnt++;
			else {
				char ch[55];
				string me = "";
				me += now;
				if (cnt < 10) me += '0';
				sprintf(ch, "%d", cnt);
				ret.push_back(me + ch);
				now = v[i];
				i++;
				cnt = 0;
			}
		}
		string res = "";
		for (int j = ret.size() - 1; j >= 0; j--){
			res += ret[j];
		}
		if (res.size() >= 100){
			res = res.substr(0, 97) + "...";
		}
		return res;
	}
};
