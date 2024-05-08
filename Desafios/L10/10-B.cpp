#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef double coord;
const double EPS = 1e-9;

struct point {
    coord x, y;

    point() : x(0), y(0) {}
    point(coord x, coord y) : x(x), y(y) {}

    double norm() { return sqrt(norm2()); }
    coord norm2() { return (*this) * (*this); }

    point operator+(const point& rhs) const { return point(x+rhs.x, y+rhs.y); }
    point operator-(const point& rhs) const { return point(x-rhs.x, y-rhs.y); }
    point operator*(const coord t) const { return point(x*t, y*t); }
    point operator/(const coord t) const { return point(x/t, y/t); }

    // produto escalar (dot product)
    coord operator*(const point& rhs) const { return x*rhs.x + y*rhs.y; }

    // produto vetorial (cross product)
    coord operator^(const point& rhs) const { return x*rhs.y - y*rhs.x; }

    // rotaciona 90 graus em sentido horario
    point perp() { return point(-y, x); }
    point rot(point rhs) { return point((*this)^rhs, (*this)*rhs); }
    point rot(double ang) { return rot(point(sin(ang), cos(ang))); }
};

ostream& operator<<(ostream& os, point p) {
    return os << "(" << p.x << "," << p.y << ")";
}

enum Side {
    LEFT,
    RIGHT,
    TOUCH
};

struct line {
    point v; // v = q-p
    coord c;

    line(point v, coord c) : v(v), c(c) {}
    line(coord a, coord b, coord c) : v({b,-a}), c(c) {}
    line(point p, point q) : v(q-p), c(v^p) {}

    // > 0: acima, < 0: abaixo, =0: colinear
    coord side(point p) { return (v^p)-c; }
    coord dist(point p) { return abs(side(p))/v.norm(); }
    coord dist2(point p) { return side(p)*side(p)/v.norm2(); }

    line perp(point p) { return line(p, p+v.perp()); }
    point proj(point p) { return p - v.perp()*side(p)/v.norm2(); }
};

// true se existe interseccao, e q eh a ponto de interseccao
bool inter(line l1, line l2, point &q){
    coord d = l1.v^l2.v;
    if(d == 0) return false;
    q = (l2.v*l1.c - l1.v*l2.c)/d;
    return true;
}

struct segment {
    point p,q;

    segment(point p, point q) : p(p), q(q) {};

    // > 0: acima, < 0: abaixo, =0: colinear
    coord side(point r) { return (r-p)^(q-p); }
    bool inDisk(point r){ return (p-r)*(q-r) < EPS; }
    bool contains(point r) { return abs(side(p)) < EPS and inDisk(r); }

    coord len() { return (q-p).norm(); }
    coord len2() { return (q-p).norm2(); }

    line getline() { return line(p,q); }
};

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    point p1(x1, y1);
    point p2(x2, y2);
    point p3(x3, y3);

    segment seg1(p1, p2);
    segment seg2(p2, p3);
    segment seg3(p3, p1);

    coord perimeter = seg1.len() + seg2.len() + seg3.len();

    line line1(p1, p2);
    line line2(p2, p3);
    line line3(p3, p1);

    point intersection1, intersection2, intersection3;
    inter(line1, line2, intersection1);
    inter(line2, line3, intersection2);
    inter(line3, line1, intersection3);

    coord area = 0.5 * abs((intersection1 - p1) ^ (intersection2 - p1));

    cout << perimeter << setprecision(4) << " ";
    cout << area << setprecision(4) << endl;

    return 0;
}
