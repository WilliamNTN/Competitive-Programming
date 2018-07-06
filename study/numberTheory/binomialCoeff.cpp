#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL  binomialCoeff(LL n, LL k){
    LL res = 1;
 
    if (k > n - k)
        k = n - k;
 
    for (LL i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
LL n,k;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>n>>k;

    cout<<binomialCoeff(n,k)<<endl;

    return 0;
}


