#include <iostream>
#include "main.h"

using namespace std;

int main()
{
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


    return 0;
}

