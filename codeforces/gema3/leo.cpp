// #include <bits/stdc++>;
#include <iostream>
#include <vector>
using namespace std;

struct point {
    int x;
    int y;
};

int n, m, xi, yi;
char mat[1000][1000]; // n x m
int R = 1, L = 1, D = 1, U = 1;
int qtSeen = 0;

int main(){
    qtSeen = 0;
    vector<point> w_points;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '.') {
                point p;
                p.x = i;
                p.y = j;
                w_points.push_back(p);
            }
        }
    }

    for (vector<point>::iterator it = w_points.begin(); it != w_points.end(); ++it) {
        // andar em todas as direções
        // it->x it->y -> pontos
        xi = 0;
        while(xi < it->x){
            if(mat[xi][it->y] == 'D'){
                D = 0;
            }
            if(mat[xi][it->y] == '#'){
                D = 1;
            }
            xi++;
        }

        xi = n;
        while(xi > it->x){
            if(mat[xi][it->y] == 'U'){
                U = 0;
            }
            if(mat[xi][it->y] == '#'){
                U = 1;
            }
            xi--;
        }

        yi = 0;
        while(yi < it->y){
            if(mat[it->x][yi] == 'R'){
                R = 0;
            }
            if(mat[it->x][yi] == '#'){
                R = 1;
            }
            yi++;
        }

        yi=m;
        while(yi > it->y){
            if(mat[it->x][yi] == 'L'){
                L = 0;
            }
            if(mat[it->x][yi] == '#'){
                L = 1;
            }
            yi--;
        }

        if(R && L && U && D) qtSeen+=1;

        if(qtSeen == 2) break;
    }

    if (qtSeen == 0)
    {
        printf("NO SOLUTION\n");
    }else if(qtSeen == 1){
        printf("ONLY ONE SOLUTION\n");
    }else{
        printf("MULTIPLE SOLUTIONS\n");
    }

    return 0;
}