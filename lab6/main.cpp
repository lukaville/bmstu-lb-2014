#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    Abstr *pAbs;
    Deriv1 d1(11);
    Deriv2 d2(22);
    Deriv3 d3(33);

    cout << endl;

    d1.print();
    d2.print();
    d3.print();

    return 0;
}
