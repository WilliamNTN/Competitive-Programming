#include <bits/stdc++.h>
#include <vector>
#include <math.h>

using namespace std;

int n, m;
long long int value;

int main(){
    long long int aux;
    long long int finalv = -1;
    vector<int> v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%lld", &aux);
        v.push_back(aux);
    }

    int j = m;
    while(j != 0){
        scanf("%lld", &value);
        vector<int>::iterator lower, upper;

        lower = std::lower_bound(v.begin(), v.end(), value);
        upper = std::upper_bound(v.begin(), v.end(), value);
        aux = value;
        if (aux > 0){
            while (*lower != aux){
                if (lower == upper){
                    aux--;
                }
                lower = std::lower_bound (v.begin(), v.end(), aux);
                upper = std::upper_bound (v.begin(), v.end(), aux);

            }
        }

        // cout << abs(value - *lower) << " " << abs(value - *upper) << endl;
        if (abs(value - *lower) <= abs(value - *upper)){
            printf("%d\n", *lower);
        }else{
            printf("%d\n", *upper);
        }
        j--;
    }

}