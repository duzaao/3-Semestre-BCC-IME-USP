#include <iostream>
#include <cmath>
using namespace std;

typedef double coord;

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

Side getSideOfPoint(point p1, point p2, point p3) {
    point lineVector = p2 - p1;
    point pointVector = p3 - p1;

    coord crossProduct = lineVector ^ pointVector;

    if (crossProduct > 0) {
        return LEFT;
    } else if (crossProduct < 0) {
        return RIGHT;
    } else {
        return TOUCH;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        point p1(x1, y1);
        point p2(x2, y2);
        point p3(x3, y3);

        Side side = getSideOfPoint(p1, p2, p3);

        if (side == LEFT) {
            cout << "LEFT" << endl;
        } else if (side == RIGHT) {
            cout << "RIGHT" << endl;
        } else {
            cout << "TOUCH" << endl;
        }
    }

    return 0;
}
