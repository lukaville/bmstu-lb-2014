#include <iostream>
#include "coblist.h"
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

    cout << endl;

    Deriv1* pd1 = &d1;
    Deriv2* pd2 = &d2;
    Deriv3* pd3 = &d3;

    pd1->print();
    pd2->print();
    pd3->print();

    cout << endl;

    pAbs = pd1;
    pAbs->print();

    pAbs = pd2;
    pAbs->print();

    pAbs = pd3;
    pAbs->print();

    cout << endl;

    CObList ListDer;
    for(int i = 0; i < 2; ++i) {
        ListDer.AddTail(new Deriv1(i));
    }

    for(int i = 0; i < 2; ++i) {
        ListDer.AddTail(new Deriv2(i));
    }

    for(int i = 0; i < 2; ++i) {
        ListDer.AddTail(new Deriv3(i));
    }

    for(POSITION pos = ListDer.GetHeadPosition(); pos != NULL;) {
        ((Abstr*) ListDer.GetNext(pos))->print();
        cout << endl;
    }

    return 0;
}
