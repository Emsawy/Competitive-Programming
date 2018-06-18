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
typedef long long ll;

class RockPaperScissorsMagicEasy {
public:

	ll mod = 1000000007;
	ll fact[2001];

	ll pw(ll b, ll p) {
		if (p == 0) return 1;
		if (p == 1) return b;
		ll ret = pw(b, p / 2);
		ret = (ret * ret) % mod;
		if (p % 2)
			ret = (ret * b) % mod;
		return ret;
	}

	ll Cnr(int n, int m) {
		return (fact[n] * pw( (fact[n - m] * fact[m]) % mod , mod - 2)) % mod;
	}

	int count(vector <int> card, int score) {
		if (card.size() < score) return 0;
		fact[0] = fact[1] = 1;
		for (int i = 2; i < 2001; i++)
			fact[i] = (fact[i - 1] * 1LL * i) % mod;

		return (Cnr(card.size(), score) * pw(2, card.size() - score)) % mod;
	}
};

/*
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


class RockPaperScissorsMagicEasy {
public:
	vector<int> _card;
	int _score;

	int mod = 1000000007;

	int dp[2001][2001];
	int go(int nd, int score) {
		if (nd >= _card.size()) {
			return _score == score;
		}
		int &ret = dp[nd][score];
		if (ret != -1) return ret;
		ret = 0;
		ret = (ret + go(nd + 1, score + 1)) % mod;
		ret = (ret + go(nd + 1, score)) % mod;
		ret = (ret + go(nd + 1, score)) % mod;
		return ret;
	}

	int count(vector <int> card, int score) {
		_card = card;
		_score = score;
		for (int i = 0; i < 2001; i++)
			for (int j = 0; j < 2001; j++)
				dp[i][j] = -1;

		return go(0, 0);
	}
};
*/
