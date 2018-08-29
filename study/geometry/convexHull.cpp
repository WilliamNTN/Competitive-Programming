#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define EPS 1e-7


struct point{
	double x,y;
	
	point(){}

	point(double _x, double _y){
		x = _x; y = _y;
	}

	bool operator < (point other){

		if(fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}

	bool operator <= (point other){
		if(fabs(x - other.x) > EPS)
			return x <= other.x;
		return y <= other.y;
	}

	bool operator == (point other){
		return (fabs(x - other.x) < EPS && fabs(y-other.y) < EPS);
	}
};

int n;
vector<point> p,hull;
double ans;

bool isCCW(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void setConvexHull(vector <point> p, vector <point> &h) {
    sort(p.begin(), p.end(), cmp);
    p.erase(unique(p.begin(), p.end(), eq), p.end());

    vector <point> up, down;
    point head = p[0], tail = p.back();

    up.push_back(head); down.push_back(head);

    for (int i = 1; i < (int) p.size(); i++) {
        if (i == (int) p.size() - 1 || !isCCW(tail, head, p[i])) {
            while ( (int) up.size() >= 2 && isCCW(up[up.size() - 2], up.back(), p[i]) )
                up.pop_back();
            up.push_back(p[i]);
        }
        if (i == (int) p.size() - 1 || isCCW(tail, head, p[i])) {
            while ( (int) down.size() >= 2 && !isCCW(down[down.size() - 2], down.back(), p[i]) )
                down.pop_back();
            down.push_back(p[i]);
        }
    }

    h.clear();
    for (int i = 0; i < (int) up.size(); i++)
        h.push_back(up[i]);
    for (int i = (int) down.size() - 2; i > 0; i--)
        h.push_back(down[i]);

}

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double getPerimeter(vector <point> p) {
    double per = 0;

    for (int i = 1; i < (int) p.size(); i++)
        per += dist(p[i - 1], p[i]);
    per += dist(p.back(), p[0]);

    return per;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	return 0;
}