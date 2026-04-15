#include <iostream>
#include <string>

// INI KUNCINYA! Panggil .h nya, bukan .cpp nya
#include "line.h"  
#include "point.h" 

using namespace std;

int main() {
    Line l1;
    Point p1;

    cin >> l1.a >> l1.b >> l1.c >> p1.x >> p1.y;

    double hasil_evaluasi = gradient(&l1, &p1);
    string status = CheckPointPosition(hasil_evaluasi);

    cout << status << endl;

    return 0;
}