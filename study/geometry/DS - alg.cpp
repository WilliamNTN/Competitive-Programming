#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-7


////////// STRUCTS////////////////
struct point_i{int x,y;};

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

struct line{
	double a,b,c;

	line(){}

	line(double _a, double _b, double _c){
		a = _a;
		b = _b;
		c = _c;
	}

	bool operator == (line other){
		return (fabs(a-other.a) < EPS) && (fabs(b-other.b) < EPS) && (fabs(c-other.c) < EPS);
	}

};

struct vec{
	double x,y;
	vec(){}

	vec(double _x, double _y){
		x = _x; y = _y;
	}
};

/////// POINTS ////////////////
double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

//////////// LINES ///////////////
line* pointsToLine(point p1, point p2){
	line *l;

	if(p1.x == p2.x){
		l->a = 1.0;
		l->b = 0.0;
		l->c = -p1.x;
	}
	else{
		l->a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
		l->b = 1.0;
		l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
	}



	return l;
}

bool areParallel(line l1, line l2){
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areIntersect(line l1,line l2, point *p){
	if(l1 == l2) return false;
	if(areParallel(l1,l2)) return false;

	p->x = (double)(l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if(fabs(l1.b) > EPS)
		p->y = -(l1.a * p->x + l1.c)/l1.b;
	else
		p->y = -(l2.a && p->x + l2.c) / l2.b;
	return true;
}

///////// VECTORS //////////////////
vec toVector(point p1, point p2){
	return vec(p2.x-p1.x,p2.y-p1.y);
}

vec scaleVector(vec v, double s){
	return vec(v.x * s, v.y * s);
}

point translate(point p, vec v){
	return point(p.x + v.x, p.y + v.y);
}


///////////// CIRCLE ///////////////////

bool isInCircle(point p, point c, double r){
	return dist(p,c) <= r;
}

double circleCirc(point c, double r){
	return (4*acos(0.0) * r);
}

double circleArea(double r){
	return (2*acos(0.0)*r*r);
}

//////////// POLYGON /////////////////

double perimeter(vector<point> P){

	double r = 0.0;
	for(int i = 0; i<P.size()-1; i++){
		r += dist(P[i],P[i+1]);
	}
	r += dist(P[P.size()-1],P[0]);

	return r;
}

double area(vector<point> P){
	double r = 0.0,x1,y1,x2,y2;

	for(int i = 0; i<P.size();i++){
		x1 = P[i].x;
		x2 = P[(i+1)%P.size()].x;

		y1 = P[i].y;
		y2 = P[(i+1)%P.size()].y;

		r += (x1 * y2 - x2 * y1);
	}

	return fabs(results)/2.0;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	return 0;
}