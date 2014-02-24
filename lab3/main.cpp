#include <iostream>
#include "color.h"
#include "point.h"
#include "triangle.h"

#define STUDENT_ID 23

using namespace std;

int main()
{
    // Constructors demonstration
    Triangle t1;
    Triangle t2(Point(0, 0), Point(1, 2), Point(3, 4));
    Triangle t3(Point(0, 0), Point(1, 2), Point(3, 4), Color(255, 124, 23));

    // Printing objects
    cout << t1 << t2 << t3;

    // Methods calling demonstation
    t1.getColor();
    t1.getP1();
    t1.getP2();
    t1.getP3();
    t1.setColor(Color(1,2,3));
    t1.setP1(Point(1,3));
    t1.setP2(Point(1,2));
    t1.setP3(Point(3,2));

    cout << "Result:\n" << t1;

    // Pointer to object
    Triangle *pt = new Triangle(Point(0, 0), Point(1, 2), Point(3, 4));
    cout << *pt;

    // Delete object
    delete pt;

    // Objects array
    Triangle arr[30];

    // Methods calling demonstation for array object
    arr[STUDENT_ID] = Triangle(Point(0, 0), Point(1, 2), Point(3, 4));
    arr[STUDENT_ID].getColor();
    arr[STUDENT_ID].getP1();
    arr[STUDENT_ID].getP2();
    arr[STUDENT_ID].getP3();
    arr[STUDENT_ID].setColor(Color(1,2,3));
    arr[STUDENT_ID].setP1(Point(1,3));
    arr[STUDENT_ID].setP2(Point(1,2));

    cout << arr[STUDENT_ID];

    // t1.p1;
    // 'Point Triangle::p1' is private

    cout << "\n\nСтатическая переменная Triangle::count = "  << Triangle::count << endl;

    return 0;
}

