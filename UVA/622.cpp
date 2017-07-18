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

int n, m, k, t, c;
/*
< Expressionression > := < Component > | < Component > + < Expressionression >
< Component > := < f actor > | < f actor > * < Component >
< f actor > := < positiveinteger > | (< Expressionression >)

*/
char s[1 << 20];
int p = 0, ok = 0;

int expression();
int component();
int factor();

int expression()
{
	if (ok) return 0;

	int l = component();
	if (p < n && s[p] == '+'){
		p++;
		return l + expression();
	}
	return l;
}

int component()
{

	if (ok) return 0;

	int l = factor();
	if (p < n && s[p] == '*'){
		p++;
		return l * component();
	}
	return l;
}

int factor()
{

	if (ok) return 0;

	if (p >= n) return ok = 1;
	if (s[p] == '('){
		p++;
		int l = expression();
		if (s[p] != ')') return ok = 1;
		p++;
		return l;
	}
	else if (isdigit(s[p])){
		int ret = 0;
		while (isdigit(s[p])){
			ret = ret * 10 + s[p] - '0';
			p++;
		}
		return ret;
	}
	return (ok = 1);
}
int main()
{
	Emsawy();
	int T;
	cin >> t;
	while (t--){
		cin >> s;
		ok = p = 0;
		n = strlen(s);

		int ans = expression();

		if (p < n)
			ok = 1;

		if (ok) cout << "ERROR\n";
		else cout << ans << endl;
	}
	return 0;
}
