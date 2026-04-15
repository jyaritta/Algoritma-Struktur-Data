#include <iostream>
#include <string>
#include "circle.h"
#include "point.h" 

using namespace std;

int main() {
    Circle c;
    Point p;

    cin >> c.centre.x >> c.centre.y >> c.radius >> p.x >> p.y;

    double d = distance(&c, &p);
    double selisih = d - c.radius;
    string status = CheckPointInCircle(selisih);
    cout << status << endl;
    return 0;
}