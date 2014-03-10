#include <iostream>
#include "main.h"
#include "rectangle.h"
#include "rectangle1.h"
#include "square.h"

using namespace std;

int main()
{
    q = -32;


    // Default arguments in prototype
    cout << maximum(1, 2, 3) << endl;
    cout << maximum(1, 2) << endl;
    cout << maximum(1) << endl;
    cout << maximum() << endl;

    // Default arguments with overload
    cout << maximum1(1, 2, 3) << endl;
    cout << maximum1(1, 2) << endl;
    cout << maximum1(1) << endl;
    cout << maximum1() << endl;

    // Defualt arguments priority
    // cout << test() << endl;

    // Overloading functions with different argument types
    cout << multiply('a', 'b', 'c') << endl;
    cout << multiply(1, 2, 3) << endl;
    cout << multiply(1.2, 1.3, 1.4) << endl;

    // Overloading functions with different argument types and argument numbers
    cout << multiply('a', 'b') << endl;
    cout << multiply(1, 2) << endl;
    cout << multiply(1.2, 1.3) << endl;

    // multiply(1.1, 2.1);

    // Overloading operators ++, -- demo
    Rectangle r1;
    cin >> r1;
    r1++;
    cout << r1;
    r1--; --r1;
    cout << r1 << endl;

    // Overloading operators + and - demo
    Rectangle rp, rq, rr;
    rp++; rq--;
    rr = rp + rq;
    rp = rp - rq;

    cout << rr << rp;

    // Rectangle 1
    Rectangle1 t1, t2, t3;
    t1++; t1++; t2--; t2--;
    t3 = t1 * t2;
    t3 = t3 - t1;
    cout << t3;

    // Square inheritance
    Square c1;
    cout << c1;

    c1++;

    cout << c1;

    return 0;
}

