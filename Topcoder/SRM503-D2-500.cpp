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


class ToastXToast {
public:
	int bake(vector <int> undertoasted, vector <int> overtoasted) {
		sort(undertoasted.begin(), undertoasted.end());
		sort(overtoasted.begin(), overtoasted.end());
		if (overtoasted[0] < undertoasted[0]) return -1;
		if (undertoasted.back() > overtoasted.back()) return -1;
		int mn = overtoasted[0];
		int mx = undertoasted.back();

		if (mn <= mx) return 2;

		for (int i = 0; i < undertoasted.size(); i++)
			if (mn < undertoasted[i] && undertoasted[i] < mx)
				return 2;


		for (int i = 0; i < overtoasted.size(); i++)
			if (mn < overtoasted[i] && overtoasted[i] < mx)
				return 2;
		return 1;
	}
};
