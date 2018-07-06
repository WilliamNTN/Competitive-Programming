
//fdpxs - gn = 0
//abracate - abacates = 7
//pxeecxeaxxdb - bcad = 3
//pxeecxxa - ac = 1

#include <bits/stdc++.h>
using namespace std;

string a,b;

int max(int x, int y){
	return x > y ? x : y;
}

int solve(string &X, string &Y){
     
    int m = X.length(), n = Y.length();
 
    int mat[2][n + 1];
 
    bool bi;
 
    for (int i = 0; i <= m; i++)    {
        bi = i & 1;
 
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0)
                mat[bi][j] = 0;
 
            else if (X[i-1] == Y[j-1])
                 mat[bi][j] = mat[1 - bi][j - 1] + 1;
 
            else
                mat[bi][j] = max(mat[1 - bi][j],mat[bi][j - 1]);
        }
    }

    return mat[bi][n];
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b;

	cout<<solve(a,b)<<endl;
	}
