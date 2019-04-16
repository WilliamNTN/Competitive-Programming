#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
int n;
string s;
int toOpen[maxN];
int toClose[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>s;

	int count = 0;
	bool flag = true;
	if(n%2 == 1) flag = false;

	int tO = 0, tC = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == ')')
			tC++;
		if(s[i] == '(')
			tO++;
		toClose[i] = tC;
		toOpen[i] = tO;
	}
	for(int i = 0; i < n; i++){
		if(s[i] == ')')
			count--;
		else if(s[i] =='(')
			count++;
		else{//?
			if(count >= (n-i)){
				s[i] = ')';
				count--;
			}
			else if(count  <= 1){
				s[i] = '(';
				count++;
			}
			else{
				int remain = n-i-1;
				tC = toClose[n-1] - toClose[i];
				tO = toOpen[n-1] - toOpen[i];
				int x = remain - (tC + tO);
				int remainDiff = tO - tC;

				if(x == 0){
					if(remainDiff >=0){
						s[i] = ')';
						count--;
					}else{//remain DIff < 0
						if(count > abs(remainDiff)){
							s[i] = ')';
							count--;
						}else{
							s[i] = '(';
							count++;
						}
					}

					continue;
				}
				x -= abs(remainDiff);
				if(x == 0){
					s[i] == ')';
					count--;
				}else{
					if(x < 0){
						s[i] = ')';
						count--;
					}else{
						if(x < count){
							s[i] = ')';
							count--;
						}
						else{// x >= count
							s[i] = '(';
							count++;
						}
					}
				}
			}
		}

		if(count < 0){
			flag = false;
		}
		if(count == 0 && i != (n-1))
			flag = false;
	}

	if(!flag || count != 0){
		cout<<":("<<endl;
	}
	else
		cout<<s<<endl;
	return 0;
}
