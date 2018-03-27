#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
#define all(v)	     ((v).begin()), ((v).end())
#define clr(v,d)     memset(v, d, sizeof(v))
#define V	         vector

const ll N = (1 << 18);
ll n, m, k, w;

char s[20][20], org[20][20], tmp[20][20];

bool isSame(){
	for(int i= 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(s[i][j] != org[i][j])
				return 0;
		}
	}
	return 1;
}
void rotate(){
	for(int i= 0;i<n;i++){
		for(int j = 0;j<n;j++){
			tmp[i][n - j - 1] = org[j][i];
		}
	}
	for(int i= 0;i<n;i++)
		for(int j= 0;j<n;j++)
			org[i][j] = tmp[i][j];
}
void reflect(){
	for(int i = 0;i<n/2;i++){
		for(int j = 0;j<n;j++){
			swap(org[i][j], org[n-i-1][j]);
		}
	}
}
void printWas(int angle){
	if(angle == 1) cout<<"was rotated 90 degrees."<<endl;
	else if(angle == 2) cout<<"was rotated 180 degrees."<<endl;
	else cout<<"was rotated 270 degrees."<<endl;
}
void printNOtWas(int angle){
	if(angle == 1) cout<<"rotated 90 degrees."<<endl;
	else if(angle == 2) cout<<"rotated 180 degrees."<<endl;
	else cout<<"rotated 270 degrees."<<endl;
}
int main() {

	Emsawy();
	int id = 0;
	while (cin >> n) {
		for(int i = 0;i<n;i++){
			for(int j= 0;j<n*2;j++){
				if(j < n)
					cin>>org[i][j];
				else
					cin>>s[i][(j%n)];
			}
		}
		/*for(int i =0;i<n;i++){
			for(int j = 0;j<n;j++)
				cerr<<org[i][j];
			cerr<<endl;
		}
		for(int i =0;i<n;i++){
				for(int j = 0;j<n;j++)
					cerr<<s[i][j];
				cerr<<endl;
			}
			*/
		cout<<"Pattern "<<++id<<" ";
		if(isSame()) cout<<"was preserved."<<endl;
		else{
			int angle = 0;
			while(angle < 4 && !isSame()){
				rotate();
				angle++;
			}
			if (isSame())
				printWas(angle);
			else {
				reflect();
				if (isSame()) {
					cout << "was reflected vertically."<<endl;
				}
				else {
					angle = 0;
					while (angle < 4 && !isSame()) {
						rotate();
						angle++;
					}
					if (isSame()) {
						cout << "was reflected vertically and ";
						printNOtWas(angle);
					} else
						cout << "was improperly transformed." << endl;
				}

			}
		}
	}

	return 0;
}
